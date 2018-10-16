<?php

$addr_in = $_GET['i2cAddress'];
$dev_in = $_GET['device'];
$addr = escapeshellcmd($addr_in);
$dev = escapeshellcmd($dev_in);

exec("python ../i2c-master/switch.py $addr $dev");
header("Location:/ctrl/");

 ?>
