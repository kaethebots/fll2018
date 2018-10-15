#!/usr/bin/python
#
# origin: https://codingworld.io/project/den-arduino-mit-dem-raspberry-pi-verbinden-i2c
# can be helpful: http://wiki.erazor-zone.de/wiki:linux:python:smbus:doc
#
# modified by karlbeecken
#
# usage: i2c-master.py <i2cAddress> <value to send>

import smbus
import time
import sys
bus = smbus.SMBus(1)

#addr = int
#val = chr

try:
    addr = int(sys.argv[1])
except IndexError:
    addr = 0x08

try:
    val = int(sys.argv[2])
except IndexError:
    val = 74

#def writeNumber(value):
def writeI2C():
    print addr,val
    bus.write_byte(addr,val)
    return

writeI2C()
#    return -1

#def readNumber():
#    number = bus.read_byte(address)
#    return number

#while True:
#    senden = input("Geraeteaddresse und -zustand: ")
#    if not senden:
#        continue
#
#    writeNumber(senden)
#    print "Raspberry schickt folgenden Wert: ", senden
#    time.sleep(1)

#    empfang = readNumber()
#    print "Der Arduino schickt folgenden Wert: ", empfang
