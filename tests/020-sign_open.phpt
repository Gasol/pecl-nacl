--TEST--
Check for sign_open
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
require 'hex2bin.inc';

$public_key = hex2bin('d3fd327abf940851f8d21aeda98d89454f4ccc97f531e00cb04c6a31c296b76f');
$sig_message = hex2bin('044031575ad8282702ef28c7da4db2a149f8fa0aaed31699d54bcb274cd6335b6d657373616765bd535c5ade0512470029837bc9163f96458fa7d8a420742758d0cc70c39c2904');
var_dump(nacl_crypto_sign_open($sig_message, $public_key));
?>
--EXPECTF--
string(7) "message"
