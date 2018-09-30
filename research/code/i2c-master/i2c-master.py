#!/usr/bin/python

# origin: https://codingworld.io/project/den-arduino-mit-dem-raspberry-pi-verbinden-i2c

import smbus
import time
from argparse import ArgumentParser
bus = smbus.SMBus(1)
parser = ArgumentParser()

address = 8 # Bedarf einer weiteren Überarbeitung

def writeNumber(value):
    bus.write_byte(address, value)
    return -1

def readNumber():
    number = bus.read_byte(address)
    return number

while True:
    senden = raw_input("Geräteadresse und -zustand: ")
    if not senden:
        continue

    writeNumber(senden)
    print "Raspberry schickt folgenden Wert: ", senden
    time.sleep(1)

    empfang = readNumber()
    print "Der Arduino schickt folgenden Wert: ", empfang
