<?php
$to = "abcd@mail.com"; //kindly add a correct mail id
$subject = "Heat Alert";
$message = "Temperature = Value C";
$headers = 'From: IoT Server<donotreply>'; //no space between ..r<.. 
mail($to,$subject,$message,$headers);
?>
