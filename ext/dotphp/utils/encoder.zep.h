
extern zend_class_entry *dotphp_utils_encoder_ce;

ZEPHIR_INIT_CLASS(DotPHP_Utils_Encoder);

PHP_METHOD(DotPHP_Utils_Encoder, encode);
PHP_METHOD(DotPHP_Utils_Encoder, decode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_encoder_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, enc_type)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_encoder_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, enc_type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_utils_encoder_method_entry) {
	PHP_ME(DotPHP_Utils_Encoder, encode, arginfo_dotphp_utils_encoder_encode, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_Encoder, decode, arginfo_dotphp_utils_encoder_decode, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
