# NRF5x Reversing #

This repository contains a collection of tools to reverse NRF5x firmwares.

## How to install dependencies ##

```
pip3 install sqlite3 SQLAlchemy
```

## NRF parsing and database population ##

The `nrfparse.py` python script must be run once to generate and populate the `nRF.db` SQLite3 database.

It parses the different SDKs versions from developer.nordicsemi/nRF5_SDK directory to extract for each softdevice :
- Associated SDK version
- Associated NRF
- Associated RAM and FLASH addresses and sections length for binary mapping in IDA pro
- Associated SVC_BASE and SVC_LAST ranges
- Associated SVCALLS' structures
- Associtade SVCALLS prototypes that will help nrfreverse using IDA python to define types of SVCALLS and rename functions and parameters

## NRF identification given a .hex or .bin version of the firmware ##

The `nrfidentify.py` python script is run with one argument, a NRF firmware in its .hex or .bin version.

The script computes the hex signature, then looks for it in the `nRF.db` database.
If not found, the binary version is generated and identified using the strings in the binary.

An approximate signature is then generated and used for firmware identification.

The following information are then extracted from the `nRF.db`:
- Associated SDK version
- Associated NRF
- Associated RAM and FLASH addresses and sections length for binary mapping in IDA pro

A file named `nRF_version` is then generated containing the firmware's signature.

This file is used with the `nRF.db` by `nrfreverse.py` that mainly uses IDApython to redefine types and rename SVCALL functions.
The `nRF.db` and `nRF_version` can be be copied to the  `%PROGRAMFILES%\IDA\python` folder.

2 cases are handled:

### Case 1 ###

If the binary has a recognized signature in the database, the associated *SVCALLs* will be outputed.

### Case 2 ###

If the binary doesn't have a recognized signature in the database (this is due to the fact that there is no .hex file in the SDK archive):

```
$strings ../netwyse_ble_app.bin | grep Nordic\ Semiconductor/ | cut -d "/" -f 3,5 |  sed -e s/'\/'/'_'/g | cut -d ' ' -f 2 | sort -u


result : SDK_v6.1.0.0_nrf51822 => the softdevice'signature is : v6.1.0_nrf512822_softdevVersion
```

Finding the associated *SVCALLs* is possible only if SVC's numbers don't change from a softdevice version to another (s110, s210, ...etc). Otherwise the softversion must be provided.


## NRF firmware reversing in IDA pro ##

The NRF firmware is mapped in IDA pro using associated FLASH and RAM addresses and lengths.

The `nrfreverse.py` python script needs the nRF_ver path to identify the firmware's signature.

It then parses the assembly code of the given nRF5x firmware to find *SVC* opcodes.

It selects the appropriate functions' prototypes from the `nRF.db` and outputs them in the python output window of IDA pro.

### Further improvements ###

1. Automatically mapping the binary according to the RAM and FLASH addresses and length in IDA pro.

2. Recover classic libc functions based on their corresponding signatures

3. Moar testing !
