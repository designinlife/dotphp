
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
#include "kernel/time.h"
#include "kernel/math.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/file.h"


/**
 * 通用日志管理类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Core_GenericLogger) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\Core, GenericLogger, dotphp, core_genericlogger, dotphp_base_dotbase_ce, dotphp_core_genericlogger_method_entry, 0);

	/**
	 * 模块名称。
	 * 
	 * @var string
	 */
	zend_declare_property_string(dotphp_core_genericlogger_ce, SL("_module"), "sys", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 输出模式。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_core_genericlogger_ce, SL("_mode"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 日志输出级别。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_core_genericlogger_ce, SL("_level"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 日志类型名称。
	 * 
	 * @var array
	 */
	zend_declare_property_null(dotphp_core_genericlogger_ce, SL("_types"), ZEND_ACC_PRIVATE TSRMLS_CC);

	dotphp_core_genericlogger_ce->create_object = zephir_init_properties_DotPHP_Core_GenericLogger;

	zend_class_implements(dotphp_core_genericlogger_ce TSRMLS_CC, 1, dotphp_interfaces_ilogger_ce);
	return SUCCESS;

}

/**
 * 设置日志模块名称。
 * 
 * @param string module
 * @return \DotPHP\Interfaces\ILogger
 */
PHP_METHOD(DotPHP_Core_GenericLogger, setModule) {

	zval *module_param = NULL;
	zval *module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_strval(module, module_param);


	zephir_update_property_this(this_ptr, SL("_module"), module TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 设置日志输出模式。(1,写入文件并输出到控制台 | 2,按天切分)
 * 
 * @param int mode
 * @return \DotPHP\Interfaces\ILogger
 */
PHP_METHOD(DotPHP_Core_GenericLogger, setMode) {

	zval *mode_param = NULL, *_0;
	int mode;

	zephir_fetch_params(0, 1, 0, &mode_param);

	mode = zephir_get_intval(mode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, mode);
	zephir_update_property_this(this_ptr, SL("_mode"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 设置日志输出级别。
 * 
 * @param int level
 * @return \DotPHP\Interfaces\ILogger
 */
PHP_METHOD(DotPHP_Core_GenericLogger, setLevel) {

	zval *level_param = NULL, *_0;
	int level;

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_this(this_ptr, SL("_level"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 调试。
 * 
 * @param var msg
 * @param array context
 * @return void
 */
PHP_METHOD(DotPHP_Core_GenericLogger, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *msg, *context_param = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &msg, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 500);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_log_write", NULL, 11, &_0, msg, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 错误。
 * 
 * @param var msg
 * @param array context
 * @param \Exception ex
 * @return void
 */
PHP_METHOD(DotPHP_Core_GenericLogger, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *msg, *context_param = NULL, *ex = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &msg, &context_param, &ex);

	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}
	if (!ex) {
		ex = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 200);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_log_write", NULL, 11, &_0, msg, context, ex);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 严重错误。
 * 
 * @param var msg
 * @param array context
 * @return void
 */
PHP_METHOD(DotPHP_Core_GenericLogger, fatal) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *msg, *context_param = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &msg, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 100);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_log_write", NULL, 11, &_0, msg, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 信息。
 * 
 * @param var msg
 * @param array context
 * @return void
 */
PHP_METHOD(DotPHP_Core_GenericLogger, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *msg, *context_param = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &msg, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 400);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_log_write", NULL, 11, &_0, msg, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 跟踪。
 * 
 * @param var msg
 * @param array context
 * @return void
 */
PHP_METHOD(DotPHP_Core_GenericLogger, trace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *msg, *context_param = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &msg, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 600);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_log_write", NULL, 11, &_0, msg, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 警告。
 * 
 * @param var msg
 * @param array context
 * @return void
 */
PHP_METHOD(DotPHP_Core_GenericLogger, warn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *msg, *context_param = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &msg, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 300);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_log_write", NULL, 11, &_0, msg, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 日志输出控制函数。
 * 
 * @param int level
 * @param mixed msg
 * @param array context
 * @param \Exception ex
 * @return boolean
 */
PHP_METHOD(DotPHP_Core_GenericLogger, _log_write) {

	HashTable *_14, *_17, *_20;
	HashPosition _13, _16, _19;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *file_pattern, *msg_pattern;
	zval *context = NULL, *reps1, *reps2;
	zval *level_param = NULL, *msg = NULL, *context_param = NULL, *ex = NULL, *_0, *_1, *date_str = NULL, *t, *micro = NULL, *file = NULL, *k = NULL, *v = NULL, _2 = zval_used_for_init, _4, *_6 = NULL, *_7, *_8, *_9 = NULL, *_10, *_11, *_12, **_15, **_18, **_21, *_22 = NULL, *_23 = NULL, *_24, *_25, *fp = NULL;
	int level, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &level_param, &msg, &context_param, &ex);

	level = zephir_get_intval(level_param);
	ZEPHIR_SEPARATE_PARAM(msg);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}
	if (!ex) {
		ex = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	if (ZEPHIR_LE_LONG(_0, 0)) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_level"), PH_NOISY_CC);
	if (ZEPHIR_LT_LONG(_1, level)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Ymd", 0);
	ZEPHIR_CALL_FUNCTION(&date_str, "date", &_3, 12, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(file_pattern);
	ZVAL_STRING(file_pattern, "%d.%m.log", 1);
	ZEPHIR_INIT_VAR(msg_pattern);
	ZVAL_STRING(msg_pattern, "%d %l [#%p] %m%n", 1);
	ZEPHIR_INIT_VAR(t);
	zephir_microtime(t, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "%03d", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, (((zephir_get_numberval(t) - zephir_floor(t TSRMLS_CC))) * (double) (1000)));
	ZEPHIR_CALL_FUNCTION(&micro, "sprintf", &_5, 13, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(reps1);
	zephir_create_array(reps1, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&reps1, SL("%d"), &date_str, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_module"), PH_NOISY_CC);
	zephir_fast_strtolower(_6, _7);
	zephir_array_update_string(&reps1, SL("%m"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(reps2);
	zephir_create_array(reps2, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "Y-m-d H:i:s,", micro);
	ZEPHIR_CALL_FUNCTION(&_9, "date", &_3, 12, _8, t);
	zephir_check_call_status();
	zephir_array_update_string(&reps2, SL("%d"), &_9, PH_COPY | PH_SEPARATE);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_types"), PH_NOISY_CC);
	zephir_array_fetch_long(&_11, _10, level, PH_NOISY | PH_READONLY, "dotphp/core/genericlogger.zep", 174 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "%-5s", 0);
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_5, 13, &_2, _11);
	zephir_check_call_status();
	zephir_array_update_string(&reps2, SL("%l"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_9, "posix_getpid", NULL, 14);
	zephir_check_call_status();
	zephir_array_update_string(&reps2, SL("%p"), &_9, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&reps2, SL("%m"), &msg, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
	zephir_array_update_string(&reps2, SL("%n"), &_6, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("bootstrap"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _12, "getlogdirectory", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(file);
	ZEPHIR_CONCAT_VSV(file, _9, "/", file_pattern);
	ZEPHIR_CPY_WRT(msg, msg_pattern);
	zephir_is_iterable(reps1, &_14, &_13, 0, 0, "dotphp/core/genericlogger.zep", 183);
	for (
	  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
	  ; zephir_hash_move_forward_ex(_14, &_13)
	) {
		ZEPHIR_GET_HMKEY(k, _14, _13);
		ZEPHIR_GET_HVALUE(v, _15);
		ZEPHIR_INIT_NVAR(_6);
		zephir_fast_str_replace(&_6, k, v, file TSRMLS_CC);
		ZEPHIR_CPY_WRT(file, _6);
	}
	zephir_is_iterable(reps2, &_17, &_16, 0, 0, "dotphp/core/genericlogger.zep", 191);
	for (
	  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
	  ; zephir_hash_move_forward_ex(_17, &_16)
	) {
		ZEPHIR_GET_HMKEY(k, _17, _16);
		ZEPHIR_GET_HVALUE(v, _18);
		ZEPHIR_INIT_NVAR(_6);
		zephir_fast_str_replace(&_6, k, v, msg TSRMLS_CC);
		ZEPHIR_CPY_WRT(msg, _6);
	}
	if (!(ZEPHIR_IS_EMPTY(context))) {
		zephir_is_iterable(context, &_20, &_19, 0, 0, "dotphp/core/genericlogger.zep", 195);
		for (
		  ; zephir_hash_get_current_data_ex(_20, (void**) &_21, &_19) == SUCCESS
		  ; zephir_hash_move_forward_ex(_20, &_19)
		) {
			ZEPHIR_GET_HMKEY(k, _20, _19);
			ZEPHIR_GET_HVALUE(v, _21);
			ZEPHIR_INIT_NVAR(_6);
			ZEPHIR_INIT_LNVAR(_22);
			ZEPHIR_CONCAT_SVS(_22, "{", k, "}");
			zephir_fast_str_replace(&_6, _22, v, msg TSRMLS_CC);
			ZEPHIR_CPY_WRT(msg, _6);
		}
	}
	if (zephir_is_true(ex)) {
		ZEPHIR_CALL_METHOD(&_23, ex, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
		ZEPHIR_INIT_LNVAR(_22);
		ZEPHIR_CONCAT_VV(_22, _23, _6);
		zephir_concat_self(&msg, _22 TSRMLS_CC);
	}
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	if (1 == (((int) (zephir_get_numberval(_24)) & 1))) {
		zend_print_zval(msg, 0);
	}
	_25 = zephir_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	if (2 == (((int) (zephir_get_numberval(_25)) & 2))) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "a", 0);
		ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 15, file, &_2);
		zephir_check_call_status();
		if (zephir_is_true(fp)) {
			zephir_fwrite(NULL, fp, msg TSRMLS_CC);
			zephir_fclose(fp TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(1);

}

static zend_object_value zephir_init_properties_DotPHP_Core_GenericLogger(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1;
		zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_types"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			zephir_create_array(_1, 8, 0 TSRMLS_CC);
			add_index_stringl(_1, 0, SL("OFF"), 1);
			add_index_stringl(_1, 100, SL("FATAL"), 1);
			add_index_stringl(_1, 200, SL("ERROR"), 1);
			add_index_stringl(_1, 300, SL("WARN"), 1);
			add_index_stringl(_1, 400, SL("INFO"), 1);
			add_index_stringl(_1, 500, SL("DEBUG"), 1);
			add_index_stringl(_1, 600, SL("TRACE"), 1);
			add_index_stringl(_1, 9999, SL("ALL"), 1);
			zephir_update_property_this(this_ptr, SL("_types"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

