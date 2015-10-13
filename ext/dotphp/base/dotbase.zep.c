
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
 * DotPHP 基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Base_DotBase) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Base, DotBase, dotphp, base_dotbase, dotphp_base_dotbase_method_entry, 0);

	/**
	 * AbstractBootstrap 上下文对象。
	 * 
	 * @var \DotPHP\AbstractBootstrap|\DotPHP\WebBootstrap|\DotPHP\SwooleBootstrap
	 */
	zend_declare_property_null(dotphp_base_dotbase_ce, SL("bootstrap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\AbstractBootstrap bootstrap
 */
PHP_METHOD(DotPHP_Base_DotBase, __construct) {

	zval *bootstrap;

	zephir_fetch_params(0, 1, 0, &bootstrap);



	zephir_update_property_this(this_ptr, SL("bootstrap"), bootstrap TSRMLS_CC);

}

/**
 * 析构函数。
 * 
 */
PHP_METHOD(DotPHP_Base_DotBase, __destruct) {

	

	zephir_unset_property(this_ptr, "bootstrap" TSRMLS_CC);

}

