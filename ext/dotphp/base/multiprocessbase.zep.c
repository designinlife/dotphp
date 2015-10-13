
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * DotPHP 多进程基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Base_MultiProcessBase) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\Base, MultiProcessBase, dotphp, base_multiprocessbase, dotphp_base_processbase_ce, dotphp_base_multiprocessbase_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 子进程数量。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_base_multiprocessbase_ce, SL("child_worker_num"), 2, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 工作进程列表。
	 * 
	 * @var array
	 */
	zend_declare_property_null(dotphp_base_multiprocessbase_ce, SL("workers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	dotphp_base_multiprocessbase_ce->create_object = zephir_init_properties_DotPHP_Base_MultiProcessBase;
	return SUCCESS;

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_MultiProcessBase, initialize) {

	


}

/**
 * 执行任务。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Base_MultiProcessBase, execute) {

	zval *_4$$3 = NULL;
	zend_class_entry *_9;
	zend_bool _1;
	zval *p = NULL, *pid = NULL, *_0, *_3 = NULL, *_10, *_5$$3 = NULL, *_7$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, i = 0, _2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("child_worker_num"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_3, _0);
	_2 = 1;
	_1 = 0;
	if (ZEPHIR_GE_LONG(_3, _2)) {
		while (1) {
			if (_1) {
				_2++;
				if (!(ZEPHIR_GE_LONG(_3, _2))) {
					break;
				}
			} else {
				_1 = 1;
			}
			i = _2;
			ZEPHIR_INIT_NVAR(p);
			object_init_ex(p, zephir_get_internal_ce(SS("swoole_process") TSRMLS_CC));
			ZEPHIR_INIT_NVAR(_4$$3);
			zephir_create_array(_4$$3, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_4$$3, this_ptr);
			ZEPHIR_INIT_NVAR(_5$$3);
			ZVAL_STRING(_5$$3, "doTaskAction", 1);
			zephir_array_fast_append(_4$$3, _5$$3);
			ZEPHIR_CALL_METHOD(NULL, p, "__construct", &_6, 0, _4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_ZVAL_NREF(_7$$3);
			ZVAL_LONG(_7$$3, i);
			zephir_update_property_zval(p, SL("id"), _7$$3 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&pid, p, "start", &_8, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("workers"), pid, p TSRMLS_CC);
		}
	}
		_9 = zend_fetch_class(SL("swoole_process"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_BOOL(_10, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, _9, "wait", NULL, 0, _10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置启动的子进程数量。
 * 
 * @param int worker_num
 * @return void
 */
PHP_METHOD(DotPHP_Base_MultiProcessBase, setWorkerNum) {

	zval *worker_num_param = NULL, *_0;
	int worker_num;

	zephir_fetch_params(0, 1, 0, &worker_num_param);

	worker_num = zephir_get_intval(worker_num_param);


	if (worker_num < 2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(dotphp_argumentexception_ce, "子进程数量必须大于 1。", "dotphp/base/multiprocessbase.zep", 63);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, worker_num);
	zephir_update_property_this(this_ptr, SL("child_worker_num"), _0 TSRMLS_CC);

}

/**
 * 子进程启动后触发此事件。
 * 
 * @param \swoole_process worker
 * @return void
 */
PHP_METHOD(DotPHP_Base_MultiProcessBase, doTaskAction) {

}

static zend_object_value zephir_init_properties_DotPHP_Base_MultiProcessBase(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("workers"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("workers"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

