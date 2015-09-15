
extern zend_class_entry *dotphp_interfaces_itemplate_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_ITemplate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_itemplate___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\WebBootstrap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_itemplate_assign, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_itemplate_display, 0, 0, 1)
	ZEND_ARG_INFO(0, tpl_file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_interfaces_itemplate_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ITemplate, __construct, arginfo_dotphp_interfaces_itemplate___construct)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ITemplate, assign, arginfo_dotphp_interfaces_itemplate_assign)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ITemplate, display, arginfo_dotphp_interfaces_itemplate_display)
	PHP_FE_END
};
