#!/bin/sh

#
# by karlbeecken
#
# usage: ./send-to-vz.sh > /dev/null &
# debugging: just ./send-to-vz.sh
#

IFS=$'\n'
#temp="22.75834845"
#hum="56.46357645"
tempuuid="af1e5b80-c70b-11e8-93fa-ddbac8086c38"
humuuid="ec0736b0-ce3a-11e8-983d-81145097ecf6"
datain=`python read-float.py`

while true
do
read temp hum <<< $datain
wget -O - -q "http://localhost/middleware.php/data/$tempuuid.json?operation=add&value=$temp" > /dev/null
echo "$temp"
wget -O - -q "http://localhost/middleware.php/data/$humuuid.json?operation=add&value=$hum" > /dev/null
echo "&hum"
sleep 0.5
done
