
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


/**
 * DotPHP 路径工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Utils_Path) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Utils, Path, dotphp, utils_path, dotphp_utils_path_method_entry, 0);

	return SUCCESS;

}

/**
 * 合并一个或多个路径符。
 *
 * @return string
 */
PHP_METHOD(DotPHP_Utils_Path, combin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *size = NULL, *path, *s = NULL, _0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 26);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&size, "func_num_args", NULL, 27);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(size, 0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/", 0);
	ZEPHIR_INIT_VAR(path);
	zephir_fast_join(path, &_0, args TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/[\\/]+/i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&s, "preg_replace", NULL, 28, _1, _2, path);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_CCTOR(s);

}

