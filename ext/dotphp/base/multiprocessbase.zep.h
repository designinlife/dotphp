
extern zend_class_entry *dotphp_base_multiprocessbase_ce;

ZEPHIR_INIT_CLASS(DotPHP_Base_MultiProcessBase);

PHP_METHOD(DotPHP_Base_MultiProcessBase, initialize);
PHP_METHOD(DotPHP_Base_MultiProcessBase, execute);
PHP_METHOD(DotPHP_Base_MultiProcessBase, setWorkerNum);
PHP_METHOD(DotPHP_Base_MultiProcessBase, doTaskAction);
static zend_object_value zephir_init_properties_DotPHP_Base_MultiProcessBase(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_base_multiprocessbase_setworkernum, 0, 0, 1)
	ZEND_ARG_INFO(0, worker_num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_base_multiprocessbase_dotaskaction, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, worker, swoole_process, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_base_multiprocessbase_method_entry) {
	PHP_ME(DotPHP_Base_MultiProcessBase, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_MultiProcessBase, execute, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_MultiProcessBase, setWorkerNum, arginfo_dotphp_base_multiprocessbase_setworkernum, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_Base_MultiProcessBase, doTaskAction, arginfo_dotphp_base_multiprocessbase_dotaskaction, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
