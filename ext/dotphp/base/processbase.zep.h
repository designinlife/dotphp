
extern zend_class_entry *dotphp_base_processbase_ce;

ZEPHIR_INIT_CLASS(DotPHP_Base_ProcessBase);

PHP_METHOD(DotPHP_Base_ProcessBase, __construct);
PHP_METHOD(DotPHP_Base_ProcessBase, __destruct);
PHP_METHOD(DotPHP_Base_ProcessBase, initialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_base_processbase___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\CliBootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_base_processbase_method_entry) {
	PHP_ME(DotPHP_Base_ProcessBase, __construct, arginfo_dotphp_base_processbase___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Base_ProcessBase, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(DotPHP_Base_ProcessBase, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
