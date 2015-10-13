
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * DotPHP - 基于 HTTP 的控制器基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Base_WebControllerBase) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\Base, WebControllerBase, dotphp, base_webcontrollerbase, dotphp_base_dotbase_ce, dotphp_base_webcontrollerbase_method_entry, 0);

	/**
	 * 是否 POST 请求方式？
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(dotphp_base_webcontrollerbase_ce, SL("_isPostback"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ITemplate 模板对象实例。
	 *
	 * @var \DotPHP\Interfaces\ITemplate
	 */
	zend_declare_property_null(dotphp_base_webcontrollerbase_ce, SL("tpl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * IDb 数据库对象实例。
	 *
	 * @var \DotPHP\Interfaces\IDb
	 */
	zend_declare_property_null(dotphp_base_webcontrollerbase_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ILogger 日志对象实例。
	 *
	 * @var \DotPHP\Interfaces\ILogger
	 */
	zend_declare_property_null(dotphp_base_webcontrollerbase_ce, SL("logger"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Redis 缓存对象实例。
	 * 
	 * @var \Redis
	 */
	zend_declare_property_null(dotphp_base_webcontrollerbase_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(dotphp_base_webcontrollerbase_ce TSRMLS_CC, 1, dotphp_interfaces_icontroller_ce);
	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\WebBootstrap bootstrap
 */
PHP_METHOD(DotPHP_Base_WebControllerBase, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *bootstrap, *_SERVER, *_1 = NULL, *_2, _3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &bootstrap);



	ZEPHIR_CALL_PARENT(NULL, dotphp_base_webcontrollerbase_ce, this_ptr, "__construct", &_0, 10, bootstrap);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "dotphp/base/webcontrollerbase.zep", 56 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "POST", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "strcmp", NULL, 1, &_3, _2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_4, 0)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_BOOL(_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_BOOL(_1, 0);
	}
	zephir_update_property_this(this_ptr, SL("_isPostback"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, bootstrap, "gettemplate", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("tpl"), _5 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, bootstrap, "getdb", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("db"), _6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, bootstrap, "getlogger", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("logger"), _7 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_8, bootstrap, "getcache", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("cache"), _8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 析构函数。
 *
 * @return void
 */
PHP_METHOD(DotPHP_Base_WebControllerBase, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, dotphp_base_webcontrollerbase_ce, this_ptr, "__destruct", &_0, 11);
	zephir_check_call_status();
	zephir_unset_property(this_ptr, "tpl" TSRMLS_CC);
	zephir_unset_property(this_ptr, "db" TSRMLS_CC);
	zephir_unset_property(this_ptr, "logger" TSRMLS_CC);
	zephir_unset_property(this_ptr, "cache" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 指示当前是否 POST 请求方式？
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_Base_WebControllerBase, isPostback) {

	

	RETURN_MEMBER(this_ptr, "_isPostback");

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_WebControllerBase, initialize) {

	


}

/**
 * 在目标方法调用之前触发此事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_WebControllerBase, before) {

	


}

/**
 * 在目标方法调用之后触发此事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_WebControllerBase, after) {

	


}

