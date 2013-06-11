PHP NaCl
========

[![Build Status](https://travis-ci.org/Gasol/pecl-nacl.png)](https://travis-ci.org/Gasol/pecl-nacl)

Intro
-----

This is a PHP interface to [NaCl](http://nacl.cace-project.eu/), not Google's NativeClient. 

NaCl is a new easy-to-use high-speed software library for network communication, encryption, decryption, signatures, etc. NaCl's goal is to provide all of the core operations needed to build higher-level cryptographic tools.

Requirements
------------

* PHP 5.3.3 or later
* NaCl 20110221 with PIC support

Installation
------------

### Install from source

Install

    $ git clone git://github.com/Gasol/pecl-nacl
    $ cd pecl-nacl
    $ phpize
    $ ./configure --with-nacl
    $ make install

Configuration

Add nacl extension into your php.ini

    extension=nacl.so


NaCl Installation Notes
-----------------------

#### Mac

Homebrew

    $ brew install nacl

#### FreeBSD

    $ cd /usr/ports/security/nacl
    $ make install clean

#### Build from source

    $ wget http://hyperelliptic.org/nacl/nacl-20110221.tar.bz2
    $ tar jxvf nacl-20110221.tar.bz2
    $ cd nacl-20110221
    $ rm -rf crypto_onetimeauth/poly1305/amd64
    $ sed -i -e "s/$/ -fPIC/" ${WRKSRC}/okcompilers/c
    $ ./do

#### Ubuntu

	$ bash alethia7/install_nacl.sh
	$ phpize --clean
	$ phpize
	$ # Replace hostname with your directory
	$ ./configure --with-nacl=alethia7/nacl-20110221/build/<hostname ?>/include/x86 --with-nacl-libdir=alethia7/nacl-20110221/build/<hostname ?>/lib/x86
	$ make
	$ sudo make install

#### Example
```php
$nonce = str_pad("", 24, "0123abc");
$plain = "To have eyes that see and ears that hear";
list($bobpk, $bobsk) = nacl_crypto_box_keypair();
list($alicepk, $alicesk) = nacl_crypto_box_keypair();
$cipher = nacl_crypto_box($plain, $nonce, $bobpk, $alicesk);
$plain_new = nacl_crypto_box_open($cipher, $nonce, $alicepk, $bobsk);

echo "Equal: " . ($plain === $plain_new ? "yes" : "no") . "\n";
```

TODO
----

Support Debian (wheezy) and Ubuntu 12.04
