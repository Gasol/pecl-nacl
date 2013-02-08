--TEST--
Check for constants of nacl_crypto_auth
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_AUTH_BYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_AUTH_KEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_AUTH_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_AUTH_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_AUTH_VERSION') . PHP_EOL;
?>
--EXPECTF--
32
32
hmacsha512256
crypto_auth/hmacsha512256/%s
-

