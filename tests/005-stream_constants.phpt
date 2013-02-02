--TEST--
Check for constants of nacl_crypto_stream
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_STREAM_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_VERSION') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_NONCEBYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_STREAM_KEYBYTES') . PHP_EOL;
?>
--EXPECT--
xsalsa20
crypto_stream/xsalsa20/ref
-
24
32

