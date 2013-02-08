--TEST--
Check for constants of box
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_BOX_PUBLICKEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_SECRETKEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_BEFORENMBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_NONCEBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_ZEROBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_BOXZEROBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_BOX_VERSION') . PHP_EOL;
?>
--EXPECTF--
32
32
32
24
32
16
curve25519xsalsa20poly1305
crypto_box/curve25519xsalsa20poly1305/%s
-

