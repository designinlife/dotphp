
extern zend_class_entry *dotphp_utils_path_ce;

ZEPHIR_INIT_CLASS(DotPHP_Utils_Path);

PHP_METHOD(DotPHP_Utils_Path, combin);

ZEPHIR_INIT_FUNCS(dotphp_utils_path_method_entry) {
	PHP_ME(DotPHP_Utils_Path, combin, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
