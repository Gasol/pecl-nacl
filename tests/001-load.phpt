--TEST--
Check for nacl presence
--SKIPIF--
<?php if (!extension_loaded("nacl")) print "skip"; ?>
--FILE--
<?php 
echo "nacl extension is available";
?>
--EXPECT--
nacl extension is available
