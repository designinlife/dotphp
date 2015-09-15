
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * 路由解析结果对象。
 * 
 * @author Lei Lee
 * @version 0.1a
 * @date 2015-09-09
 */
ZEPHIR_INIT_CLASS(DotPHP_Bean_RouteMessage) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Bean, RouteMessage, dotphp, bean_routemessage, dotphp_bean_routemessage_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(dotphp_bean_routemessage_ce, SL("controller"), "Index", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(dotphp_bean_routemessage_ce, SL("method"), "defaults", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(dotphp_bean_routemessage_ce, SL("parameters"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(DotPHP_Bean_RouteMessage, __construct) {

	zval *parameters = NULL;
	zval *controller_param = NULL, *method_param = NULL, *parameters_param = NULL;
	zval *controller = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &controller_param, &method_param, &parameters_param);

	zephir_get_strval(controller, controller_param);
	zephir_get_strval(method, method_param);
	if (!parameters_param) {
	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	zephir_update_property_this(this_ptr, SL("controller"), controller TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("method"), method TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("parameters"), parameters TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(DotPHP_Bean_RouteMessage, getController) {


	RETURN_MEMBER(this_ptr, "controller");

}

PHP_METHOD(DotPHP_Bean_RouteMessage, getMethod) {


	RETURN_MEMBER(this_ptr, "method");

}

PHP_METHOD(DotPHP_Bean_RouteMessage, getParameters) {


	RETURN_MEMBER(this_ptr, "parameters");

}

