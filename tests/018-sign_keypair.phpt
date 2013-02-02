--TEST--
Check for sign_keypair
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
var_dump(nacl_crypto_sign_keypair($public_key, $secret_key));
var_dump($public_key);
var_dump($secret_key);
var_dump(nacl_crypto_sign_keypair($public_key, $secret_key, true));
var_dump(bin2hex($public_key));
var_dump(bin2hex($secret_key));
?>
--EXPECTF--
bool(true)
string(64) "%x"
string(128) "%x"
bool(true)
string(64) "%x"
string(128) "%x"

