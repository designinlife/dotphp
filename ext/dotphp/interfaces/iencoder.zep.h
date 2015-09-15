
extern zend_class_entry *dotphp_interfaces_iencoder_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IEncoder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iencoder_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, enc_type)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iencoder_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, enc_type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_interfaces_iencoder_method_entry) {
	ZEND_FENTRY(encode, NULL, arginfo_dotphp_interfaces_iencoder_encode, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(decode, NULL, arginfo_dotphp_interfaces_iencoder_decode, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
