<?php
//check if request is empty
if(empty($_GET["l"]) || empty($_GET["t"]))
die();
//set date and time to IST
date_default_timezone_set('Asia/Kolkata');
//capture current data time in specific format Year,month,date Hours,Min,Sec
$dt = date('Y-m-d H:i:s');
$myfile = fopen("data", "a") or die("Unable to open file!");
$txt = "{$_GET["l"]},{$dt},{$_GET["t"]}\n";
fwrite($myfile, $txt);
fclose($myfile);
?>