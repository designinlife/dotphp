
extern zend_class_entry *dotphp_base_swoolebase_ce;

ZEPHIR_INIT_CLASS(DotPHP_Base_SwooleBase);

PHP_METHOD(DotPHP_Base_SwooleBase, __construct);
PHP_METHOD(DotPHP_Base_SwooleBase, initialize);
PHP_METHOD(DotPHP_Base_SwooleBase, before);
PHP_METHOD(DotPHP_Base_SwooleBase, after);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_base_swoolebase___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\SwooleBootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_base_swoolebase_method_entry) {
	PHP_ME(DotPHP_Base_SwooleBase, __construct, arginfo_dotphp_base_swoolebase___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Base_SwooleBase, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_SwooleBase, before, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_SwooleBase, after, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
