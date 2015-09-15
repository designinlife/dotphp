
extern zend_class_entry *dotphp_base_dotbase_ce;

ZEPHIR_INIT_CLASS(DotPHP_Base_DotBase);

PHP_METHOD(DotPHP_Base_DotBase, __construct);
PHP_METHOD(DotPHP_Base_DotBase, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_base_dotbase___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\AbstractBootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_base_dotbase_method_entry) {
	PHP_ME(DotPHP_Base_DotBase, __construct, arginfo_dotphp_base_dotbase___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Base_DotBase, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
