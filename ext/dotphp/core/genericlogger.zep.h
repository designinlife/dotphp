
extern zend_class_entry *dotphp_core_genericlogger_ce;

ZEPHIR_INIT_CLASS(DotPHP_Core_GenericLogger);

PHP_METHOD(DotPHP_Core_GenericLogger, setModule);
PHP_METHOD(DotPHP_Core_GenericLogger, setMode);
PHP_METHOD(DotPHP_Core_GenericLogger, setLevel);
PHP_METHOD(DotPHP_Core_GenericLogger, debug);
PHP_METHOD(DotPHP_Core_GenericLogger, error);
PHP_METHOD(DotPHP_Core_GenericLogger, fatal);
PHP_METHOD(DotPHP_Core_GenericLogger, info);
PHP_METHOD(DotPHP_Core_GenericLogger, trace);
PHP_METHOD(DotPHP_Core_GenericLogger, warn);
PHP_METHOD(DotPHP_Core_GenericLogger, _log_write);
static zend_object_value zephir_init_properties_DotPHP_Core_GenericLogger(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_setmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_setlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_error, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_fatal, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_info, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_trace, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger_warn, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_genericlogger__log_write, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_core_genericlogger_method_entry) {
	PHP_ME(DotPHP_Core_GenericLogger, setModule, arginfo_dotphp_core_genericlogger_setmodule, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, setMode, arginfo_dotphp_core_genericlogger_setmode, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, setLevel, arginfo_dotphp_core_genericlogger_setlevel, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, debug, arginfo_dotphp_core_genericlogger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, error, arginfo_dotphp_core_genericlogger_error, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, fatal, arginfo_dotphp_core_genericlogger_fatal, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, info, arginfo_dotphp_core_genericlogger_info, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, trace, arginfo_dotphp_core_genericlogger_trace, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, warn, arginfo_dotphp_core_genericlogger_warn, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_GenericLogger, _log_write, arginfo_dotphp_core_genericlogger__log_write, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
