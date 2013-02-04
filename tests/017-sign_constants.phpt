--TEST--
Check for constants of sign
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_SIGN_BYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SIGN_PUBLICKEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SIGN_SECRETKEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SIGN_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_SIGN_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_SIGN_VERSION') . PHP_EOL;
?>
--EXPECT--
64
32
64
edwards25519sha512batch
crypto_sign/edwards25519sha512batch/ref
-

