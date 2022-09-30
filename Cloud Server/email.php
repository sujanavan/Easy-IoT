<?php
$to = "abcd@mail.com";
$subject = "Heat Alert";
$message = "temp high";
$headers = 'From: IoT Server<donotreply>'; //no space between r<
mail($to,$subject,$message,$headers);
?>
