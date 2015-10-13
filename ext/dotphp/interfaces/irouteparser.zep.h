
extern zend_class_entry *dotphp_interfaces_irouteparser_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IRouteParser);

ZEPHIR_INIT_FUNCS(dotphp_interfaces_irouteparser_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_IRouteParser, parse, NULL)
	PHP_FE_END
};
