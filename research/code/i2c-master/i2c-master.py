#!/usr/bin/python

# origin: https://codingworld.io/project/den-arduino-mit-dem-raspberry-pi-verbinden-i2c

import smbus
import time
bus = smbus.SMBus(1)

address = 0x05

def writeNumber(value):
    bus.write_byte(address, value)
    return -1

def readNumber():
    number = bus.read_byte(address)
    return number

while True:
    senden = input("Zahl zwischen 1 - 9: ")
    if not senden:
        continue

    writeNumber(senden)
    print "Raspberry schickt folgende Zahl: ", senden
    time.sleep(1)

    empfang = readNumber()
    print "Der Arduino empfängt/schickt folgende Zahl: ", empfang
