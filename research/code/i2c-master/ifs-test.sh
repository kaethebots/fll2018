#!/bin/bash
#
# by karlbeecken
# test for internal file seperator of bash
#
#

IFS=','

#datain='python read-float.py'
datain=22.434655,24.43567

read temp1 temp2 <<< $datain

echo "$temp1"
echo "$temp2"
