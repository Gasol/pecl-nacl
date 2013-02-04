--TEST--
Check for box_open
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
require 'hex2bin.inc';

$public_key = hex2bin('7637535cd3b6fac7911a76867eecca8ed7607b44a244447eea7d97c6b79c6575');
$secret_key = hex2bin('84e4055a9983f609dc74b728c3746c6a3c8a0cf08df791b1b8fe66909a2d003b');
$nonce = 'nonce';
$sig_message = hex2bin('6e0aac25e9d43eda16f93b068524e341ea2b51a8162a7c');
var_dump(nacl_crypto_box_open($sig_message, $nonce, $public_key, $secret_key));
?>
--EXPECTF--
string(7) "message"
