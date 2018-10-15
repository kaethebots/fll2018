#!/usr/bin/python
#
# origin: https://codingworld.io/project/den-arduino-mit-dem-raspberry-pi-verbinden-i2c
#
# modified by karlbeecken
#
# usage: i2c-master.py <i2cAddress> <value to send>

import smbus
import time
import sys
bus = smbus.SMBus(1)

try:
    address = sys.argv[1]
except IndexError:
    address = 8

try:
    senden = sys.argv[2]
except IndexError:
    senden = 42

def writeNumber(value):
    bus.write_byte(address, value)
    return -1

#def readNumber():
#    number = bus.read_byte(address)
#    return number

#while True:
#    senden = input("Geraeteaddresse und -zustand: ")
#    if not senden:
#        continue
#
    writeNumber(senden)
    print "Raspberry schickt folgenden Wert: ", senden
    time.sleep(1)

    empfang = readNumber()
    print "Der Arduino schickt folgenden Wert: ", empfang
