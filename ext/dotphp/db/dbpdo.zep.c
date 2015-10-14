
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/concat.h"


/**
 * DotPHP 数据库操作类。(基于 PDO 扩展)
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_DB_DbPdo) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\DB, DbPdo, dotphp, db_dbpdo, dotphp_base_dotbase_ce, dotphp_db_dbpdo_method_entry, 0);

	/**
	 * 数据库参数对象。
	 * 
	 * @var \DotPHP\Bean\DbParameter
	 */
	zend_declare_property_null(dotphp_db_dbpdo_ce, SL("dbParameter"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 是否已连接 DB 服务器？
	 * 
	 * @var boolean
	 */
	zend_declare_property_bool(dotphp_db_dbpdo_ce, SL("is_connected"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * PDO 对象。
	 * 
	 * @var \PDO
	 */
	zend_declare_property_null(dotphp_db_dbpdo_ce, SL("dbo"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 事务计数。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_db_dbpdo_ce, SL("transactions"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(dotphp_db_dbpdo_ce TSRMLS_CC, 1, dotphp_interfaces_idb_ce);
	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\AbstractBootstrap bootstrap
 */
PHP_METHOD(DotPHP_DB_DbPdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *bootstrap;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootstrap);



	ZEPHIR_CALL_PARENT(NULL, dotphp_db_dbpdo_ce, this_ptr, "__construct", &_0, 10, bootstrap);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 析构函数。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, __destruct) {

	

	zephir_unset_property(this_ptr, "dbParameter" TSRMLS_CC);

}

/**
 * 设置 DB 参数。
 * 
 * @param \DotPHP\Bean\DbParameter param
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, set) {

	zval *param;

	zephir_fetch_params(0, 1, 0, &param);



	zephir_update_property_this(this_ptr, SL("dbParameter"), param TSRMLS_CC);

}

/**
 * 开启事务。
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_DB_DbPdo, begin) {

	zval *_0, *_1, *_2, *_3$$5, *_4$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 80);
		return;
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactions") TSRMLS_CC));
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("transactions"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_2, 1)) {
		_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4$$5);
		ZVAL_STRING(_4$$5, "BEGIN", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3$$5, "exec", NULL, 0, _4$$5);
		zephir_check_temp_parameter(_4$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 提交事务。
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_DB_DbPdo, commit) {

	zval *_0, *_1, *_2$$4, *_3$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 101);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("transactions"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_1, 1)) {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "COMMIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "exec", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactions") TSRMLS_CC));
		RETURN_MM_BOOL(1);
	} else {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactions") TSRMLS_CC));
	}
	RETURN_MM_BOOL(0);

}

/**
 * 回滚事务。
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_DB_DbPdo, rollback) {

	zval *_0, *_1, *_2$$4, *_3$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 124);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("transactions"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_1, 1)) {
		ZEPHIR_INIT_ZVAL_NREF(_2$$4);
		ZVAL_LONG(_2$$4, 0);
		zephir_update_property_this(this_ptr, SL("transactions"), _2$$4 TSRMLS_CC);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "ROLLBACK", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "exec", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactions") TSRMLS_CC));
	}
	RETURN_MM_BOOL(0);

}

/**
 * 执行一条或多条 SQL 语句并返回影响的行数。
 * 
 * @param array|string sql
 * @return int
 * @throw \DotPHP\DbException
 */
PHP_METHOD(DotPHP_DB_DbPdo, exec) {

	HashTable *_3$$6;
	HashPosition _2$$6;
	int ZEPHIR_LAST_CALL_STATUS, affected;
	zval *sql, *_0, *_1, *e = NULL, *v$$5 = NULL, **_4$$6, *_5$$7, *_6$$7 = NULL, *_7$$8, *_8$$8 = NULL, *_9$$8 = NULL, *_10$$10, *_11$$10 = NULL, *_12$$11, *_13$$11 = NULL, *_14$$11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sql);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 153);
		return;
	}
	affected = 0;
	if (Z_TYPE_P(sql) == IS_ARRAY) {

		/* try_start_1: */

			zephir_is_iterable(sql, &_3$$6, &_2$$6, 0, 0, "dotphp/db/dbpdo.zep", 166);
			for (
			  ; zephir_hash_get_current_data_ex(_3$$6, (void**) &_4$$6, &_2$$6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3$$6, &_2$$6)
			) {
				ZEPHIR_GET_HVALUE(v$$5, _4$$6);
				_5$$7 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_6$$7, _5$$7, "exec", NULL, 0, v$$5);
				zephir_check_call_status_or_jump(try_end_1);
				affected += zephir_get_intval(_6$$7);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, php_pdo_get_exception() TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_VAR(_7$$8);
				object_init_ex(_7$$8, dotphp_dbexception_ce);
				ZEPHIR_CALL_METHOD(&_8$$8, e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$8, e, "getcode", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _7$$8, "__construct", NULL, 20, _8$$8, _9$$8, v$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$8, "dotphp/db/dbpdo.zep", 167 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {

		/* try_start_2: */

			_10$$10 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_11$$10, _10$$10, "exec", NULL, 0, sql);
			zephir_check_call_status_or_jump(try_end_1);
			affected += zephir_get_intval(_11$$10);

		try_end_2:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, php_pdo_get_exception() TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_VAR(_12$$11);
				object_init_ex(_12$$11, dotphp_dbexception_ce);
				ZEPHIR_CALL_METHOD(&_13$$11, e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_14$$11, e, "getcode", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _12$$11, "__construct", NULL, 20, _13$$11, _14$$11, sql);
				zephir_check_call_status();
				zephir_throw_exception_debug(_12$$11, "dotphp/db/dbpdo.zep", 173 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_LONG(affected);

}

/**
 * 执行 INSERT/UPDATE/DELETE 语句并返回影响的行数或 AUTO_INCREMENT 自增值。
 * 
 * @param string sql    指定 SQL 语句。
 * @param array  params 指定参数集合。
 * @param int    type   指定 SQL 查询类型。(注: 请务必使用 \DotPHP\Dot::SQL_TYPE_* 常量定义。)
 * @return var
 */
PHP_METHOD(DotPHP_DB_DbPdo, execute) {

	HashTable *_4$$6;
	HashPosition _3$$6;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL;
	int type, ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *type_param = NULL, *_0, *_1, *d = NULL, *e = NULL, *sth = NULL, *key = NULL, *value = NULL, *_2$$5, **_5$$6, *_6$$8, *_7$$8, *_8$$8 = NULL, *_10$$9 = NULL, *_12$$11, *_13$$14, *_14$$16, *_15$$18;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sql_param, &params_param, &type_param);

	zephir_get_strval(sql, sql_param);
	zephir_get_arrval(params, params_param);
	type = zephir_get_intval(type_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 194);
		return;
	}
	ZEPHIR_INIT_VAR(d);
	ZVAL_BOOL(d, 0);

	/* try_start_1: */

		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&sth, _2$$5, "prepare", NULL, 0, sql);
		zephir_check_call_status_or_jump(try_end_1);
		if (!(ZEPHIR_IS_EMPTY(params))) {
			zephir_is_iterable(params, &_4$$6, &_3$$6, 0, 0, "dotphp/db/dbpdo.zep", 212);
			for (
			  ; zephir_hash_get_current_data_ex(_4$$6, (void**) &_5$$6, &_3$$6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4$$6, &_3$$6)
			) {
				ZEPHIR_GET_HMKEY(key, _4$$6, _3$$6);
				ZEPHIR_GET_HVALUE(value, _5$$6);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					zephir_array_fetch_long(&_6$$8, value, 0, PH_NOISY | PH_READONLY, "dotphp/db/dbpdo.zep", 207 TSRMLS_CC);
					zephir_array_fetch_long(&_7$$8, value, 1, PH_NOISY | PH_READONLY, "dotphp/db/dbpdo.zep", 207 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_8$$8);
					ZVAL_LONG(_8$$8, (1 + zephir_get_numberval(key)));
					ZEPHIR_CALL_METHOD(NULL, sth, "bindvalue", &_9, 0, _8$$8, _6$$8, _7$$8);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					ZEPHIR_INIT_NVAR(_10$$9);
					ZVAL_LONG(_10$$9, (1 + zephir_get_numberval(key)));
					ZEPHIR_CALL_METHOD(NULL, sth, "bindvalue", &_11, 0, _10$$9, value);
					zephir_check_call_status_or_jump(try_end_1);
				}
			}
		}
		ZEPHIR_CALL_METHOD(NULL, sth, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_is_instance_of(e, SL("DotPHP\\DB\\PDOException") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			zephir_throw_exception_debug(e, "dotphp/db/dbpdo.zep", 216 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	do {
		if (type == 1) {
			_12$$11 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&d, _12$$11, "lastinsertid", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (type == 2 || type == 3) {
			ZEPHIR_CALL_METHOD(&d, sth, "rowcount", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (type == 4) {
			ZEPHIR_INIT_NVAR(d);
			ZVAL_BOOL(d, 1);
			break;
		}
		if (type == 5) {
			ZEPHIR_INIT_VAR(_13$$14);
			ZVAL_LONG(_13$$14, 2);
			ZEPHIR_CALL_METHOD(&d, sth, "fetch", NULL, 0, _13$$14);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(d)) {
				ZEPHIR_INIT_NVAR(d);
				ZVAL_BOOL(d, 0);
			}
			break;
		}
		if (type == 6) {
			ZEPHIR_INIT_VAR(_14$$16);
			ZVAL_LONG(_14$$16, 2);
			ZEPHIR_CALL_METHOD(&d, sth, "fetchall", NULL, 0, _14$$16);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(d)) {
				ZEPHIR_INIT_NVAR(d);
				ZVAL_BOOL(d, 0);
			}
			break;
		}
		if (type == 7) {
			ZEPHIR_INIT_VAR(_15$$18);
			ZVAL_LONG(_15$$18, 0);
			ZEPHIR_CALL_METHOD(&d, sth, "fetchcolumn", NULL, 0, _15$$18);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "当前 SQL 类型不被支持。", "dotphp/db/dbpdo.zep", 248);
		return;
	} while(0);

	ZEPHIR_CALL_METHOD(NULL, sth, "closecursor", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(d);

}

/**
 * 查询单行记录。
 * 
 * @param string sql
 * @param array  params
 * @return array
 */
PHP_METHOD(DotPHP_DB_DbPdo, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *d = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 5);
	ZEPHIR_CALL_METHOD(&d, this_ptr, "execute", NULL, 0, sql, params, _0);
	zephir_check_call_status();
	RETURN_CCTOR(d);

}

/**
 * 查询全部记录。
 * 
 * @param string sql
 * @param array  params
 * @return array
 */
PHP_METHOD(DotPHP_DB_DbPdo, all) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *d = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 6);
	ZEPHIR_CALL_METHOD(&d, this_ptr, "execute", NULL, 0, sql, params, _0);
	zephir_check_call_status();
	RETURN_CCTOR(d);

}

/**
 * 查询单行、单列数据。
 * 
 * @param string sql
 * @param array  params
 * @return var
 */
PHP_METHOD(DotPHP_DB_DbPdo, scalar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *d = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 7);
	ZEPHIR_CALL_METHOD(&d, this_ptr, "execute", NULL, 0, sql, params, _0);
	zephir_check_call_status();
	RETURN_CCTOR(d);

}

/**
 * PING 数据库服务器。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, ping) {

	zval *_0, *e$$3 = NULL, *_1$$4, *_2$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {

		/* try_start_1: */

			_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2$$4);
			ZVAL_STRING(_2$$4, "SELECT 1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "query", NULL, 0, _2$$4);
			zephir_check_temp_parameter(_2$$4);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e$$3, EG(exception));
			if (zephir_instance_of_ev(e$$3, php_pdo_get_exception() TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
				zephir_check_call_status();
			}
		}
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 切换数据库上下文。
 * 
 * @param string db_name
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, changedb) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *db_name_param = NULL, *_0, *_1, *_2;
	zval *db_name = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &db_name_param);

	zephir_get_strval(db_name, db_name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 334);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "USE `", db_name, "`");
	ZEPHIR_CALL_METHOD(NULL, _2, "exec", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 连接数据库服务器。
 * 
 * @return void
 * @throw \DotPHP\ArgumentException
 * @throw \DotPHP\DbException
 */
PHP_METHOD(DotPHP_DB_DbPdo, connect) {

	zval *opts$$4;
	zval *dsn$$4 = NULL;
	zval *_0, *_1, *e$$4 = NULL, *_2$$4, *_3$$4, *_4$$4, *_5$$4, *_6$$4, *_7$$4 = NULL, *_8$$4, *_9$$4, *_10$$4 = NULL, *_11$$5, *_12$$5 = NULL, *_13$$5, *_14$$5 = NULL, *_15$$5, *_16$$5 = NULL, *_17$$5, *_18$$6, *_19$$6 = NULL, *_20$$6, *_21$$6 = NULL, *_22$$6, *_23$$7, *_24$$7, *_25$$7 = NULL, *_26$$7, *_27$$7 = NULL, *_28$$8, *_29$$8, *_30$$8 = NULL, *_31$$8;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "尚未设置 DB 连接参数。", "dotphp/db/dbpdo.zep", 349);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(_1)) {
		ZEPHIR_INIT_VAR(dsn$$4);
		ZVAL_EMPTY_STRING(dsn$$4);
		ZEPHIR_INIT_VAR(opts$$4);
		array_init(opts$$4);
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_LONG(_2$$4, 2);
		zephir_array_update_long(&opts$$4, 3, &_2$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_long(&opts$$4, 17, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_long(&opts$$4, 0, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_long(&opts$$4, 12, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, 0);
		zephir_array_update_long(&opts$$4, 8, &_3$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_LONG(_4$$4, 2);
		zephir_array_update_long(&opts$$4, 19, &_4$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_LONG(_5$$4, 0);
		zephir_array_update_long(&opts$$4, 20, &_5$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7$$4, _6$$4, "getcharset", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SVS(_8$$4, "SET NAMES `", _7$$4, "`");
		zephir_array_update_long(&opts$$4, 1002, &_8$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10$$4, _9$$4, "getunixsocket", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(_10$$4)) {
			_11$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_12$$5, _11$$5, "gethost", NULL, 0);
			zephir_check_call_status();
			_13$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14$$5, _13$$5, "getport", NULL, 0);
			zephir_check_call_status();
			_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_16$$5, _15$$5, "getdb", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_17$$5);
			ZEPHIR_CONCAT_SVSVSVS(_17$$5, "mysql:host=", _12$$5, ";port=", _14$$5, ";dbname=", _16$$5, ";");
			zephir_get_strval(dsn$$4, _17$$5);
		} else {
			_18$$6 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_19$$6, _18$$6, "getunixsocket", NULL, 0);
			zephir_check_call_status();
			_20$$6 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_21$$6, _20$$6, "getdb", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_22$$6);
			ZEPHIR_CONCAT_SVSVS(_22$$6, "mysql:unix_socket=", _19$$6, ";dbname=", _21$$6, ";");
			zephir_get_strval(dsn$$4, _22$$6);
		}

		/* try_start_1: */

			ZEPHIR_INIT_VAR(_23$$7);
			object_init_ex(_23$$7, php_pdo_get_dbh_ce());
			_24$$7 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_25$$7, _24$$7, "getuser", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			_26$$7 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_27$$7, _26$$7, "getpass", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, _23$$7, "__construct", NULL, 0, dsn$$4, _25$$7, _27$$7, opts$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("dbo"), _23$$7 TSRMLS_CC);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e$$4, EG(exception));
			if (zephir_is_instance_of(e$$4, SL("DotPHP\\DB\\PDOException") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_VAR(_28$$8);
				object_init_ex(_28$$8, dotphp_dbexception_ce);
				_29$$8 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_30$$8, _29$$8, "gethost", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_31$$8);
				ZEPHIR_CONCAT_SVS(_31$$8, "数据库连接失败。(", _30$$8, ")");
				ZEPHIR_CALL_METHOD(NULL, _28$$8, "__construct", NULL, 20, _31$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(_28$$8, "dotphp/db/dbpdo.zep", 375 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (1) {
			zephir_update_property_this(this_ptr, SL("is_connected"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("is_connected"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 关闭数据库连接。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, close) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_update_property_this(this_ptr, SL("dbo"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("is_connected"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("is_connected"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * 指示是否已连接 DB 服务器？
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_DB_DbPdo, isConnected) {

	

	RETURN_MEMBER(this_ptr, "is_connected");

}

