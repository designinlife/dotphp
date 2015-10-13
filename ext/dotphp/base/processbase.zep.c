
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * DotPHP 进程基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Base_ProcessBase) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Base, ProcessBase, dotphp, base_processbase, dotphp_base_processbase_method_entry, 0);

	/**
	 * CliBootstrap 上下文对象。
	 * 
	 * @var \DotPHP\CliBootstrap
	 */
	zend_declare_property_null(dotphp_base_processbase_ce, SL("bootstrap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\CliBootstrap bootstrap
 */
PHP_METHOD(DotPHP_Base_ProcessBase, __construct) {

	zval *bootstrap;

	zephir_fetch_params(0, 1, 0, &bootstrap);



	zephir_update_property_this(this_ptr, SL("bootstrap"), bootstrap TSRMLS_CC);

}

/**
 * 析构函数。
 * 
 */
PHP_METHOD(DotPHP_Base_ProcessBase, __destruct) {

	

	zephir_unset_property(this_ptr, "bootstrap" TSRMLS_CC);

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_ProcessBase, initialize) {

	


}

