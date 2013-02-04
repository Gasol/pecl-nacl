<?php

if (!function_exists('hex2bin')) {
    function hex2bin($hex) {
        $bin = null;
        $n = strlen($hex);
        for ($i = 0; $i < $n; $i += 2) {
            $h = substr($hex, $i, 2);
            $bin .= pack('H*', $h);
        }
        return $bin;
    }
}
