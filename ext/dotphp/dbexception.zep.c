
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * 数据库操作异常。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_DbException) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP, DbException, dotphp, dbexception, dotphp_baseexception_ce, dotphp_dbexception_method_entry, 0);

	/**
	 * 当前查询的 SQL 语句。
	 * 
	 * @var string
	 */
	zend_declare_property_null(dotphp_dbexception_ce, SL("sql"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param string message
 * @param int code
 * @param string sql
 * @param \Exception previous
 */
PHP_METHOD(DotPHP_DbException, __construct) {

	int code, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *code_param = NULL, *sql_param = NULL, *previous = NULL, *_0;
	zval *message = NULL, *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &message_param, &code_param, &sql_param, &previous);

	zephir_get_strval(sql, sql_param);
	if (!message_param) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	} else {
		zephir_get_strval(message, message_param);
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!previous) {
		previous = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, code);
	ZEPHIR_CALL_PARENT(NULL, dotphp_dbexception_ce, this_ptr, "__construct", NULL, 0, message, _0, previous);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("sql"), sql TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取当前查询的 SQL 语句。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_DbException, getSql) {

	

	RETURN_MEMBER(this_ptr, "sql");

}

/**
 * 打印输出。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_DbException, __toString) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sql"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VSV(return_value, _0, " | 查询: ", _1);
	return;

}

