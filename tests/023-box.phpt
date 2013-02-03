--TEST--
Check for box
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
$public_key = hex2bin('7637535cd3b6fac7911a76867eecca8ed7607b44a244447eea7d97c6b79c6575');
$secret_key = hex2bin('84e4055a9983f609dc74b728c3746c6a3c8a0cf08df791b1b8fe66909a2d003b');
$nonce = 'nonce';
$message = 'message';
$out1 = nacl_crypto_box($message, $nonce, $public_key, $secret_key);
$out2 = bin2hex(nacl_crypto_box($message, $nonce, $public_key, $secret_key, true));
var_dump($out1);
var_dump($out2);
var_dump($out1 === $out2);
?>
--EXPECTF--
string(46) "6e0aac25e9d43eda16f93b068524e341ea2b51a8162a7c"
string(46) "6e0aac25e9d43eda16f93b068524e341ea2b51a8162a7c"
bool(true)
