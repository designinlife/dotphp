
extern zend_class_entry *dotphp_bean_abstractresponsemessage_ce;

ZEPHIR_INIT_CLASS(DotPHP_Bean_AbstractResponseMessage);

PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getErrorCode);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setErrorCode);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getErrorMessage);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setErrorMessage);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getTrace);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setTrace);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getModule);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setModule);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getMethod);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setMethod);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getData);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setData);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, getOpCode);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, setOpCode);
PHP_METHOD(DotPHP_Bean_AbstractResponseMessage, encode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_seterrorcode, 0, 0, 1)
	ZEND_ARG_INFO(0, errno)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_seterrormessage, 0, 0, 1)
	ZEND_ARG_INFO(0, errstr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_settrace, 0, 0, 1)
	ZEND_ARG_INFO(0, trace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_setmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_abstractresponsemessage_setopcode, 0, 0, 1)
	ZEND_ARG_INFO(0, op_code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_bean_abstractresponsemessage_method_entry) {
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getErrorCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setErrorCode, arginfo_dotphp_bean_abstractresponsemessage_seterrorcode, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getErrorMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setErrorMessage, arginfo_dotphp_bean_abstractresponsemessage_seterrormessage, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getTrace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setTrace, arginfo_dotphp_bean_abstractresponsemessage_settrace, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setModule, arginfo_dotphp_bean_abstractresponsemessage_setmodule, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setMethod, arginfo_dotphp_bean_abstractresponsemessage_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setData, arginfo_dotphp_bean_abstractresponsemessage_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, getOpCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, setOpCode, arginfo_dotphp_bean_abstractresponsemessage_setopcode, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_AbstractResponseMessage, encode, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
