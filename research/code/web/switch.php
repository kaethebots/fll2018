<?php

$addr_in = $_GET['i2cAddress'];
$dev_in = $_GET['device'];
$addr = escapeshellcmd($addr_in);
$dev = escapeshellcmd($dev_in);
$com_script = '../i2c-master/i2c-master.py';
$exec_com_script = realpath($com_script);

exec("python $exec_com_script $addr $dev");
header("Location:/ctrl/");

 ?>
