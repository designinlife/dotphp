
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


/**
 * DotPHP - 基于 Swoole Socket 的控制器基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Base_SwooleBase) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\Base, SwooleBase, dotphp, base_swoolebase, dotphp_base_dotbase_ce, dotphp_base_swoolebase_method_entry, 0);

	zend_class_implements(dotphp_base_swoolebase_ce TSRMLS_CC, 1, dotphp_interfaces_icontroller_ce);
	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\SwooleBootstrap bootstrap
 */
PHP_METHOD(DotPHP_Base_SwooleBase, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *bootstrap;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootstrap);



	ZEPHIR_CALL_PARENT(NULL, dotphp_base_swoolebase_ce, this_ptr, "__construct", &_0, 4, bootstrap);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_SwooleBase, initialize) {



}

/**
 * 在目标方法调用之前触发此事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_SwooleBase, before) {



}

/**
 * 在目标方法调用之后触发此事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_SwooleBase, after) {



}

