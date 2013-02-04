--TEST--
Check for constants of onetimeauth
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_ONETIMEAUTH_KEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_ONETIMEAUTH_BYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_ONETIMEAUTH_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_ONETIMEAUTH_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_ONETIMEAUTH_VERSION') . PHP_EOL;
?>
--EXPECT--
32
16
poly1305
crypto_onetimeauth/poly1305/53
-

