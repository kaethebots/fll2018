#!/usr/bin/python
# origin: https://gist.github.com/gileri/5a9285d6a1cfde142260
#
# modified by karlbeecken and leonelbohnet
#

import time
import struct
import smbus
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x08

def get_data():
    return bus.read_i2c_block_data(address, 0);

def get_float(data, index):
    bytes = data[4*index:(index+1)*4]
    return struct.unpack('f', "".join(map(chr, bytes)))[0]

while True:
    try:
        data = get_data()
        print(get_float(data, 0))
	break
    except:
        continue
time.sleep(0.05);
