PHP NaCl
========

[![Build Status](https://travis-ci.org/Gasol/pecl-nacl.svg)](https://travis-ci.org/Gasol/pecl-nacl)

Intro
-----

This is a PHP interface to [NaCl](http://nacl.cace-project.eu/), not Google's NativeClient. 

NaCl is a new easy-to-use high-speed software library for network communication, encryption, decryption, signatures, etc. NaCl's goal is to provide all of the core operations needed to build higher-level cryptographic tools.

Requirements
------------

* PHP 5.3.3 or later
* NaCl 20110221 with PIC support

Installation as PHP module
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


NaCl library installation (for development)
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

TODO
----

Support Debian (wheezy) and Ubuntu 12.04
