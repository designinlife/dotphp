
extern zend_class_entry *dotphp_interfaces_idb_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IDb);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_set, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, param, DotPHP\\Bean\\DbParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_exec, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_execute, 0, 0, 3)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_get, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_all, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_scalar, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_idb_changedb, 0, 0, 1)
	ZEND_ARG_INFO(0, db_name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_interfaces_idb_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, set, arginfo_dotphp_interfaces_idb_set)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, begin, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, commit, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, rollback, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, exec, arginfo_dotphp_interfaces_idb_exec)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, execute, arginfo_dotphp_interfaces_idb_execute)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, get, arginfo_dotphp_interfaces_idb_get)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, all, arginfo_dotphp_interfaces_idb_all)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, scalar, arginfo_dotphp_interfaces_idb_scalar)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, ping, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, changedb, arginfo_dotphp_interfaces_idb_changedb)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, connect, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, close, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IDb, isConnected, NULL)
	PHP_FE_END
};
