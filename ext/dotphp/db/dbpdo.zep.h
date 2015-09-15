
extern zend_class_entry *dotphp_db_dbpdo_ce;

ZEPHIR_INIT_CLASS(DotPHP_DB_DbPdo);

PHP_METHOD(DotPHP_DB_DbPdo, __construct);
PHP_METHOD(DotPHP_DB_DbPdo, __destruct);
PHP_METHOD(DotPHP_DB_DbPdo, set);
PHP_METHOD(DotPHP_DB_DbPdo, begin);
PHP_METHOD(DotPHP_DB_DbPdo, commit);
PHP_METHOD(DotPHP_DB_DbPdo, rollback);
PHP_METHOD(DotPHP_DB_DbPdo, exec);
PHP_METHOD(DotPHP_DB_DbPdo, execute);
PHP_METHOD(DotPHP_DB_DbPdo, get);
PHP_METHOD(DotPHP_DB_DbPdo, all);
PHP_METHOD(DotPHP_DB_DbPdo, scalar);
PHP_METHOD(DotPHP_DB_DbPdo, ping);
PHP_METHOD(DotPHP_DB_DbPdo, changedb);
PHP_METHOD(DotPHP_DB_DbPdo, connect);
PHP_METHOD(DotPHP_DB_DbPdo, close);
PHP_METHOD(DotPHP_DB_DbPdo, isConnected);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\AbstractBootstrap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_set, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, param, DotPHP\\Bean\\DbParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_exec, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_execute, 0, 0, 3)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_get, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_all, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_scalar, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_db_dbpdo_changedb, 0, 0, 1)
	ZEND_ARG_INFO(0, db_name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_db_dbpdo_method_entry) {
	PHP_ME(DotPHP_DB_DbPdo, __construct, arginfo_dotphp_db_dbpdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_DB_DbPdo, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(DotPHP_DB_DbPdo, set, arginfo_dotphp_db_dbpdo_set, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, exec, arginfo_dotphp_db_dbpdo_exec, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, execute, arginfo_dotphp_db_dbpdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, get, arginfo_dotphp_db_dbpdo_get, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, all, arginfo_dotphp_db_dbpdo_all, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, scalar, arginfo_dotphp_db_dbpdo_scalar, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, ping, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, changedb, arginfo_dotphp_db_dbpdo_changedb, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DB_DbPdo, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
