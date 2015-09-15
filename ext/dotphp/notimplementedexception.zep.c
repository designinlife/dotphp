
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
 * DotPHP 接口未实现异常。
 * 
 * @author Lei Lee
 * @version 0.1a
 * @date 2015-09-09
 */
ZEPHIR_INIT_CLASS(DotPHP_NotImplementedException) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP, NotImplementedException, dotphp, notimplementedexception, dotphp_baseexception_ce, NULL, 0);

	return SUCCESS;

}

