
extern zend_class_entry *dotphp_utils_number_ce;

ZEPHIR_INIT_CLASS(DotPHP_Utils_Number);

PHP_METHOD(DotPHP_Utils_Number, isPrime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_number_isprime, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_utils_number_method_entry) {
	PHP_ME(DotPHP_Utils_Number, isPrime, arginfo_dotphp_utils_number_isprime, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
