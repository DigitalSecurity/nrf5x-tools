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
from intelhex import IntelHex
from intelhex import bin2hex
from tqdm import tqdm

class NRF5xIdentify(object):
    """
    Identification class
    Given a firmware, computes its signature and looks for it in the database
    returns the SDK version used, the possible SoftDevice versions and associated RAM and ROM binary addresses
    """
    def __init__(self, binfile, cur, objtype):
        self.cur = cur
        self.sdk_version = None
        self.sdv_version = None
        self.sign = None
        self.bin = binfile
        self.nrf = None
        self.sdvs = []
        self.identified = 0

    def signature(self):
        """
        Computes the softdevice signature
        The signature is the sha256 hash of specific bytes of the ihex file
        """
        print("\nComputing signature from binary")
        for i in tqdm(range(1)):
            time.sleep(0.05)
        with open(self.bin, 'rb+') as sdv_hex:
            # skip bytes from 0x07C0 to 0x1000 
            sdv_hex.seek(0)
            first = sdv_hex.read(1983)
            sdv_hex.seek(4096)
            extract = sdv_hex.read(10000)
            self.sign = hashlib.sha256(extract).hexdigest()
        print("Signature: ", self.sign)

    def identify(self):
        """
        Identifies the firmware based on its signature in the database
        """
        print("Searching for signature in nRF.db")
        for i in tqdm(range(1)):
            time.sleep(0.05)
        req = "select sdk_version, nrf, softdevice_v from SoftDevice where sign LIKE ?"
        self.cur.execute(req, (self.sign, ))
        res = self.cur.fetchall()
        # CASE 1 : signature of the binary file is not in database
        if res == []:
            print("Signature not found in nRF5x database")
            print("\nComputing approximate signature from strings in binary")
            #content = "Nordic Semiconductor"
            cmd = "strings " + self.bin + " | grep Nordic\ Semiconductor/ | cut -d '/' -f 3,5"
            cmd += "| sed -e s/'\/'/'_'/g | cut -d ' ' -f 2 | sed -e s/'SDK_'/''/g | "
            cmd += "sed -e s/'.0_'/'_'/g | sort -u"
            nrf_sign = subprocess.getoutput(cmd)
            print(nrf_sign)
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
                    if len(res) > 1:
                        self.multiple = 1
                    self.sdv_version = sdv[0]
                    print("Possible SoftDevice version: ", self.sdv_version)
                print("=========================")
                with open("nRF_ver", "w") as nrf_version:
                    nrf_version.write(self.sign)
                print("nRF5x signature identified from strings in provided binary")
                print("Signature written to file nRF_ver in current directory")
                print("nRF_ver path must be provided when running nrfreverse.py from IDA")
                self.identified = 1
            else:
                print("Can't be identified")
        # CASE 2 : signature of the binary file is in database
        else:
            self.identified = 1
            self.multiple = 1
            for sdv in res:
                self.sdk_version = sdv[0]
                self.nrf = sdv[1]
                self.sdv_version = sdv[2]
                print("=========================")
                print("SDK version: ", self.sdk_version)
                print("SoftDevice version:", self.sdv_version)
                print("NRF:", self.nrf)
            with open("nRF_ver", "w") as nrf_version:
                nrf_version.write(self.sign)
            print("                               ==================")
            print("nRF5x signature written to file nRF_ver in current directory")
            print("nRF_ver path must be provided when running nrfreverse.py from IDA")

    def map_binary(self):
        """
        Maps the binary at the right memory addresses
        """
        if self.identified == 1:
            if self.multiple is None:
                req = "select softdev_v, card_version, ram_origin, ram_length, rom_origin, rom_length from MemoryAddr where softdev_signature LIKE ? and nrf=? GROUP BY card_version, ram_origin, ram_length, rom_origin, rom_length"
                self.cur.execute(req, (self.sign, self.nrf))
                for res in self.cur.fetchall():
                    mem_props(res, "m")
            else:
                req = "select softdev_v, card_version, ram_origin, ram_length, rom_origin, rom_length, nrf from MemoryAddr where softdev_signature LIKE ? GROUP BY card_version, ram_origin, ram_length, rom_origin, rom_length"
                self.cur.execute(req, (self.sign, ))
                for res in self.cur.fetchall():
                    mem_props(res, "")
                
def mem_props(res, ident_type):
    if ident_type != "m":
        softdev = res[0]
        card_v = res[1]
        ram_addr = res[2]
        ram_length = res[3]
        rom_addr = res[4]
        rom_length = res[5]
        print("\n", " "*35, "*****")
        print(" "*33, "Binary mapping")
        print(" "*36, "*****\n")
        print("SoftDevice  : ", softdev)
        print("Card version : ", card_v)
        print(" "*10, "*****")
        print("RAM address  : ", ram_addr)
        print("RAM length   : ", ram_length)
        print("ROM address  : ", rom_addr)
        print("ROM length   : ", rom_length)
    else:
        nrf = res[6]

def bin_to_hex(binary):
    """
    Returns the ihex format from the given the bin file
    """
    hexfile = binary.replace(".bin", ".hex")
    bin2hex(binary, hexfile)
    print("Converting file object format from bin to hex")
    for i in tqdm(range(1)):
        time.sleep(0.05)
    print("Hex file successfully dumped on disk: {0}".format(hexfile))
    return hexfile

def hex_2_binary(hexfile):
    """
    Returns the binary format from the given ihex file
    """
    ih = IntelHex(hexfile)
    bin_file = hexfile.replace(".hex", "-1.bin")
    ih.tobinfile(bin_file)
    print("Dumping binary from hex file to directory: ", bin_file)
    return bin_file

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
    binfile = ""
    hexfile = ""
    if args.format == 'hex':
        hexfile = sys.argv[2]
        objtype = 'hex'
        print("Hex file provided {0}".format(hexfile))
        binfile = hex_2_binary(hexfile)
    elif args.format == 'bin':
        binfile = sys.argv[2]
        objtype = 'bin'
        print("Binary file provided {0}".format(binfile))
    nrf = NRF5xIdentify(binfile, cur, objtype)
    nrf.signature()
    nrf.identify()
    nrf.map_binary()
    con.close()

if __name__ == "__main__":
    main()
