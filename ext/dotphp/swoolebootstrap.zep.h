
extern zend_class_entry *dotphp_swoolebootstrap_ce;

ZEPHIR_INIT_CLASS(DotPHP_SwooleBootstrap);

PHP_METHOD(DotPHP_SwooleBootstrap, initialize);
PHP_METHOD(DotPHP_SwooleBootstrap, initializeComplete);
PHP_METHOD(DotPHP_SwooleBootstrap, route);
PHP_METHOD(DotPHP_SwooleBootstrap, validate);
PHP_METHOD(DotPHP_SwooleBootstrap, execute);
PHP_METHOD(DotPHP_SwooleBootstrap, getPort);
PHP_METHOD(DotPHP_SwooleBootstrap, setPort);
PHP_METHOD(DotPHP_SwooleBootstrap, getServerOptions);
PHP_METHOD(DotPHP_SwooleBootstrap, setServerOptions);
PHP_METHOD(DotPHP_SwooleBootstrap, setEventDispatcher);
static zend_object_value zephir_init_properties_DotPHP_SwooleBootstrap(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_swoolebootstrap_execute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route_message, DotPHP\\Bean\\RouteMessage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_swoolebootstrap_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_swoolebootstrap_setserveroptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, server_options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_swoolebootstrap_seteventdispatcher, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event_dispatcher, DotPHP\\Interfaces\\ISwooleEventDispatcher, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_swoolebootstrap_method_entry) {
	PHP_ME(DotPHP_SwooleBootstrap, initialize, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_SwooleBootstrap, initializeComplete, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_SwooleBootstrap, route, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_SwooleBootstrap, validate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_SwooleBootstrap, execute, arginfo_dotphp_swoolebootstrap_execute, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_SwooleBootstrap, getPort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_SwooleBootstrap, setPort, arginfo_dotphp_swoolebootstrap_setport, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_SwooleBootstrap, getServerOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_SwooleBootstrap, setServerOptions, arginfo_dotphp_swoolebootstrap_setserveroptions, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_SwooleBootstrap, setEventDispatcher, arginfo_dotphp_swoolebootstrap_seteventdispatcher, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
