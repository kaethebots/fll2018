#!/bin/sh

#
# by karlbeecken
#
# usage: ./send-to-vz.sh > /dev/null &
# debugging: just ./send-to-vz.sh
#

temp="22.75834845"
vzuuid="af1e5b80-c70b-11e8-93fa-ddbac8086c38"

while true
do
temp=`python test.py`
wget -O - -q "http://localhost/middleware.php/data/$vzuuid.json?operation=add&value=$temp" > /dev/null
echo "$temp"
sleep 1
done
