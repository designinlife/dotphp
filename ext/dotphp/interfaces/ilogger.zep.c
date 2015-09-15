
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP 日志接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_ILogger) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, ILogger, dotphp, interfaces_ilogger, dotphp_interfaces_ilogger_method_entry);

	return SUCCESS;

}

/**
 * 设置日志模块名称。
 * 
 * @param string module
 * @return \DotPHP\Interfaces\ILogger
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, setModule);

/**
 * 设置日志输出模式。(1,写入文件并输出到控制台 | 2,按天切分)
 * 
 * @param int mode
 * @return \DotPHP\Interfaces\ILogger
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, setMode);

/**
 * 设置日志输出级别。
 * 
 * @param int level
 * @return \DotPHP\Interfaces\ILogger
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, setLevel);

/**
 * 调试。
 * 
 * @param mixed msg
 * @param array context
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, debug);

/**
 * 错误。
 * 
 * @param mixed msg
 * @param array context
 * @param \Exception ex
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, error);

/**
 * 严重错误。
 * 
 * @param mixed msg
 * @param array context
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, fatal);

/**
 * 信息。
 * 
 * @param mixed msg
 * @param array context
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, info);

/**
 * 跟踪。
 * 
 * @param mixed msg
 * @param array context
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, trace);

/**
 * 警告。
 * 
 * @param mixed msg
 * @param array context
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ILogger, warn);

