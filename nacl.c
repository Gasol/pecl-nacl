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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_nacl.h"
#include "crypto_auth.h"
#include "crypto_hash.h"
#include "crypto_secretbox.h"
#include "crypto_stream.h"
#include "crypto_onetimeauth.h"

/* If you declare any globals in php_nacl.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(nacl)
*/

/* True global resources - no need for thread safety here */
static int le_nacl;

/* {{{ nacl_functions[]
 *
 * Every user visible function must have an entry in nacl_functions[].
 */
const zend_function_entry nacl_functions[] = {
	PHP_FE(nacl_crypto_auth, NULL)
	PHP_FE(nacl_crypto_auth_verify, NULL)
	PHP_FE(nacl_crypto_stream, NULL)
	PHP_FE(nacl_crypto_stream_xor, NULL)
	PHP_FE(nacl_crypto_secretbox, NULL)
	PHP_FE(nacl_crypto_secretbox_open, NULL)
	PHP_FE(nacl_crypto_onetimeauth, NULL)
	PHP_FE(nacl_crypto_onetimeauth_verify, NULL)
	PHP_FE(nacl_crypto_hash, NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ nacl_module_entry
 */
zend_module_entry nacl_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"nacl",
	nacl_functions,
	PHP_MINIT(nacl),
	PHP_MSHUTDOWN(nacl),
	PHP_RINIT(nacl),
	PHP_RSHUTDOWN(nacl),
	PHP_MINFO(nacl),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_NACL
ZEND_GET_MODULE(nacl)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(nacl)
{
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_AUTH_BYTES", crypto_auth_BYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_AUTH_KEYBYTES", crypto_auth_KEYBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_AUTH_PRIMITIVE", crypto_auth_PRIMITIVE, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_AUTH_IMPLEMENTATION", crypto_auth_IMPLEMENTATION, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_AUTH_VERSION", crypto_auth_VERSION, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("NACL_CRYPTO_STREAM_KEYBYTES", crypto_stream_KEYBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_STREAM_NONCEBYTES", crypto_stream_NONCEBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_STREAM_PRIMITIVE", crypto_stream_PRIMITIVE, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_STREAM_IMPLEMENTATION", crypto_stream_IMPLEMENTATION, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_STREAM_VERSION", crypto_stream_VERSION, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("NACL_CRYPTO_SECRETBOX_KEYBYTES", crypto_secretbox_KEYBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_SECRETBOX_NONCEBYTES", crypto_secretbox_NONCEBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_SECRETBOX_ZEROBYTES", crypto_secretbox_ZEROBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_SECRETBOX_BOXZEROBYTES", crypto_secretbox_BOXZEROBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_SECRETBOX_PRIMITIVE", crypto_secretbox_PRIMITIVE, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_SECRETBOX_IMPLEMENTATION", crypto_secretbox_IMPLEMENTATION, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_SECRETBOX_VERSION", crypto_secretbox_VERSION, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("NACL_CRYPTO_ONETIMEAUTH_BYTES", crypto_onetimeauth_BYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("NACL_CRYPTO_ONETIMEAUTH_KEYBYTES", crypto_onetimeauth_KEYBYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_ONETIMEAUTH_PRIMITIVE", crypto_onetimeauth_PRIMITIVE, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_ONETIMEAUTH_IMPLEMENTATION", crypto_onetimeauth_IMPLEMENTATION, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_ONETIMEAUTH_VERSION", crypto_onetimeauth_VERSION, CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("NACL_CRYPTO_HASH_BYTES", crypto_hash_BYTES, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_HASH_PRIMITIVE", crypto_hash_PRIMITIVE, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_HASH_IMPLEMENTATION", crypto_hash_IMPLEMENTATION, CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("NACL_CRYPTO_HASH_VERSION", crypto_hash_VERSION, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(nacl)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(nacl)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(nacl)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(nacl)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "nacl support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ nacl_crypto_auth
 */
PHP_FUNCTION(nacl_crypto_auth)
{
	const unsigned char k[crypto_auth_KEYBYTES];
	unsigned char *returnval, *data, *key = NULL;
	int data_len, key_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &data, &data_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_auth_KEYBYTES);

	returnval = safe_emalloc(crypto_auth_BYTES, 1, 1);

	if (crypto_auth(returnval, data, data_len, k)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, crypto_auth_BYTES, 0);
}
/* }}} */

/* {{{ nacl_crypto_auth_verify
 */
PHP_FUNCTION(nacl_crypto_auth_verify)
{
	unsigned char *hash, *data, *key = NULL;
	int hash_len, data_len, key_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &hash, &hash_len, &data, &data_len, &key, &key_len) == FAILURE) {
		return;
	}

	int ret = crypto_auth_verify(hash, data, data_len, key);
	if (ret) {
		RETURN_FALSE;
	} else {
		RETURN_TRUE;
	}
}
/* }}} */

/* {{{ nacl_crypto_stream
 */
PHP_FUNCTION(nacl_crypto_stream)
{
	const unsigned char k[crypto_stream_KEYBYTES], n[crypto_stream_NONCEBYTES];
	unsigned char *returnval, *data, *key, *nonce = NULL;
	int data_len, key_len, nonce_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &data, &data_len, &nonce, &nonce_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_stream_KEYBYTES);
	strncpy((char *) &n, (const char *) nonce, crypto_stream_NONCEBYTES);

	returnval = safe_emalloc(data_len, 1, 1);

	if (crypto_stream(returnval, data_len, n, k)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, data_len, 0);
}
/* }}} */

/* {{{ nacl_crypto_stream_xor
 */
PHP_FUNCTION(nacl_crypto_stream_xor)
{
	const unsigned char k[crypto_stream_KEYBYTES], n[crypto_stream_NONCEBYTES];
	unsigned char *returnval, *data, *key, *nonce = NULL;
	int data_len, key_len, nonce_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &data, &data_len, &nonce, &nonce_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_stream_KEYBYTES);
	strncpy((char *) &n, (const char *) nonce, crypto_stream_NONCEBYTES);

	returnval = safe_emalloc(data_len, 1, 1);

	if (crypto_stream_xor(returnval, data, data_len, n, k)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, data_len, 0);
}
/* }}} */

/* {{{ nacl_crypto_secretbox
 */
PHP_FUNCTION(nacl_crypto_secretbox)
{
	const unsigned char k[crypto_secretbox_KEYBYTES], n[crypto_secretbox_NONCEBYTES];
	unsigned char *returnval, *data, *key, *nonce = NULL;
	int data_len, key_len, nonce_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &data, &data_len, &nonce, &nonce_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_secretbox_KEYBYTES);
	strncpy((char *) &n, (const char *) nonce, crypto_secretbox_NONCEBYTES);

	returnval = safe_emalloc(data_len, 1, 1);

	if (crypto_secretbox(returnval, data, data_len, n, k)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, data_len, 0);
}
/* }}} */

/* {{{ nacl_crypto_secretbox_open
 */
PHP_FUNCTION(nacl_crypto_secretbox_open)
{
	const unsigned char k[crypto_secretbox_KEYBYTES], n[crypto_secretbox_NONCEBYTES];
	unsigned char *returnval, *data, *key, *nonce = NULL;
	int data_len, key_len, nonce_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &data, &data_len, &nonce, &nonce_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_secretbox_KEYBYTES);
	strncpy((char *) &n, (const char *) nonce, crypto_secretbox_NONCEBYTES);

	returnval = safe_emalloc(data_len, 1, 1);

	if (crypto_secretbox_open(returnval, data, data_len, n, k)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, data_len, 0);
}
/* }}} */

/* {{{ nacl_crypto_onetimeauth
 */
PHP_FUNCTION(nacl_crypto_onetimeauth)
{
	const unsigned char k[crypto_onetimeauth_KEYBYTES];
	unsigned char *returnval, *data, *key = NULL;
	int data_len, key_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &data, &data_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_onetimeauth_KEYBYTES);

	returnval = safe_emalloc(crypto_onetimeauth_BYTES, 1, 1);

	if (crypto_onetimeauth(returnval, data, data_len, k)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, crypto_onetimeauth_BYTES, 0);
}
/* }}} */

/* {{{ nacl_crypto_onetimeauth_verify
 */
PHP_FUNCTION(nacl_crypto_onetimeauth_verify)
{
	const unsigned char k[crypto_onetimeauth_KEYBYTES];
	unsigned char *auth, *data, *key = NULL;
	int auth_len, data_len, key_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &auth, &auth_len, &data, &data_len, &key, &key_len) == FAILURE) {
		return;
	}

	strncpy((char *) &k, (const char *) key, crypto_onetimeauth_KEYBYTES);

	if (crypto_onetimeauth_verify(auth, data, data_len, k)) {
		RETURN_FALSE;
	} else {
		RETURN_TRUE;
	}
}
/* }}} */

/* {{{ nacl_crypto_hash
 */
PHP_FUNCTION(nacl_crypto_hash)
{
	unsigned char *returnval, *data = NULL;
	int data_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &data, &data_len) == FAILURE) {
		return;
	}

	returnval = safe_emalloc(crypto_hash_BYTES, 1, 1);

	if (crypto_hash(returnval, data, data_len)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, crypto_hash_BYTES, 0);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
