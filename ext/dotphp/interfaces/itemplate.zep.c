
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP 模板引擎接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_ITemplate) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, ITemplate, dotphp, interfaces_itemplate, dotphp_interfaces_itemplate_method_entry);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\WebBootstrap bootstrap 上下文对象。
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ITemplate, __construct);

/**
 * 模板变量赋值。
 * 
 * @param string key
 * @param mixed value
 * @return \DotPHP\Interfaces\ITemplate
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ITemplate, assign);

/**
 * 输出模板内容。
 * 
 * @param string tpl_file 模板文件名称。
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ITemplate, display);

