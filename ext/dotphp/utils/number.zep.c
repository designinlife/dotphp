
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
#include "kernel/operators.h"
#include "kernel/math.h"
#include "kernel/memory.h"
#include "math.h"


/**
 * DotPHP 数字工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Utils_Number) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Utils, Number, dotphp, utils_number, dotphp_utils_number_method_entry, 0);

	return SUCCESS;

}

/**
 * 检查 num 数值是否为素数？
 *
 * @param int num
 * @return boolean
 */
PHP_METHOD(DotPHP_Utils_Number, isPrime) {

	zend_bool _2;
	zval *num_param = NULL, *end = NULL, *_0, _1, *_4 = NULL;
	int num, i = 0, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &num_param);

	num = zephir_get_intval(num_param);


	if (num == 1) {
		RETURN_MM_BOOL(0);
	}
	if (num == 2) {
		RETURN_MM_BOOL(1);
	}
	if (0 == (int) (zephir_safe_mod_long_long(num, 2 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, num);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, sqrt(num));
	ZEPHIR_INIT_VAR(end);
	ZVAL_DOUBLE(end, zephir_ceil(&_1 TSRMLS_CC));
	ZEPHIR_CPY_WRT(_4, end);
	_3 = 3;
	_2 = 0;
	if (ZEPHIR_GE_LONG(_4, _3)) {
		while (1) {
			if (_2) {
				_3 += 2;
				if (!(ZEPHIR_GE_LONG(_4, _3))) {
					break;
				}
			} else {
				_2 = 1;
			}
			i = _3;
			if (0 == (int) (zephir_safe_mod_long_long(num, i TSRMLS_CC))) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

