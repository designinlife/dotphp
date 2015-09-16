
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * DotPHP 数组工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Utils_ArrayUtil) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Utils, ArrayUtil, dotphp, utils_arrayutil, dotphp_utils_arrayutil_method_entry, 0);

	return SUCCESS;

}

/**
 * 检查数组是否包含 Associative 键？
 *
 * @param array arr
 * @param bool  reusingKeys
 * @return bool
 */
PHP_METHOD(DotPHP_Utils_ArrayUtil, isAssoc) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool reusingKeys;
	zval *arr_param = NULL, *reusingKeys_param = NULL, *r = NULL, _0, _1, *_2, *_3;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arr_param, &reusingKeys_param);

	zephir_get_arrval(arr, arr_param);
	if (!reusingKeys_param) {
		reusingKeys = 0;
	} else {
		reusingKeys = zephir_get_boolval(reusingKeys_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (zephir_fast_count_int(arr TSRMLS_CC) - 1));
	ZEPHIR_CALL_FUNCTION(&r, "range", NULL, 21, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	if (reusingKeys) {
		ZVAL_BOOL(_2, !ZEPHIR_IS_IDENTICAL(arr, r));
	} else {
		ZEPHIR_INIT_VAR(_3);
		zephir_array_keys(_3, arr TSRMLS_CC);
		ZVAL_BOOL(_2, !ZEPHIR_IS_IDENTICAL(_3, r));
	}
	RETURN_CCTOR(_2);

}

