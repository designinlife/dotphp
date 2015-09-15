
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
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * DotPHP 消息协议类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Bean_AbstractResponseMessage) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Bean, AbstractResponseMessage, dotphp, bean_abstractresponsemessage, dotphp_bean_abstractresponsemessage_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_long(dotphp_bean_abstractresponsemessage_ce, SL("_timestamp"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(dotphp_bean_abstractresponsemessage_ce, SL("_module"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(dotphp_bean_abstractresponsemessage_ce, SL("_method"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(dotphp_bean_abstractresponsemessage_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(dotphp_bean_abstractresponsemessage_ce, SL("_errno"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(dotphp_bean_abstractresponsemessage_ce, SL("_errstr"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(dotphp_bean_abstractresponsemessage_ce, SL("_op_code"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(dotphp_bean_abstractresponsemessage_ce, SL("_trace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 获取错误代码。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getErrorCode) {


	RETURN_MEMBER(this_ptr, "_errno");

}

/**
 * 设置错误代码。
 * 
 * @param int errno
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setErrorCode) {

	zval *errno_param = NULL, *_0;
	int errno;

	zephir_fetch_params(0, 1, 0, &errno_param);

	errno = zephir_get_intval(errno_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, errno);
	zephir_update_property_this(this_ptr, SL("_errno"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取错误消息。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getErrorMessage) {


	RETURN_MEMBER(this_ptr, "_errstr");

}

/**
 * 设置错误消息。
 * 
 * @param string errstr
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setErrorMessage) {

	zval *errstr_param = NULL;
	zval *errstr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &errstr_param);

	zephir_get_strval(errstr, errstr_param);


	zephir_update_property_this(this_ptr, SL("_errstr"), errstr TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取异常堆栈消息。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getTrace) {


	RETURN_MEMBER(this_ptr, "_trace");

}

/**
 * 设置异常堆栈消息。
 * 
 * @param string errstr
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setTrace) {

	zval *trace_param = NULL;
	zval *trace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &trace_param);

	zephir_get_strval(trace, trace_param);


	zephir_update_property_this(this_ptr, SL("_trace"), trace TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取模块编号。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getModule) {


	RETURN_MEMBER(this_ptr, "_module");

}

/**
 * 设置模块编号。
 * 
 * @param int module
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setModule) {

	zval *module_param = NULL, *_0;
	int module;

	zephir_fetch_params(0, 1, 0, &module_param);

	module = zephir_get_intval(module_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, module);
	zephir_update_property_this(this_ptr, SL("_module"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取接口编号。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getMethod) {


	RETURN_MEMBER(this_ptr, "_method");

}

/**
 * 设置接口编号。
 * 
 * @param int method
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setMethod) {

	zval *method_param = NULL, *_0;
	int method;

	zephir_fetch_params(0, 1, 0, &method_param);

	method = zephir_get_intval(method_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, method);
	zephir_update_property_this(this_ptr, SL("_method"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取数据对象。
 * 
 * @return mixed
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getData) {


	RETURN_MEMBER(this_ptr, "_data");

}

/**
 * 设置数据对象。
 * 
 * @param mixed data
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setData) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);



	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取操作代码。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getOpCode) {


	RETURN_MEMBER(this_ptr, "_op_code");

}

/**
 * 设置操作代码。
 * 
 * @param int op_code
 * @return \DotPHP\Bean\AbstractResponseMessage
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setOpCode) {

	zval *op_code_param = NULL, *_0;
	int op_code;

	zephir_fetch_params(0, 1, 0, &op_code_param);

	op_code = zephir_get_intval(op_code_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, op_code);
	zephir_update_property_this(this_ptr, SL("_op_code"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 数据编码。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, encode) {

}

