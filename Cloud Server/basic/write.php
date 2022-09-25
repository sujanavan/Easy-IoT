<?php
$myfile = fopen("data", "w");
fwrite($myfile, $_GET["data"]);
fclose($myfile);
?>
