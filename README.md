PHP NaCl
========

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

See [ports/175820](http://www.freebsd.org/cgi/query-pr.cgi?pr=ports/175820)

    $ cd /usr/ports/security/nacl
    $ curl 'http://www.freebsd.org/cgi/query-pr.cgi?pr=ports%2F175820&getpatch=1' | patch
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
