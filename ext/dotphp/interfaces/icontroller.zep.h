
extern zend_class_entry *dotphp_interfaces_icontroller_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IController);

ZEPHIR_INIT_FUNCS(dotphp_interfaces_icontroller_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IController, initialize, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IController, before, NULL)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IController, after, NULL)
	PHP_FE_END
};
