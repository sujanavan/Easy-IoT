<?php
//check if request is empty
if(empty($_GET["data"])) die();
//set date and time to IST
date_default_timezone_set('Asia/Kolkata');
//capture current data time in specific format Year,month,date Hours,Min,Sec
$dt = date('Y-m-d H:i:s');
$myfile = fopen("data", "a") or die("Unable to open file!");
$txt = "{$dt},{$_GET["data"]}\n";
fwrite($myfile, $txt);
fclose($myfile);
?>