
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"


/**
 * 共享内存表对象。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Core_ShareTable) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\Core, ShareTable, dotphp, core_sharetable, zephir_get_internal_ce(SS("swoole_table") TSRMLS_CC), dotphp_core_sharetable_method_entry, 0);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param int size 内存表最大行数。
 * @return void
 */
PHP_METHOD(DotPHP_Core_ShareTable, __construct) {

	zval *size_param = NULL, *_0;
	int size, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &size_param);

	if (!size_param) {
		size = 2147483648;
	} else {
		size = zephir_get_intval(size_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, size);
	ZEPHIR_CALL_PARENT(NULL, dotphp_core_sharetable_ce, this_ptr, "__construct", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置数据表列集合。
 *
 * @param array columns
 * @return \DotPHP\Core\ShareTable
 */
PHP_METHOD(DotPHP_Core_ShareTable, addColumns) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *columns_param = NULL, *v = NULL, **_2, *_3$$3, *_4$$3, *_5$$3;
	zval *columns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columns_param);

	zephir_get_arrval(columns, columns_param);


	zephir_is_iterable(columns, &_1, &_0, 0, 0, "dotphp/core/sharetable.zep", 36);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_array_fetch_long(&_3$$3, v, 0, PH_NOISY | PH_READONLY, "dotphp/core/sharetable.zep", 33 TSRMLS_CC);
		zephir_array_fetch_long(&_4$$3, v, 1, PH_NOISY | PH_READONLY, "dotphp/core/sharetable.zep", 33 TSRMLS_CC);
		zephir_array_fetch_long(&_5$$3, v, 2, PH_NOISY | PH_READONLY, "dotphp/core/sharetable.zep", 33 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "column", &_6, 0, _3$$3, _4$$3, _5$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

