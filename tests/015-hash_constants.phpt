--TEST--
Check for constants of hash
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--FILE--
<?php
echo constant('NACL_CRYPTO_HASH_BYTES') . PHP_EOL;
echo constant('NACL_CRYPTO_HASH_PRIMITIVE') . PHP_EOL;
echo constant('NACL_CRYPTO_HASH_IMPLEMENTATION') . PHP_EOL;
echo constant('NACL_CRYPTO_HASH_VERSION') . PHP_EOL;
?>
--EXPECT--
64
sha512
crypto_hash/sha512/ref
-
