
extern zend_class_entry *dotphp_core_socketclient_ce;

ZEPHIR_INIT_CLASS(DotPHP_Core_SocketClient);

PHP_METHOD(DotPHP_Core_SocketClient, __construct);
PHP_METHOD(DotPHP_Core_SocketClient, __destruct);
PHP_METHOD(DotPHP_Core_SocketClient, connect);
PHP_METHOD(DotPHP_Core_SocketClient, close);
PHP_METHOD(DotPHP_Core_SocketClient, send);
PHP_METHOD(DotPHP_Core_SocketClient, recv);
PHP_METHOD(DotPHP_Core_SocketClient, isConnected);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_socketclient___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_socketclient_send, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_socketclient_recv, 0, 0, 0)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, waitall)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_core_socketclient_method_entry) {
	PHP_ME(DotPHP_Core_SocketClient, __construct, arginfo_dotphp_core_socketclient___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Core_SocketClient, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(DotPHP_Core_SocketClient, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SocketClient, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SocketClient, send, arginfo_dotphp_core_socketclient_send, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SocketClient, recv, arginfo_dotphp_core_socketclient_recv, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SocketClient, isConnected, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
