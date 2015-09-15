
extern zend_class_entry *dotphp_webbootstrap_ce;

ZEPHIR_INIT_CLASS(DotPHP_WebBootstrap);

PHP_METHOD(DotPHP_WebBootstrap, initialize);
PHP_METHOD(DotPHP_WebBootstrap, initializeComplete);
PHP_METHOD(DotPHP_WebBootstrap, route);
PHP_METHOD(DotPHP_WebBootstrap, validate);
PHP_METHOD(DotPHP_WebBootstrap, execute);
PHP_METHOD(DotPHP_WebBootstrap, getTemplateDirectory);
PHP_METHOD(DotPHP_WebBootstrap, setTemplateDirectory);
PHP_METHOD(DotPHP_WebBootstrap, getTemplateCacheDirectory);
PHP_METHOD(DotPHP_WebBootstrap, setTemplateCacheDirectory);
PHP_METHOD(DotPHP_WebBootstrap, setTemplateClass);
PHP_METHOD(DotPHP_WebBootstrap, getTemplate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_webbootstrap_execute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route_message, DotPHP\\Bean\\RouteMessage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_webbootstrap_settemplatedirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_webbootstrap_settemplatecachedirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_webbootstrap_settemplateclass, 0, 0, 1)
	ZEND_ARG_INFO(0, cls_name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_webbootstrap_method_entry) {
	PHP_ME(DotPHP_WebBootstrap, initialize, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_WebBootstrap, initializeComplete, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_WebBootstrap, route, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_WebBootstrap, validate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_WebBootstrap, execute, arginfo_dotphp_webbootstrap_execute, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_WebBootstrap, getTemplateDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_WebBootstrap, setTemplateDirectory, arginfo_dotphp_webbootstrap_settemplatedirectory, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_WebBootstrap, getTemplateCacheDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_WebBootstrap, setTemplateCacheDirectory, arginfo_dotphp_webbootstrap_settemplatecachedirectory, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_WebBootstrap, setTemplateClass, arginfo_dotphp_webbootstrap_settemplateclass, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_WebBootstrap, getTemplate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
