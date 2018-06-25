#!/usr/bin/env python3.5

"""
NRF5 identification tool based on
- their .hex signature
- or strings contained in their .bin version
"""
import hashlib
import sqlite3
import subprocess
import sys
import os
import argparse
import time
from tqdm import tqdm

class NRF5xIdentify(object):
    """
    Identification class
    Given a firmware, computes its signature and looks for it in the database
    returns the SDK version used, the possible SoftDevice versions and associated RAM and ROM binary addresses
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
        Returns softdevice signature
        The signature is the sha256 hash of specific bytes of its .hex file
        """
        print("\nComputing signature from hex")
        for i in tqdm(range(1)):
            time.sleep(0.05)
        with open(self.hexfile, 'rb+') as sdv_hex:
            sdv_hex.seek(10000)
            extract = sdv_hex.read(40000)
            self.sign = hashlib.sha256(extract).hexdigest()
        print("Signature: ", self.sign)

    def identify(self):
        """
        Identifies the firmware from its signature in the database
        """
        print("Searching for signature in nRF.db")
        for i in tqdm(range(1)):
            time.sleep(0.05)
        req = "select sdk_version, nrf, softdevice_v from SoftDevice where sign LIKE ?"
        self.cur.execute(req, (self.sign, ))
        res = self.cur.fetchone()
        # CASE 1 : signature of the hex file is not in database
        if res is None:
            print("Signature not found in nRF5x database")
            print("\nComputing approximate signature from strings in binary")
            self.binary()
            cmd = "strings " + self.bin + " | grep Nordic\ Semiconductor/ | cut -d '/' -f 3,5"
            cmd += "| sed -e s/'\/'/'_'/g | cut -d ' ' -f 2 | sed -e s/'SDK_'/''/g | "
            cmd += "sed -e s/'.0_'/'_'/g | sort -u"
            nrf_sign = subprocess.getoutput(cmd)
            for i in tqdm(range(1)):
                time.sleep(0.05)
            if "_" in nrf_sign:
                self.sdk_version = nrf_sign.split("_")[0]
                self.nrf = nrf_sign.split("_")[1]
                self.sign = "%" + nrf_sign + "%"
                print("Identified the following strings in binary", nrf_sign)
                print("\nSDK version: ", self.sdk_version)
                print("NRF type: ", self.nrf)
                req = "select softdevice_v from SoftDevice where sign LIKE ? and nrf=? and sdk_version=?"
                self.cur.execute(req, (self.sign, self.nrf, self.sdk_version))
                res = self.cur.fetchall()
                for sdv in res:
                    self.sdv_version = sdv[0]
                    print("Possible SoftDevice version: ", self.sdv_version)
                print("                               ==================")
        # CASE 2 : signature of the hex file is in database
        else:
            self.sdk_version = res[0]
            self.nrf = res[1]
            self.sdv_version = res[2]
            print("                               ==================")
            print("SDK version: ", self.sdk_version)
        with open("nRF_ver", "w") as nrf_version:
            nrf_version.write(self.sign)
            print("nRF5x signature written to file nRF_ver in current directory")
            print("nRF_ver path must be provided when running nrfreverse.py from IDA")

    def binary(self):
        """
        Returns the binary format given the hex file
        $objcopy -I ihex -O binary ./path_to_formware.hex
        """
        self.bin = self.hexfile.replace(".hex", ".bin")
        cmd = "objcopy -I ihex -O binary " + self.hexfile + " " + self.bin
        subprocess.run(cmd, shell=True, check=True)

    def map_binary(self):
        """
        Maps the binary at the right memory addresses
        """
        req = "select softdev_v, nrf, card_version, ram_origin, ram_length, rom_origin, rom_length from MemoryAddr where softdev_signature LIKE ?"
        self.cur.execute(req, (self.sign, ))
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
        print("SoftDevice   : ", sdv)
        print("NRF          : ", nrf)
        print("Card version : ", card_v)
        print(" "*10, "*****")
        print("RAM address  : ", ram_addr)
        print("RAM length   : ", ram_length)
        print("ROM address  : ", rom_addr)
        print("ROM length   : ", rom_length)

def bin_to_hex(binary):
    """
    returns the hex format given the bin file
    $objcopy -I binary -O ihex binary
    """
    hexfile = binary.replace(".bin", ".hex")
    cmd = "objcopy -O ihex -I binary " + binary + " " + hexfile
    subprocess.run(cmd, shell=True, check=True)
    print("Converting file object format from bin to hex")
    for i in tqdm(range(1)):
        time.sleep(0.05)
    print("Hex file successfully dumped on disk: {0}".format(hexfile))
    return hexfile

def helper():
    """
    Arguments parser
    """
    print("############################ nRF5-tool ############################ ")
    print("#####                                                         ##### ")
    print("#####                Identifying nRF5x firmwares              ##### ")
    print("#####                                                         ##### ")
    print("################################################################### ")
    print("\n")

def is_valid_file(parser, arg):
    """
    Checks if the input file is valid
    """
    if not os.path.exists(arg):
        parser.error("The file %s does not exist!" % arg)

def main():
    """
    main
    """
    helper()
    parser = argparse.ArgumentParser("nrfident.py")
    parser.add_argument("format", choices=['bin', 'hex'], help="the object format bfdname")
    parser.add_argument("firmware", help="input file to identify", metavar="FILE",
                        type=lambda x: is_valid_file(parser, x))
    args = parser.parse_args()
    con = sqlite3.connect("./nRF.db")
    cur = con.cursor()
    if args.format == 'hex':
        hexfile = sys.argv[2]
        print("Hex file provided {0}".format(hexfile))
    elif args.format == 'bin':
        binfile = sys.argv[2]
        print("Binary file provided {0}".format(binfile))
        hexfile = bin_to_hex(binfile)
    nrf = NRF5xIdentify(hexfile, cur)
    nrf.signature()
    nrf.identify()
    nrf.map_binary()
    con.close()

if __name__ == "__main__":
    main()
