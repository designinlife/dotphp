
extern zend_class_entry *dotphp_core_sharetable_ce;

ZEPHIR_INIT_CLASS(DotPHP_Core_ShareTable);

PHP_METHOD(DotPHP_Core_ShareTable, __construct);
PHP_METHOD(DotPHP_Core_ShareTable, addColumns);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_sharetable___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_sharetable_addcolumns, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_core_sharetable_method_entry) {
	PHP_ME(DotPHP_Core_ShareTable, __construct, arginfo_dotphp_core_sharetable___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Core_ShareTable, addColumns, arginfo_dotphp_core_sharetable_addcolumns, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
