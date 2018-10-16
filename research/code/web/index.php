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

<!DOCTYPE html>
<html>
        <head>
                <title>Gew&auml;chsh&auml;user</title>

                <link rel="stylesheet" href="https://bootswatch.com/4/darkly/bootstrap.min.css">
                <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
                <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js"></script>
                <link href="https://gitcdn.github.io/bootstrap-toggle/2.2.2/css/bootstrap-toggle.min.css" rel="stylesheet">
                <script src="https://gitcdn.github.io/bootstrap-toggle/2.2.2/js/bootstrap-toggle.min.js"></script>
        </head>
        <body>
                        <div class="container-fluid">
                        <div class="row">
                        <div class="col-md-12">
                                <div class="page-header">
                                        <h1>
                                                Gew&auml;chshaussteuerung
                                        </h1>
                                </div>
                                <br>
                                <h3>
                                        Gew&auml;chshaus 1
                                </h3>
                                <br>
                                <div class="btn-group" role="group">

                                        <button class="btn btn-success" type="button" onclick="location.href='?i2cAddress=8&device=71'">
                                                Licht an
                                        </button>
                                        <button class="btn btn-danger" type="button" onclick="location.href='?i2cAddress=8&device=72'">
                                                Licht aus
                                        </button>
                                </div>
                                <br>
                                <div style="height: 10px;"></div>
                                <div class="btn-group" role="group">

                                        <button class="btn btn-success" type="button" onclick="window.location.href='?i2cAddress=8&device=73'">
                                                Debug an
                                        </button>
                                        <button class="btn btn-danger" type="button" onclick="window.location.href='?i2cAddress=8&device=74'">
                                                Debug aus
                                        </button>
                                </div>
                        </div>
                        <div class="well span6" style="padding-top: 50px">
                          <iframe src="http://magnesium.local:3000/d-solo/ILbsDszgk/temp-humi?theme=dark&orgId=1&panelId=2&from=now-1h-10m&to=now-10m" width="760" height="480" frameborder="0"></iframe>
                            <div class="well span6" style="padding-top: 50px">
                              <a class="btn" href="https://github.com/kaethebots/fll2018">View on Github >></a>
                            </div>
                        </div>
                      </body>
</html>
