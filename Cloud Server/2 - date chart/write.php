<?php
//check if request is empty Loc=Location Temp=temperature Eg.:URL/write.php?Loc=Uppal&Temp=25
if(empty($_GET["Loc"]) || empty($_GET["Temp"])) die();
//set date and time to IST
date_default_timezone_set('Asia/Kolkata');
//capture current data time in specific format Year,month,date Hours,Min,Sec
$dt = date('Y-m-d H:i:s');
$myfile = fopen("data", "a") or die("Unable to open file!");
$txt = "{$_GET["Loc"]},{$dt},{$_GET["Temp"]}\n";
fwrite($myfile, $txt);
fclose($myfile);
?>
