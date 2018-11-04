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

import smbus            # imports all the needed librarys
import time
import sys
bus = smbus.SMBus(1)

try:                    # reads the first cli argument
    addr = int(sys.argv[1])
except IndexError:      # error hndling for IndexErrors
    addr = 0x08

try:                    # reads the second cli argument
    val = int(sys.argv[2])
except IndexError:      # error handling for IndexErrors
    val = 74

def writeI2C():         # defines function for sending the data over the i2c bus
    print addr,val      # debug output
    bus.write_byte(addr,val) # finally sends the data
    return

writeI2C()              # executes the function
print("Success")        # debug output
