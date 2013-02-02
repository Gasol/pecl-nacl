--TEST--
Check for sign
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
$secret_key = hex2bin('b0b0a9ce2fe3dfd093c334603725f638d64643ae238781f0a73ec5525db7c94bbad832eefe57e76d691c8c7bf4007ca7aabdeebbf708989c310883ddb3579fae');
$message = 'message';
$out1 = nacl_crypto_sign('message', $secret_key);
$out2 = bin2hex(nacl_crypto_sign('message', $secret_key, true));
var_dump($out1);
var_dump($out2);
var_dump($out1 === $out2);
?>
--EXPECTF--
string(142) "%x"
string(142) "%x"
bool(true)
