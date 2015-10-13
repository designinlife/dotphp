
extern zend_class_entry *dotphp_bean_cacheparameter_ce;

ZEPHIR_INIT_CLASS(DotPHP_Bean_CacheParameter);

PHP_METHOD(DotPHP_Bean_CacheParameter, __construct);
PHP_METHOD(DotPHP_Bean_CacheParameter, getHost);
PHP_METHOD(DotPHP_Bean_CacheParameter, setHost);
PHP_METHOD(DotPHP_Bean_CacheParameter, getPort);
PHP_METHOD(DotPHP_Bean_CacheParameter, setPort);
PHP_METHOD(DotPHP_Bean_CacheParameter, getPass);
PHP_METHOD(DotPHP_Bean_CacheParameter, setPass);
PHP_METHOD(DotPHP_Bean_CacheParameter, getUnixSocket);
PHP_METHOD(DotPHP_Bean_CacheParameter, setUnixSocket);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_cacheparameter___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, passwd)
	ZEND_ARG_INFO(0, unix_socket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_cacheparameter_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_cacheparameter_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_cacheparameter_setpass, 0, 0, 1)
	ZEND_ARG_INFO(0, passwd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_cacheparameter_setunixsocket, 0, 0, 1)
	ZEND_ARG_INFO(0, unix_socket)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_bean_cacheparameter_method_entry) {
	PHP_ME(DotPHP_Bean_CacheParameter, __construct, arginfo_dotphp_bean_cacheparameter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Bean_CacheParameter, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, setHost, arginfo_dotphp_bean_cacheparameter_sethost, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, getPort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, setPort, arginfo_dotphp_bean_cacheparameter_setport, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, getPass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, setPass, arginfo_dotphp_bean_cacheparameter_setpass, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, getUnixSocket, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_CacheParameter, setUnixSocket, arginfo_dotphp_bean_cacheparameter_setunixsocket, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
