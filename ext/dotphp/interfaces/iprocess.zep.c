
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP 命令行进程接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IProcess) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, IProcess, dotphp, interfaces_iprocess, dotphp_interfaces_iprocess_method_entry);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\CliBootstrap bootstrap 上下文对象。
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IProcess, __construct);

/**
 * 初始化事件。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IProcess, initialize);

/**
 * 执行任务。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IProcess, execute);

