
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP - 标准控制器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IController) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, IController, dotphp, interfaces_icontroller, dotphp_interfaces_icontroller_method_entry);

	return SUCCESS;

}

/**
 * 初始化事件。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IController, initialize);

/**
 * 在目标方法调用之前触发此事件。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IController, before);

/**
 * 在目标方法调用之后触发此事件。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IController, after);

