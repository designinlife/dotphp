
extern zend_class_entry *dotphp_utils_arrayutil_ce;

ZEPHIR_INIT_CLASS(DotPHP_Utils_ArrayUtil);

PHP_METHOD(DotPHP_Utils_ArrayUtil, isAssoc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_arrayutil_isassoc, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_INFO(0, reusingKeys)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_utils_arrayutil_method_entry) {
	PHP_ME(DotPHP_Utils_ArrayUtil, isAssoc, arginfo_dotphp_utils_arrayutil_isassoc, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
