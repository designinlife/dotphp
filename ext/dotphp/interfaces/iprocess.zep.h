
extern zend_class_entry *dotphp_interfaces_iprocess_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IProcess);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iprocess___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\CliBootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_interfaces_iprocess_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IProcess, __construct, arginfo_dotphp_interfaces_iprocess___construct)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IProcess, initialize, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IProcess, execute, NULL)
	PHP_FE_END
};
