
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * DotPHP - 基于 CLI 命令行的启动器。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_CliBootstrap) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP, CliBootstrap, dotphp, clibootstrap, dotphp_abstractbootstrap_ce, dotphp_clibootstrap_method_entry, 0);

	return SUCCESS;

}

/**
 * 初始化完成事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_CliBootstrap, initializeComplete) {

	


}

/**
 * 执行路由解析。
 * 
 * @return \DotPHP\Bean\RouteMessage
 */
PHP_METHOD(DotPHP_CliBootstrap, route) {

	

	RETURN_NULL();

}

/**
 * 执行验证。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_CliBootstrap, validate) {

	


}

/**
 * 执行程序。
 * 
 * @param \DotPHP\Bean\RouteMessage route_message
 * @return void
 */
PHP_METHOD(DotPHP_CliBootstrap, execute) {

	zend_class_entry *_8;
	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route_message, *_0, *_1, *cls_n = NULL, *cls_o = NULL, *_3 = NULL, *_4, *_5, _6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route_message);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("argv"), PH_NOISY_CC);
	zephir_array_fetch_long(&_1, _0, 1, PH_NOISY | PH_READONLY, "dotphp/clibootstrap.zep", 43 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "未指定命令名称。(Usage: /usr/bin/php cli.php [命令名称])", "dotphp/clibootstrap.zep", 44);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcontrollerns", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(_2, _3);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("argv"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_array_fetch_long(&_5, _4, 1, PH_NOISY, "dotphp/clibootstrap.zep", 50 TSRMLS_CC);
	zephir_array_fast_append(_2, _5);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "\\DotPHP\\Utils\\StringUtil::ns", 0);
	ZEPHIR_INIT_VAR(cls_n);
	ZEPHIR_CALL_USER_FUNC_ARRAY(cls_n, &_6, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(cls_o);
	zephir_fetch_safe_class(_7, cls_n);
		_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(cls_o, _8);
	if (zephir_has_constructor(cls_o TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, cls_o, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, cls_o, "initialize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, cls_o, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

