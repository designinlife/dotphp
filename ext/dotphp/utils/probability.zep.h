
extern zend_class_entry *dotphp_utils_probability_ce;

ZEPHIR_INIT_CLASS(DotPHP_Utils_Probability);

PHP_METHOD(DotPHP_Utils_Probability, hit);
PHP_METHOD(DotPHP_Utils_Probability, lottery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_probability_hit, 0, 0, 1)
	ZEND_ARG_INFO(0, rate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_probability_lottery, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, ratios, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_utils_probability_method_entry) {
	PHP_ME(DotPHP_Utils_Probability, hit, arginfo_dotphp_utils_probability_hit, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_Probability, lottery, arginfo_dotphp_utils_probability_lottery, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
