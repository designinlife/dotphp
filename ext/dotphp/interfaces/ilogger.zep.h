
extern zend_class_entry *dotphp_interfaces_ilogger_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_ILogger);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_setmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_setlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_error, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_fatal, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_info, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_trace, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_ilogger_warn, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_interfaces_ilogger_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, setModule, arginfo_dotphp_interfaces_ilogger_setmodule)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, setMode, arginfo_dotphp_interfaces_ilogger_setmode)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, setLevel, arginfo_dotphp_interfaces_ilogger_setlevel)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, debug, arginfo_dotphp_interfaces_ilogger_debug)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, error, arginfo_dotphp_interfaces_ilogger_error)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, fatal, arginfo_dotphp_interfaces_ilogger_fatal)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, info, arginfo_dotphp_interfaces_ilogger_info)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, trace, arginfo_dotphp_interfaces_ilogger_trace)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ILogger, warn, arginfo_dotphp_interfaces_ilogger_warn)
	PHP_FE_END
};
