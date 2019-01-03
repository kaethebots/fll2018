#!/bin/bash

#
# by karlbeecken
#
# usage: ./send-to-vz.sh > /dev/null &
# debugging: just ./send-to-vz.sh and uncomment line 16
#

IFS=' '                   # sets the IFS to space
#temp="22.75834845"
#hum="56.46357645"
tempuuid="af1e5b80-c70b-11e8-93fa-ddbac8086c38"   # put here your vz-uuid for the temperature sensor
humuuid="ec0736b0-ce3a-11e8-983d-81145097ecf6"    # put here your vz-uuid for the humidity sensor
temp2uuid="0b22b680-f3ec-11e8-93dc-ef508458ba74"  # put here your vz-uuid for the 2nd temperature sensor
#echo "$datain"

while true        # loop every 10 seconds
do
  datain=$(python read-float.py)      # defines the data input (= read script)
  echo "$datain"                      # debug output
  read temp hum temp2 <<< $datain     # seperates the data input into temp and hum values
  if [ $hum != nan ]
  then
  if [ "$temp" != "-127.0" ]
  then
    wget -O - -q "http://localhost/middleware.php/data/$tempuuid.json?operation=add&value=$temp" > /dev/null # sends the temp value to vz
    echo "$temp"                                # debug output
  fi
  fi
  if [ $hum != nan ]
  then
  if [ "$hum" != "0.0" ]
    then
    wget -O - -q "http://localhost/middleware.php/data/$humuuid.json?operation=add&value=$hum" > /dev/null   # sends the hum value to vz
    echo "$hum"                       # debug output
  fi
  fi
  if [ $temp2 != nan ]
  then
    if [ "$temp2" != "0.0" ]
    then
    wget -O - -q "http://localhost/middleware.php/data/$temp2uuid.json?operation=add&value=$temp2" > /dev/null # sends the temp2 value to vz
    echo "$temp2"
    fi
  fi
  sleep 2
done
