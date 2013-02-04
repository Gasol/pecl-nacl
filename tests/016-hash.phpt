--TEST--
Check for hash
--SKIPIF--
<?php if (!extension_loaded('nacl')) echo 'skip'; ?>
--EXTENSIONS--
hash
--FILE--
<?php
$data = 'Foo';
var_dump(hash('sha512', $data, true) === nacl_crypto_hash($data));
?>
--EXPECT--
bool(true)
