#!/usr/bin/python
#
#    fll2018 - code for a smart glasshouse
#    Copyright (C) 2018  Karl Beecken
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# can be helpful: http://wiki.erazor-zone.de/wiki:linux:python:smbus:doc
#
# usage: i2c-master.py <i2cAddress> <value to send>

import smbus
import time
import sys
bus = smbus.SMBus(1)

try:
    addr = int(sys.argv[1])
except IndexError:
    addr = 0x08

try:
    val = int(sys.argv[2])
except IndexError:
    val = 74

def writeI2C():
    print addr,val
    bus.write_byte(addr,val)
    return

writeI2C()
print("Success")
