
extern zend_class_entry *dotphp_base_webcontrollerbase_ce;

ZEPHIR_INIT_CLASS(DotPHP_Base_WebControllerBase);

PHP_METHOD(DotPHP_Base_WebControllerBase, __construct);
PHP_METHOD(DotPHP_Base_WebControllerBase, __destruct);
PHP_METHOD(DotPHP_Base_WebControllerBase, isPostback);
PHP_METHOD(DotPHP_Base_WebControllerBase, initialize);
PHP_METHOD(DotPHP_Base_WebControllerBase, before);
PHP_METHOD(DotPHP_Base_WebControllerBase, after);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_base_webcontrollerbase___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\WebBootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_base_webcontrollerbase_method_entry) {
	PHP_ME(DotPHP_Base_WebControllerBase, __construct, arginfo_dotphp_base_webcontrollerbase___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Base_WebControllerBase, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(DotPHP_Base_WebControllerBase, isPostback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_WebControllerBase, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_WebControllerBase, before, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Base_WebControllerBase, after, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
