
extern zend_class_entry *dotphp_dot_ce;

ZEPHIR_INIT_CLASS(DotPHP_Dot);

PHP_METHOD(DotPHP_Dot, setup);
PHP_METHOD(DotPHP_Dot, getRootDirectory);
PHP_METHOD(DotPHP_Dot, def_class_auto_handler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_dot_setup, 0, 0, 1)
	ZEND_ARG_INFO(0, sys_root_dir)
	ZEND_ARG_INFO(0, class_auto_handler)
	ZEND_ARG_INFO(0, error_level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_dot_def_class_auto_handler, 0, 0, 1)
	ZEND_ARG_INFO(0, class_name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_dot_method_entry) {
	PHP_ME(DotPHP_Dot, setup, arginfo_dotphp_dot_setup, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Dot, getRootDirectory, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Dot, def_class_auto_handler, arginfo_dotphp_dot_def_class_auto_handler, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
