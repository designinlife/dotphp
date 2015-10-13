
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

	zend_declare_property_null(dotphp_bean_routemessage_ce, SL("data_item"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param string controller 控制器名称。
 * @param string method     方法名称。
 * @param array  parameters 参数集合。
 * @param array  data_item  命令数据集合。
 */
PHP_METHOD(DotPHP_Bean_RouteMessage, __construct) {

	zval *parameters = NULL, *data_item = NULL;
	zval *controller_param = NULL, *method_param = NULL, *parameters_param = NULL, *data_item_param = NULL;
	zval *controller = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &controller_param, &method_param, &parameters_param, &data_item_param);

	zephir_get_strval(controller, controller_param);
	zephir_get_strval(method, method_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}
	if (!data_item_param) {
		ZEPHIR_INIT_VAR(data_item);
		array_init(data_item);
	} else {
		zephir_get_arrval(data_item, data_item_param);
	}


	zephir_update_property_this(this_ptr, SL("controller"), controller TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("method"), method TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("parameters"), parameters TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data_item"), data_item TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取控制器名称。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_RouteMessage, getController) {

	

	RETURN_MEMBER(this_ptr, "controller");

}

/**
 * 获取方法名称。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_RouteMessage, getMethod) {

	

	RETURN_MEMBER(this_ptr, "method");

}

/**
 * 获取参数集合。
 * 
 * @return array|null
 */
PHP_METHOD(DotPHP_Bean_RouteMessage, getParameters) {

	

	RETURN_MEMBER(this_ptr, "parameters");

}

/**
 * 获取命令数据集合。
 * 
 * @return array|null
 */
PHP_METHOD(DotPHP_Bean_RouteMessage, getDataItem) {

	

	RETURN_MEMBER(this_ptr, "data_item");

}

