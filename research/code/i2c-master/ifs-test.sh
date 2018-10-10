#!/bin/#!/bin/sh
#
# by karlbeecken
# test for internal file seperator of bash
#
#

IFS=','

outdata='python i2c-read-float.py'

temp1=$(echo $outdata |)