#!/usr/bin/python3.5
"""
NRF5 identification tool based on 
- their .hex signature
- or strings contained in their .bin version
"""
import hashlib
import sqlite3
import subprocess
import sys

class NRF5xIdentify(object):
    """
    Identification class
    Given a hex file returns associated SDK, SoftDevice versions, RAM and ROM binary addresses
    """
    def __init__(self, hexfile, cur):
        self.hexfile = hexfile
        self.cur = cur
        self.sdk_version = None
        self.sdv_version = None
        self.sign = None
        self.bin = None
        self.nrf = None
        self.sdvs = []

    def signature(self):
        """
        returns softdevice signature
        The signature is the sha256 hash of specific bytes of its .hex file
        """
        with open(self.hexfile, 'rb+') as sdv_hex:
            sdv_hex.seek(10000)
            extract = sdv_hex.read(40000)
            self.sign = hashlib.sha256(extract).hexdigest()
        print("Computing signature\nHex file:", self.hexfile)
        print("Signature: ", self.sign)

    def identify(self):
        """
        select SDKversion, SoftDeviceVersion where signature = self.sign
        """
        req = "select sdk_version from SoftDevice where sign LIKE ?"
        self.cur.execute(req, (self.sign, ))
        res = self.cur.fetchone()
        # CASE 1 : signature of the hex file is not in database
        if res is None:
            print("                               ==================")
            print("hex not identified in nRF5x database ====> Computing approximate signature from strings in binary")
            print("                               ==================")
            self.binary()
            print("Hex file    : ", self.hexfile)
            print("Binary file : ", self.bin)
            cmd = "strings " + self.bin + " | grep Nordic\ Semiconductor/ | cut -d '/' -f 3,5"
            cmd += "| sed -e s/'\/'/'_'/g | cut -d ' ' -f 2 | sed -e s/'SDK_'/''/g | "
            cmd += "sed -e s/'.0_'/'_'/g | sort -u"
            nrf_sign = subprocess.getoutput(cmd)
            print("nrf sign", nrf_sign)
            print("                               ==================")
            if "_" in nrf_sign:
                self.sdk_version = nrf_sign.split("_")[0]
                self.nrf = nrf_sign.split("_")[1]
                self.sign = "%" + nrf_sign + "%"
                print("SDK version: ", self.sdk_version)
                print("NRF type: ", self.nrf)
                print("Approximative signature: ", self.sign)
                req = "select softdevice_v from SoftDevice where sign LIKE ? and nrf=?"
                self.cur.execute(req, (self.sign, self.nrf))
                res = self.cur.fetchall()
                for sdv in res:
                    self.sdv_version = sdv[0]
                    print("SoftDevice version: ", self.sdv_version)
                print("                               ==================")
        # CASE 2 : signature of the hex file is in database
        else:
            self.sdk_version = res[0]
            self.sdv_version = res[1]
            print("                               ==================")
            print("SDK version: ", self.sdk_version)
            print("SoftDevice version: ", self.sdv_version)
        with open("nRF_ver", "w") as nrf_version:
            nrf_version.write(self.sign)
            print("nRF5x signature written to file nRF_ver in current directory")
            print("nRF_ver path must be provided when running nrfreverse.py")

    def binary(self):
        """
        returns the binary format given the hex file
        $objcopy -I ihex -O binary netwyse_ble_app.hex
        """
        self.bin = self.hexfile.replace(".hex", ".bin")
        cmd = "objcopy -I ihex -O binary " + self.hexfile + " " + self.bin
        subprocess.run(cmd, shell=True, check=True)
        print("Dumping binary from hex file to directory: ", self.bin)

    def map_binary(self):
        """
        maps the binary at the right memory addresses
        """
        req = "select softdev_v, nrf, card_version, ram_origin, ram_length, rom_origin, rom_length from MemoryAddr where softdev_signature LIKE ? and nrf=? "
        self.cur.execute(req, (self.sign, self.nrf))
        for res in self.cur.fetchall():
            mem_props(res)
def mem_props(res):
    if res is not None:
        sdv = res[0]
        nrf = res[1]
        card_v = res[2]
        ram_addr = res[3]
        ram_length = res[4]
        rom_addr = res[5]
        rom_length = res[6]
        print("\n", " "*35, "*****")
        print(" "*33, "Binary mapping")
        print(" "*36, "*****\n")
        print("NRF          : ", nrf)
        print("SoftDevice   : ", sdv)
        print("Card version : ", card_v)
        print(" "*10, "*****")
        print("RAM address  : ", ram_addr)
        print("RAM length   : ", ram_length)
        print("ROM address  : ", rom_addr)
        print("ROM length   : ", rom_length)

def launch_print():
    """print message"""
    print("############################ nRF5-tool ############################ ")
    print("#####                                                         ##### ")
    print("#####                Identifying nRF5x firmwares              ##### ")
    print("#####                                                         ##### ")
    print("################################################################### ")
    print("\n")

def bin_to_hex(binary):
    """
    returns the hex format given the bin file
    $objcopy -I binary -O ihex binary
    """
    hexfile = binary.replace(".bin", ".hex")
    cmd = "objcopy -O ihex -I binary " + binary + " " + hexfile
    subprocess.run(cmd, shell=True, check=True)
    print("Dumping hex", hexfile, "from binary file ", binary)
    return hexfile

def main():
    """
    main
    """
    launch_print()
    if len(sys.argv) == 2 and ('.hex' in sys.argv[1] or '.bin' in sys.argv[1]):
        con = sqlite3.connect("./nRF.db")
        cur = con.cursor()
        if ".hex" in sys.argv[1]:
            print("hex file")
            hexfile = sys.argv[1]
        elif ".bin" in sys.argv[1]:
            print("Binary file provided ", sys.argv[1])
            hexfile = bin_to_hex(sys.argv[1])
        nrf = NRF5xIdentify(hexfile, cur)
        nrf.signature()
        nrf.identify()
        nrf.map_binary()
        con.close()

if __name__ == "__main__":
    main()
