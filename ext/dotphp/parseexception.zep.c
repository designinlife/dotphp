
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


/**
 * 数据解析异常。
 * 
 * @author Lei Lee
 * @version 0.1a
 * @date 2015-09-09
 */
ZEPHIR_INIT_CLASS(DotPHP_ParseException) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP, ParseException, dotphp, parseexception, dotphp_baseexception_ce, NULL, 0);

	return SUCCESS;

}

