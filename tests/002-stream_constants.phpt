--TEST--
Check for constants of nacl_crypto_stream
--SKIPIF--
<?php require 'skipif.inc' ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_STREAM_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_VERSION') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_NONCEBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_KEYBYTES') . PHP_EOL;
?>
--EXPECTF--
xsalsa20
crypto_stream/xsalsa20/%s
-
24
32

