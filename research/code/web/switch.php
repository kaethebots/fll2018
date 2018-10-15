<?php

exec("python ../i2c-master/switch.py ($_GET["i2cAddress"])");
header("Location:/ctrl/");

?>
