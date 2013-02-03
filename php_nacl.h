/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_NACL_H
#define PHP_NACL_H

extern zend_module_entry nacl_module_entry;
#define phpext_nacl_ptr &nacl_module_entry

#ifdef PHP_WIN32
#	define PHP_NACL_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_NACL_API __attribute__ ((visibility("default")))
#else
#	define PHP_NACL_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(nacl);
PHP_MSHUTDOWN_FUNCTION(nacl);
PHP_RINIT_FUNCTION(nacl);
PHP_RSHUTDOWN_FUNCTION(nacl);
PHP_MINFO_FUNCTION(nacl);

PHP_FUNCTION(nacl_crypto_auth);
PHP_FUNCTION(nacl_crypto_auth_verify);
PHP_FUNCTION(nacl_crypto_box);
PHP_FUNCTION(nacl_crypto_box_keypair);
PHP_FUNCTION(nacl_crypto_stream);
PHP_FUNCTION(nacl_crypto_stream_xor);
PHP_FUNCTION(nacl_crypto_secretbox);
PHP_FUNCTION(nacl_crypto_secretbox_open);
PHP_FUNCTION(nacl_crypto_sign);
PHP_FUNCTION(nacl_crypto_sign_open);
PHP_FUNCTION(nacl_crypto_sign_keypair);
PHP_FUNCTION(nacl_crypto_onetimeauth);
PHP_FUNCTION(nacl_crypto_onetimeauth_verify);
PHP_FUNCTION(nacl_crypto_hash);

static inline void php_nacl_bin2hex(char *out, const unsigned char *in, int in_len)
{
	static const char hexits[17] = "0123456789abcdef";
	int i;

	for(i = 0; i < in_len; i++) {
		out[i * 2]       = hexits[in[i] >> 4];
		out[(i * 2) + 1] = hexits[in[i] &  0x0F];
	}
}

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(nacl)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(nacl)
*/

/* In every utility function you add that needs to use variables 
   in php_nacl_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as NACL_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define NACL_G(v) TSRMG(nacl_globals_id, zend_nacl_globals *, v)
#else
#define NACL_G(v) (nacl_globals.v)
#endif

#endif	/* PHP_NACL_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
