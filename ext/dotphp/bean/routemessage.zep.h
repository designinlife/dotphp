
extern zend_class_entry *dotphp_bean_routemessage_ce;

ZEPHIR_INIT_CLASS(DotPHP_Bean_RouteMessage);

PHP_METHOD(DotPHP_Bean_RouteMessage, __construct);
PHP_METHOD(DotPHP_Bean_RouteMessage, getController);
PHP_METHOD(DotPHP_Bean_RouteMessage, getMethod);
PHP_METHOD(DotPHP_Bean_RouteMessage, getParameters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_routemessage___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_bean_routemessage_method_entry) {
	PHP_ME(DotPHP_Bean_RouteMessage, __construct, arginfo_dotphp_bean_routemessage___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Bean_RouteMessage, getController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_RouteMessage, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_RouteMessage, getParameters, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
