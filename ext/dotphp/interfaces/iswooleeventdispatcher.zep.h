
extern zend_class_entry *dotphp_interfaces_iswooleeventdispatcher_ce;

ZEPHIR_INIT_CLASS(DotPHP_Interfaces_ISwooleEventDispatcher);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, DotPHP\\SwooleBootstrap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onstart, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onshutdown, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onmanagerstart, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onmanagerstop, 0, 0, 1)
	ZEND_ARG_INFO(0, serv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onworkerstart, 0, 0, 2)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, worker_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onworkerstop, 0, 0, 2)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, worker_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onworkererror, 0, 0, 4)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, worker_id)
	ZEND_ARG_INFO(0, worker_pid)
	ZEND_ARG_INFO(0, exit_code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_ontimer, 0, 0, 2)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, interval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_ontask, 0, 0, 4)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, task_id)
	ZEND_ARG_INFO(0, from_id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onfinish, 0, 0, 3)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, task_id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onconnect, 0, 0, 3)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, fd)
	ZEND_ARG_INFO(0, from_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onclose, 0, 0, 3)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, fd)
	ZEND_ARG_INFO(0, from_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_interfaces_iswooleeventdispatcher_onreceive, 0, 0, 4)
	ZEND_ARG_INFO(0, serv)
	ZEND_ARG_INFO(0, fd)
	ZEND_ARG_INFO(0, from_id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_interfaces_iswooleeventdispatcher_method_entry) {
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, __construct, arginfo_dotphp_interfaces_iswooleeventdispatcher___construct)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onStart, arginfo_dotphp_interfaces_iswooleeventdispatcher_onstart)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onShutdown, arginfo_dotphp_interfaces_iswooleeventdispatcher_onshutdown)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onManagerStart, arginfo_dotphp_interfaces_iswooleeventdispatcher_onmanagerstart)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onManagerStop, arginfo_dotphp_interfaces_iswooleeventdispatcher_onmanagerstop)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onWorkerStart, arginfo_dotphp_interfaces_iswooleeventdispatcher_onworkerstart)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onWorkerStop, arginfo_dotphp_interfaces_iswooleeventdispatcher_onworkerstop)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onWorkerError, arginfo_dotphp_interfaces_iswooleeventdispatcher_onworkererror)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onTimer, arginfo_dotphp_interfaces_iswooleeventdispatcher_ontimer)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onTask, arginfo_dotphp_interfaces_iswooleeventdispatcher_ontask)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onFinish, arginfo_dotphp_interfaces_iswooleeventdispatcher_onfinish)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onConnect, arginfo_dotphp_interfaces_iswooleeventdispatcher_onconnect)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onClose, arginfo_dotphp_interfaces_iswooleeventdispatcher_onclose)
	PHP_ABSTRACT_ME(DotPHP_Interfaces_ISwooleEventDispatcher, onReceive, arginfo_dotphp_interfaces_iswooleeventdispatcher_onreceive)
	PHP_FE_END
};
