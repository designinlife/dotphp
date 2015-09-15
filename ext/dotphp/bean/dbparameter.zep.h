
extern zend_class_entry *dotphp_bean_dbparameter_ce;

ZEPHIR_INIT_CLASS(DotPHP_Bean_DbParameter);

PHP_METHOD(DotPHP_Bean_DbParameter, __construct);
PHP_METHOD(DotPHP_Bean_DbParameter, getHost);
PHP_METHOD(DotPHP_Bean_DbParameter, setHost);
PHP_METHOD(DotPHP_Bean_DbParameter, getPort);
PHP_METHOD(DotPHP_Bean_DbParameter, setPort);
PHP_METHOD(DotPHP_Bean_DbParameter, getUser);
PHP_METHOD(DotPHP_Bean_DbParameter, setUser);
PHP_METHOD(DotPHP_Bean_DbParameter, getPass);
PHP_METHOD(DotPHP_Bean_DbParameter, setPass);
PHP_METHOD(DotPHP_Bean_DbParameter, getDb);
PHP_METHOD(DotPHP_Bean_DbParameter, setDb);
PHP_METHOD(DotPHP_Bean_DbParameter, getCharset);
PHP_METHOD(DotPHP_Bean_DbParameter, setCharset);
PHP_METHOD(DotPHP_Bean_DbParameter, getUnixSocket);
PHP_METHOD(DotPHP_Bean_DbParameter, setUnixSocket);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter___construct, 0, 0, 5)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
	ZEND_ARG_INFO(0, db)
	ZEND_ARG_INFO(0, charset)
	ZEND_ARG_INFO(0, unix_socket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_setuser, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_setpass, 0, 0, 1)
	ZEND_ARG_INFO(0, passwd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_setdb, 0, 0, 1)
	ZEND_ARG_INFO(0, db)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_setcharset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_bean_dbparameter_setunixsocket, 0, 0, 1)
	ZEND_ARG_INFO(0, unix_socket)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_bean_dbparameter_method_entry) {
	PHP_ME(DotPHP_Bean_DbParameter, __construct, arginfo_dotphp_bean_dbparameter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Bean_DbParameter, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setHost, arginfo_dotphp_bean_dbparameter_sethost, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, getPort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setPort, arginfo_dotphp_bean_dbparameter_setport, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, getUser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setUser, arginfo_dotphp_bean_dbparameter_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, getPass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setPass, arginfo_dotphp_bean_dbparameter_setpass, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setDb, arginfo_dotphp_bean_dbparameter_setdb, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, getCharset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setCharset, arginfo_dotphp_bean_dbparameter_setcharset, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, getUnixSocket, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_DbParameter, setUnixSocket, arginfo_dotphp_bean_dbparameter_setunixsocket, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
