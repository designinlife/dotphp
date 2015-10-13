
extern zend_class_entry *dotphp_clibootstrap_ce;

ZEPHIR_INIT_CLASS(DotPHP_CliBootstrap);

PHP_METHOD(DotPHP_CliBootstrap, initializeComplete);
PHP_METHOD(DotPHP_CliBootstrap, route);
PHP_METHOD(DotPHP_CliBootstrap, validate);
PHP_METHOD(DotPHP_CliBootstrap, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_clibootstrap_execute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route_message, DotPHP\\Bean\\RouteMessage, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_clibootstrap_method_entry) {
	PHP_ME(DotPHP_CliBootstrap, initializeComplete, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_CliBootstrap, route, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_CliBootstrap, validate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_CliBootstrap, execute, arginfo_dotphp_clibootstrap_execute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
