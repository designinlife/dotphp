
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP 路由解析器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IRouteParser) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, IRouteParser, dotphp, interfaces_irouteparser, dotphp_interfaces_irouteparser_method_entry);

	return SUCCESS;

}

/**
 * 解析路由并返回消息对象。
 * 
 * @return \DotPHP\Bean\RouteMessage
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IRouteParser, parse);

