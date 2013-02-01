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
#include "crypto_stream.h"

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
	PHP_FE(nacl_crypto_stream, NULL)
	PHP_FE(nacl_crypto_stream_xor, NULL)
	PHP_FE_END	/* Must be the last line in nacl_functions[] */
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
	PHP_RINIT(nacl),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(nacl),	/* Replace with NULL if there's nothing to do at request end */
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

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("nacl.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_nacl_globals, nacl_globals)
    STD_PHP_INI_ENTRY("nacl.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_nacl_globals, nacl_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_nacl_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_nacl_init_globals(zend_nacl_globals *nacl_globals)
{
	nacl_globals->global_value = 0;
	nacl_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(nacl)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(nacl)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(nacl)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
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

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ nacl_crypto_stream
 */
PHP_FUNCTION(nacl_crypto_stream)
{
	unsigned char *returnval, *data, *key, *nonce = NULL;
	int data_len, key_len, nonce_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &data, &data_len, &nonce, &nonce_len, &key, &key_len) == FAILURE) {
		return;
	}

	returnval = safe_emalloc(data_len, 1, 1);

	if (crypto_stream(returnval, data_len, nonce, key)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, data_len, 0);
}
/* }}} */

/* {{{ nacl_crypto_stream_xor
 */
PHP_FUNCTION(nacl_crypto_stream_xor)
{
	unsigned char *returnval, *data, *key, *nonce = NULL;
	int data_len, key_len, nonce_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &data, &data_len, &nonce, &nonce_len, &key, &key_len) == FAILURE) {
		return;
	}

	returnval = safe_emalloc(data_len, 1, 1);

	if (crypto_stream_xor(returnval, data, data_len, nonce, key)) {
		RETURN_FALSE;
	}

	RETURN_STRINGL((char *) returnval, data_len, 0);
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
