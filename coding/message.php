<?php
$mobile = "919986171454";
$from = "varun@six.com";
$message = "This is a sample text message";
$headers = "From: $from\n";
mail($to, '',$message,$headers);

$apiKey = urlencode('SenYyJ2+xcA-WpSEgghZaFQT4K5vZ5gCBWUCBzEoAH');
	
	$numbers = array($mobile);
	$sender = urlencode('TXTLCL');
	$message = rawurlencode($message);
 
	$numbers = implode(',', $numbers);
 
	$data = array('apikey' => $apiKey, 'numbers' => $numbers, "sender" => $sender, "message" => $message);
 
	$ch = curl_init('https://api.textlocal.in/send/');
	curl_setopt($ch, CURLOPT_POST, true);
	curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	$response = curl_exec($ch);
	curl_close($ch);
	
	echo $response;
?>

