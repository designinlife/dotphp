
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
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, begin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 73);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "BEGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "exec", NULL, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 提交事务。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 86);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "COMMIT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "exec", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 回滚事务。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_DB_DbPdo, rollback) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 99);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "ROLLBACK", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "exec", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 执行一条或多条 SQL 语句并返回影响的行数。
 * 
 * @param array|string sql
 * @return int
 * @throw \DotPHP\DbException
 */
PHP_METHOD(DotPHP_DB_DbPdo, exec) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS, affected = 0;
	zval *sql, *_0, *_1, *e = NULL, *v = NULL, **_4, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sql);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 118);
		return;
	}
	if (Z_TYPE_P(sql) == IS_ARRAY) {

		/* try_start_1: */

			zephir_is_iterable(sql, &_3, &_2, 0, 0, "dotphp/db/dbpdo.zep", 131);
			for (
			  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HVALUE(v, _4);
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_6, _5, "exec", NULL, 0, v);
				zephir_check_call_status_or_jump(try_end_1);
				affected += zephir_get_intval(_6);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, php_pdo_get_exception() TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_VAR(_7);
				object_init_ex(_7, dotphp_dbexception_ce);
				ZEPHIR_CALL_METHOD(&_6, e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8, e, "getcode", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 16, _6, _8, v);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7, "dotphp/db/dbpdo.zep", 132 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {

		/* try_start_2: */

			_5 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_8, _5, "exec", NULL, 0, sql);
			zephir_check_call_status_or_jump(try_end_1);
			affected += zephir_get_intval(_8);

		try_end_2:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, php_pdo_get_exception() TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_NVAR(_7);
				object_init_ex(_7, dotphp_dbexception_ce);
				ZEPHIR_CALL_METHOD(&_8, e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9, e, "getcode", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 16, _8, _9, sql);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7, "dotphp/db/dbpdo.zep", 138 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL;
	HashTable *_4;
	HashPosition _3;
	int type, ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *type_param = NULL, *_0, *_1, *d = NULL, *e = NULL, *sth = NULL, *key = NULL, *value = NULL, *_2, **_5, *_6, *_7, *_8 = NULL;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 159);
		return;
	}
	ZEPHIR_INIT_VAR(d);
	ZVAL_BOOL(d, 0);

	/* try_start_1: */

		_2 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&sth, _2, "prepare", NULL, 0, sql);
		zephir_check_call_status_or_jump(try_end_1);
		if (!(ZEPHIR_IS_EMPTY(params))) {
			zephir_is_iterable(params, &_4, &_3, 0, 0, "dotphp/db/dbpdo.zep", 177);
			for (
			  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HMKEY(key, _4, _3);
				ZEPHIR_GET_HVALUE(value, _5);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					zephir_array_fetch_long(&_6, value, 0, PH_NOISY | PH_READONLY, "dotphp/db/dbpdo.zep", 172 TSRMLS_CC);
					zephir_array_fetch_long(&_7, value, 1, PH_NOISY | PH_READONLY, "dotphp/db/dbpdo.zep", 172 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_8);
					ZVAL_LONG(_8, (1 + zephir_get_numberval(key)));
					ZEPHIR_CALL_METHOD(NULL, sth, "bindvalue", &_9, 0, _8, _6, _7);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					ZEPHIR_INIT_NVAR(_8);
					ZVAL_LONG(_8, (1 + zephir_get_numberval(key)));
					ZEPHIR_CALL_METHOD(NULL, sth, "bindvalue", &_10, 0, _8, value);
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
			zephir_throw_exception_debug(e, "dotphp/db/dbpdo.zep", 181 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	do {
		if (type == 1) {
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&d, _2, "lastinsertid", NULL, 0);
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
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 2);
			ZEPHIR_CALL_METHOD(&d, sth, "fetch", NULL, 0, _8);
			zephir_check_call_status();
			break;
		}
		if (type == 6) {
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 2);
			ZEPHIR_CALL_METHOD(&d, sth, "fetchall", NULL, 0, _8);
			zephir_check_call_status();
			break;
		}
		if (type == 7) {
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 0);
			ZEPHIR_CALL_METHOD(&d, sth, "fetchcolumn", NULL, 0, _8);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "当前 SQL 类型不被支持。", "dotphp/db/dbpdo.zep", 205);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *e = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {

		/* try_start_1: */

			_1 = zephir_fetch_nproperty_this(this_ptr, SL("dbo"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "SELECT 1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1, "query", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, php_pdo_get_exception() TSRMLS_CC)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_dbexception_ce, "检测到无效的 PDO 实例对象。", "dotphp/db/dbpdo.zep", 291);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *opts;
	zval *dsn = NULL;
	zval *_0, *_1, *e = NULL, *_2, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9, *_10 = NULL, *_11, *_12 = NULL, *_13, *_14 = NULL, *_15, *_16 = NULL, *_17 = NULL, *_18 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(dsn);
	ZVAL_STRING(dsn, "", 1);
	ZEPHIR_INIT_VAR(opts);
	array_init(opts);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "尚未设置 DB 连接参数。", "dotphp/db/dbpdo.zep", 306);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("is_connected"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(_1)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 2);
		zephir_array_update_long(&opts, 3, &_2, PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 314);
		zephir_array_update_long(&opts, 17, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 315);
		zephir_array_update_long(&opts, 0, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 316);
		zephir_array_update_long(&opts, 12, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 317);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 0);
		zephir_array_update_long(&opts, 8, &_3, PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 318);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 2);
		zephir_array_update_long(&opts, 19, &_4, PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 319);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, 0);
		zephir_array_update_long(&opts, 20, &_5, PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 320);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, _6, "getcharset", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SVS(_8, "SET NAMES `", _7, "`");
		zephir_array_update_long(&opts, 1002, &_8, PH_COPY | PH_SEPARATE, "dotphp/db/dbpdo.zep", 321);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "getunixsocket", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(_10)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_12, _11, "gethost", NULL, 0);
			zephir_check_call_status();
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14, _13, "getport", NULL, 0);
			zephir_check_call_status();
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_16, _15, "getdb", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_17);
			ZEPHIR_CONCAT_SVSVSVS(_17, "mysql:host=", _12, ";port=", _14, ";dbname=", _16, ";");
			zephir_get_strval(dsn, _17);
		} else {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_12, _11, "getunixsocket", NULL, 0);
			zephir_check_call_status();
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14, _13, "getdb", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_17);
			ZEPHIR_CONCAT_SVSVS(_17, "mysql:unix_socket=", _12, ";dbname=", _14, ";");
			zephir_get_strval(dsn, _17);
		}

		/* try_start_1: */

			ZEPHIR_INIT_VAR(_18);
			object_init_ex(_18, php_pdo_get_dbh_ce());
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_12, _11, "getuser", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14, _13, "getpass", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, _18, "__construct", NULL, 0, dsn, _12, _14, opts);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("dbo"), _18 TSRMLS_CC);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_is_instance_of(e, SL("DotPHP\\DB\\PDOException") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_INIT_NVAR(_18);
				object_init_ex(_18, dotphp_dbexception_ce);
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("dbParameter"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_12, _11, "gethost", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_SVS(_17, "数据库连接失败。(", _12, ")");
				ZEPHIR_CALL_METHOD(NULL, _18, "__construct", NULL, 16, _17);
				zephir_check_call_status();
				zephir_throw_exception_debug(_18, "dotphp/db/dbpdo.zep", 332 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_update_property_this(this_ptr, SL("is_connected"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	zephir_update_property_this(this_ptr, SL("is_connected"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * 指示是否已连接 DB 服务器？
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_DB_DbPdo, isConnected) {


	RETURN_MEMBER(this_ptr, "is_connected");

}

