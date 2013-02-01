--TEST--
Check for encrypt and decrypt string hello by nacl_crypto_stream_xor
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
$nonce = 'nonce';
$key = 'key';

$plaintext = 'hello';
$ciphertext = nacl_crypto_stream_xor($plaintext, $nonce, $key);
echo nacl_crypto_stream_xor($ciphertext, $nonce, $key);
?>
--EXPECT--
hello
