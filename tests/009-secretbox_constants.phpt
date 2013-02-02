--TEST--
Check for constants of secretbox
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_SECRETBOX_KEYBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SECRETBOX_NONCEBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SECRETBOX_ZEROBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SECRETBOX_BOXZEROBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_SECRETBOX_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_SECRETBOX_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_SECRETBOX_VERSION') . PHP_EOL;
?>
--EXPECT--
32
24
32
16
xsalsa20poly1305
crypto_secretbox/xsalsa20poly1305/ref
-

