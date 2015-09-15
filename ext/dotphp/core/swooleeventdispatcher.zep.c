
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * 适用于 IDb 接口的参数对象。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Core_SwooleEventDispatcher) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Core, SwooleEventDispatcher, dotphp, core_swooleeventdispatcher, dotphp_core_swooleeventdispatcher_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * AbstractBootstrap 实例。
	 * 
	 * @var \DotPHP\SwooleBootstrap
	 */
	zend_declare_property_null(dotphp_core_swooleeventdispatcher_ce, SL("bootstrap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(dotphp_core_swooleeventdispatcher_ce TSRMLS_CC, 1, dotphp_interfaces_iswooleeventdispatcher_ce);
	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\SwooleBootstrap bootstrap 上下文对象。
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, __construct) {

	zval *bootstrap;

	zephir_fetch_params(0, 1, 0, &bootstrap);



	zephir_update_property_this(this_ptr, SL("bootstrap"), bootstrap TSRMLS_CC);

}

/**
 * 析构函数。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, __destruct) {


	zephir_unset_property(this_ptr, "bootstrap" TSRMLS_CC);

}

/**
 * 主进程的主线程启动之后触发此事件。
 * 
 * 在此事件之前进行了如下操作:
 *     1).已创建了管理进程
 *     2).已创建了工作进程
 *     3).已监听所有 TCP/UDP 端口
 *     4).已监听了 Timer 定时器
 * 
 * @param swoole_server serv
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onStart) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serv, *_0, *_1, *_2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serv);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("bootstrap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, _0, SL("logger"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("bootstrap"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getport", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "TCP 服务器已启动。(0.0.0.0:", _3, ")");
	ZEPHIR_CALL_METHOD(NULL, _1, "info", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 服务器关闭事件。
 * 
 * @param swoole_server serv
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onShutdown) {

	zval *serv;

	zephir_fetch_params(0, 1, 0, &serv);




}

/**
 * 管理进程启动事件。
 * 
 * @param swoole_server serv
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onManagerStart) {

	zval *serv;

	zephir_fetch_params(0, 1, 0, &serv);




}

/**
 * 管理进程结束事件。
 * 
 * @param swoole_server serv
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onManagerStop) {

	zval *serv;

	zephir_fetch_params(0, 1, 0, &serv);




}

/**
 * 工作进程启动事件。
 * 
 * @param swoole_server serv
 * @param int worker_id
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onWorkerStart) {

	int worker_id;
	zval *serv, *worker_id_param = NULL;

	zephir_fetch_params(0, 2, 0, &serv, &worker_id_param);

	worker_id = zephir_get_intval(worker_id_param);



}

/**
 * 工作进程结束事件。
 * 
 * @param swoole_server serv
 * @param int worker_id
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onWorkerStop) {

	int worker_id;
	zval *serv, *worker_id_param = NULL;

	zephir_fetch_params(0, 2, 0, &serv, &worker_id_param);

	worker_id = zephir_get_intval(worker_id_param);



}

/**
 * 工作进程出错事件。
 * 
 * @param swoole_server serv
 * @param int worker_id
 * @param int worker_pid
 * @param int exit_code
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onWorkerError) {

	int worker_id, worker_pid, exit_code;
	zval *serv, *worker_id_param = NULL, *worker_pid_param = NULL, *exit_code_param = NULL;

	zephir_fetch_params(0, 4, 0, &serv, &worker_id_param, &worker_pid_param, &exit_code_param);

	worker_id = zephir_get_intval(worker_id_param);
	worker_pid = zephir_get_intval(worker_pid_param);
	exit_code = zephir_get_intval(exit_code_param);



}

/**
 * 定时器事件。
 * 
 * @param swoole_server serv
 * @param int interval
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onTimer) {

	int interval;
	zval *serv, *interval_param = NULL;

	zephir_fetch_params(0, 2, 0, &serv, &interval_param);

	interval = zephir_get_intval(interval_param);



}

/**
 * 任务事件。
 * 
 * @param swoole_server serv
 * @param int task_id
 * @param int from_id
 * @param string data
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onTask) {

	zval *data = NULL;
	int task_id, from_id;
	zval *serv, *task_id_param = NULL, *from_id_param = NULL, *data_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &serv, &task_id_param, &from_id_param, &data_param);

	task_id = zephir_get_intval(task_id_param);
	from_id = zephir_get_intval(from_id_param);
	zephir_get_strval(data, data_param);



}

/**
 * 任务完成事件。
 * 
 * @param swoole_server serv
 * @param int task_id
 * @param string data
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onFinish) {

	zval *data = NULL;
	int task_id;
	zval *serv, *task_id_param = NULL, *data_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &serv, &task_id_param, &data_param);

	task_id = zephir_get_intval(task_id_param);
	zephir_get_strval(data, data_param);



}

/**
 * 客户端连接事件。
 * 
 * @param swoole_server serv
 * @param int fd
 * @param int from_id
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onConnect) {

}

/**
 * 客户端断开事件。
 * 
 * @param swoole_server serv
 * @param int fd
 * @param int from_id
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onClose) {

}

/**
 * 数据接收事件。
 * 
 * @param swoole_server serv
 * @param int fd
 * @param int from_id
 * @param string data
 * @return void
 */
PHP_METHOD(DotPHP_Core_SwooleEventDispatcher, onReceive) {

}

