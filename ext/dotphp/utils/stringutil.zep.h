
extern zend_class_entry *dotphp_utils_stringutil_ce;

ZEPHIR_INIT_CLASS(DotPHP_Utils_StringUtil);

PHP_METHOD(DotPHP_Utils_StringUtil, quote);
PHP_METHOD(DotPHP_Utils_StringUtil, translate);
PHP_METHOD(DotPHP_Utils_StringUtil, substitute);
PHP_METHOD(DotPHP_Utils_StringUtil, length);
PHP_METHOD(DotPHP_Utils_StringUtil, alphaID);
PHP_METHOD(DotPHP_Utils_StringUtil, guid);
PHP_METHOD(DotPHP_Utils_StringUtil, ns);
PHP_METHOD(DotPHP_Utils_StringUtil, ip);
PHP_METHOD(DotPHP_Utils_StringUtil, encrypt);
PHP_METHOD(DotPHP_Utils_StringUtil, decrypt);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_translate, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_length, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_alphaid, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, to_num)
	ZEND_ARG_INFO(0, pad_up)
	ZEND_ARG_INFO(0, pass_key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_ip, 0, 0, 1)
	ZEND_ARG_INFO(0, addr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_encrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, s)
	ZEND_ARG_INFO(0, secure_key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_utils_stringutil_decrypt, 0, 0, 2)
	ZEND_ARG_INFO(0, s)
	ZEND_ARG_INFO(0, secure_key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_utils_stringutil_method_entry) {
	PHP_ME(DotPHP_Utils_StringUtil, quote, arginfo_dotphp_utils_stringutil_quote, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, translate, arginfo_dotphp_utils_stringutil_translate, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, substitute, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, length, arginfo_dotphp_utils_stringutil_length, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, alphaID, arginfo_dotphp_utils_stringutil_alphaid, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, guid, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, ns, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, ip, arginfo_dotphp_utils_stringutil_ip, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, encrypt, arginfo_dotphp_utils_stringutil_encrypt, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Utils_StringUtil, decrypt, arginfo_dotphp_utils_stringutil_decrypt, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
