#!/bin/sh

temp="22.75834845"

while true
do
temp=`python test.py`
wget -O - -q "http://localhost/middleware.php/data/af1e5b80-c70b-11e8-93fa-ddbac8086c38.json?operation=add&value=$temp" > /dev/null
echo "$temp"
sleep 1
done
