
extern zend_class_entry *dotphp_abstractbootstrap_ce;

ZEPHIR_INIT_CLASS(DotPHP_AbstractBootstrap);

PHP_METHOD(DotPHP_AbstractBootstrap, dispatch);
PHP_METHOD(DotPHP_AbstractBootstrap, initialize);
PHP_METHOD(DotPHP_AbstractBootstrap, initializeComplete);
PHP_METHOD(DotPHP_AbstractBootstrap, route);
PHP_METHOD(DotPHP_AbstractBootstrap, validate);
PHP_METHOD(DotPHP_AbstractBootstrap, execute);
PHP_METHOD(DotPHP_AbstractBootstrap, before);
PHP_METHOD(DotPHP_AbstractBootstrap, after);
PHP_METHOD(DotPHP_AbstractBootstrap, shutdown);
PHP_METHOD(DotPHP_AbstractBootstrap, defExceptionHandler);
PHP_METHOD(DotPHP_AbstractBootstrap, defErrorHandler);
PHP_METHOD(DotPHP_AbstractBootstrap, getDb);
PHP_METHOD(DotPHP_AbstractBootstrap, getLogger);
PHP_METHOD(DotPHP_AbstractBootstrap, isCliMode);
PHP_METHOD(DotPHP_AbstractBootstrap, getTimezone);
PHP_METHOD(DotPHP_AbstractBootstrap, setTimezone);
PHP_METHOD(DotPHP_AbstractBootstrap, getTimeOffset);
PHP_METHOD(DotPHP_AbstractBootstrap, setTimeOffset);
PHP_METHOD(DotPHP_AbstractBootstrap, getErrorLevel);
PHP_METHOD(DotPHP_AbstractBootstrap, setErrorLevel);
PHP_METHOD(DotPHP_AbstractBootstrap, getControllerNS);
PHP_METHOD(DotPHP_AbstractBootstrap, setControllerNS);
PHP_METHOD(DotPHP_AbstractBootstrap, setDbParameter);
PHP_METHOD(DotPHP_AbstractBootstrap, getLogDirectory);
PHP_METHOD(DotPHP_AbstractBootstrap, setLogDirectory);
PHP_METHOD(DotPHP_AbstractBootstrap, getLogLevel);
PHP_METHOD(DotPHP_AbstractBootstrap, setLogLevel);
PHP_METHOD(DotPHP_AbstractBootstrap, getLogMode);
PHP_METHOD(DotPHP_AbstractBootstrap, setLogMode);
PHP_METHOD(DotPHP_AbstractBootstrap, getLogModule);
PHP_METHOD(DotPHP_AbstractBootstrap, setLogModule);
PHP_METHOD(DotPHP_AbstractBootstrap, getVersion);
PHP_METHOD(DotPHP_AbstractBootstrap, isDebug);
PHP_METHOD(DotPHP_AbstractBootstrap, debug);
PHP_METHOD(DotPHP_AbstractBootstrap, dump);
PHP_METHOD(DotPHP_AbstractBootstrap, cts);
PHP_METHOD(DotPHP_AbstractBootstrap, setup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_dispatch, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, argv, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_execute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route_message, DotPHP\\Bean\\RouteMessage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_defexceptionhandler, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_deferrorhandler, 0, 0, 4)
	ZEND_ARG_INFO(0, errno)
	ZEND_ARG_INFO(0, errstr)
	ZEND_ARG_INFO(0, errfile)
	ZEND_ARG_INFO(0, errline)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_settimezone, 0, 0, 1)
	ZEND_ARG_INFO(0, timezone)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_settimeoffset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_seterrorlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, error_level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_setcontrollerns, 0, 0, 1)
	ZEND_ARG_INFO(0, controller_ns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_setdbparameter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, db_parameter, DotPHP\\Bean\\DbParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_setlogdirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, log_dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_setlogmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_setlogmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, debug)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_abstractbootstrap_dump, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_abstractbootstrap_method_entry) {
	PHP_ME(DotPHP_AbstractBootstrap, dispatch, arginfo_dotphp_abstractbootstrap_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, initialize, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, initializeComplete, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, route, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, validate, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, execute, arginfo_dotphp_abstractbootstrap_execute, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, before, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, after, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(DotPHP_AbstractBootstrap, shutdown, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, defExceptionHandler, arginfo_dotphp_abstractbootstrap_defexceptionhandler, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, defErrorHandler, arginfo_dotphp_abstractbootstrap_deferrorhandler, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getLogger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, isCliMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getTimezone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setTimezone, arginfo_dotphp_abstractbootstrap_settimezone, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getTimeOffset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setTimeOffset, arginfo_dotphp_abstractbootstrap_settimeoffset, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getErrorLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setErrorLevel, arginfo_dotphp_abstractbootstrap_seterrorlevel, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getControllerNS, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setControllerNS, arginfo_dotphp_abstractbootstrap_setcontrollerns, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setDbParameter, arginfo_dotphp_abstractbootstrap_setdbparameter, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getLogDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setLogDirectory, arginfo_dotphp_abstractbootstrap_setlogdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getLogLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setLogLevel, arginfo_dotphp_abstractbootstrap_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getLogMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setLogMode, arginfo_dotphp_abstractbootstrap_setlogmode, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getLogModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setLogModule, arginfo_dotphp_abstractbootstrap_setlogmodule, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, isDebug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, debug, arginfo_dotphp_abstractbootstrap_debug, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, dump, arginfo_dotphp_abstractbootstrap_dump, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, cts, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_AbstractBootstrap, setup, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
