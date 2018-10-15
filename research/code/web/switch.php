<?php

shell_exec(" python ../i2c-master/switch.py ($_GET["i2cAddress"]) ($_GET["device"]) ");
header("Location:/ctrl/");

 ?>
