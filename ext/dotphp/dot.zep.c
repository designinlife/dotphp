
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"


/**
 * DotPHP 常量定义。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Dot) {

	ZEPHIR_REGISTER_CLASS(DotPHP, Dot, dotphp, dot, dotphp_dot_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * 系统根目录。
	 *
	 * @var string
	 */
	zend_declare_property_null(dotphp_dot_ce, SL("sys_root"), ZEND_ACC_STATIC|ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_INSERT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_DELETE"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_DDL"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_FETCH"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_FETCH_ALL"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("SQL_TYPE_SCALAR"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_OFF"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_FATAL"), 100 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_ERROR"), 200 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_WARN"), 300 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_INFO"), 400 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_DEBUG"), 500 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_TRACE"), 600 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_ALL"), 9999 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_OUT_CONSOLE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_dot_ce, SL("LOG_OUT_DAILY_FILE"), 2 TSRMLS_CC);

	return SUCCESS;

}

/**
 * DotPHP 环境初始化方法。
 * 
 * @param string   sys_root_dir
 * @param callable class_auto_handler
 * @param int      error_level
 * @return void
 */
PHP_METHOD(DotPHP_Dot, setup) {

	zephir_fcall_cache_entry *_4 = NULL;
	int error_level, ZEPHIR_LAST_CALL_STATUS;
	zval *sys_root_dir_param = NULL, *class_auto_handler = NULL, *error_level_param = NULL, *_0, _1, *_2, _3 = zval_used_for_init;
	zval *sys_root_dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sys_root_dir_param, &class_auto_handler, &error_level_param);

	zephir_get_strval(sys_root_dir, sys_root_dir_param);
	if (!class_auto_handler) {
		class_auto_handler = ZEPHIR_GLOBAL(global_null);
	}
	if (!error_level_param) {
		error_level = 32759;
	} else {
		error_level = zephir_get_intval(error_level_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/\\", 0);
	zephir_fast_trim(_0, sys_root_dir, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "/");
	zephir_update_static_property_ce(dotphp_dot_ce, SL("sys_root"), &_2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, error_level);
	ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 17, &_3);
	zephir_check_call_status();
	if (zephir_is_callable(class_auto_handler TSRMLS_CC) == 1) {
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", &_4, 18, class_auto_handler);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "\\DotPHP\\Dot::def_class_auto_handler", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", &_4, 18, &_3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取系统根目录路径。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Dot, getRootDirectory) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(dotphp_dot_ce, SL("sys_root") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * SPL 类自动加载处理器。
 * 
 * @param string class_name
 * @return void
 */
PHP_METHOD(DotPHP_Dot, def_class_auto_handler) {

	zval *class_name_param = NULL, *file = NULL, _0, *_1, _2, *_3, *_4 = NULL, *_5 = NULL, *_6, _7 = zval_used_for_init, _8 = zval_used_for_init, _9, _10;
	zval *class_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_name_param);

	zephir_get_strval(class_name, class_name_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Twig", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, class_name, &_0, 0 );
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Application", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_strpos(_3, class_name, &_2, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
		ZEPHIR_OBS_VAR(_4);
		zephir_read_static_property_ce(&_4, dotphp_dot_ce, SL("sys_root") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_STRING(&_7, "_", 0);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_str_replace(&_6, &_7, &_8, class_name TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_STRING(&_9, "\\0", 0);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_STRING(&_10, "", 0);
		zephir_fast_str_replace(&_5, &_9, &_10, _6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(file);
		ZEPHIR_CONCAT_VSSVS(file, _4, "libs", "/", _5, ".php");
	} else if (ZEPHIR_IS_LONG_IDENTICAL(_3, 0)) {
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_static_property_ce(&_4, dotphp_dot_ce, SL("sys_root") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "\\", 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_str_replace(&_5, &_7, &_8, class_name TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VVS(file, _4, _5, ".php");
	} else {
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_static_property_ce(&_4, dotphp_dot_ce, SL("sys_root") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "\\", 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_str_replace(&_5, &_7, &_8, class_name TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VSSVS(file, _4, "libs", "/", _5, ".php");
	}
	if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

