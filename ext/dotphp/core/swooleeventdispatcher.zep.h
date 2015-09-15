
extern zend_class_entry *dotphp_core_swooleeventdispatcher_ce;

ZEPHIR_INIT_CLASS(DotPHP_Core_SwooleEventDispatcher);

PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, __construct);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, __destruct);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onStart);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onShutdown);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onManagerStart);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onManagerStop);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onWorkerStart);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onWorkerStop);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onWorkerError);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onTimer);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onTask);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onFinish);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onConnect);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onClose);
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onReceive);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\SwooleBootstrap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onstart, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onshutdown, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onmanagerstart, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onmanagerstop, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onworkerstart, 0, 0, 2)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, worker_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onworkerstop, 0, 0, 2)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, worker_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onworkererror, 0, 0, 4)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, worker_id)
	ZEND_ARG_INFO(0, worker_pid)
	ZEND_ARG_INFO(0, exit_code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_ontimer, 0, 0, 2)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, interval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_ontask, 0, 0, 4)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, task_id)
	ZEND_ARG_INFO(0, from_id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onfinish, 0, 0, 3)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, task_id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onconnect, 0, 0, 3)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, fd)
	ZEND_ARG_INFO(0, from_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onclose, 0, 0, 3)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, fd)
	ZEND_ARG_INFO(0, from_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_core_swooleeventdispatcher_onreceive, 0, 0, 4)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, fd)
	ZEND_ARG_INFO(0, from_id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_core_swooleeventdispatcher_method_entry) {
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, __construct, arginfo_dotphp_core_swooleeventdispatcher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onStart, arginfo_dotphp_core_swooleeventdispatcher_onstart, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onShutdown, arginfo_dotphp_core_swooleeventdispatcher_onshutdown, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onManagerStart, arginfo_dotphp_core_swooleeventdispatcher_onmanagerstart, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onManagerStop, arginfo_dotphp_core_swooleeventdispatcher_onmanagerstop, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onWorkerStart, arginfo_dotphp_core_swooleeventdispatcher_onworkerstart, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onWorkerStop, arginfo_dotphp_core_swooleeventdispatcher_onworkerstop, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onWorkerError, arginfo_dotphp_core_swooleeventdispatcher_onworkererror, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onTimer, arginfo_dotphp_core_swooleeventdispatcher_ontimer, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onTask, arginfo_dotphp_core_swooleeventdispatcher_ontask, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onFinish, arginfo_dotphp_core_swooleeventdispatcher_onfinish, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onConnect, arginfo_dotphp_core_swooleeventdispatcher_onconnect, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onClose, arginfo_dotphp_core_swooleeventdispatcher_onclose, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Core_SwooleEventDispatcher, onReceive, arginfo_dotphp_core_swooleeventdispatcher_onreceive, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
