
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Swoole 事件处理器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_ISwooleEventDispatcher) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, ISwooleEventDispatcher, dotphp, interfaces_iswooleeventdispatcher, dotphp_interfaces_iswooleeventdispatcher_method_entry);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param \DotPHP\SwooleBootstrap bootstrap 上下文对象。
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, __construct);

/**
 * 主进程的主线程启动之后触发此事件。
 * 
 * 在此事件之前进行了如下操作:
 *     1).已创建了管理进程
 *     2).已创建了工作进程
 *     3).已监听所有 TCP/UDP 端口
 *     4).已监听了 Timer 定时器
 * 
 * @param \swoole_server serv
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onStart);

/**
 * 服务器关闭事件。
 * 
 * @param \swoole_server serv
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onShutdown);

/**
 * 管理进程启动事件。
 * 
 * @param \swoole_server serv
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onManagerStart);

/**
 * 管理进程结束事件。
 * 
 * @param \swoole_server serv
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onManagerStop);

/**
 * 工作进程启动事件。
 * 
 * @param \swoole_server serv
 * @param int worker_id
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onWorkerStart);

/**
 * 工作进程结束事件。
 * 
 * @param \swoole_server serv
 * @param int worker_id
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onWorkerStop);

/**
 * 工作进程出错事件。
 * 
 * @param \swoole_server serv
 * @param int worker_id
 * @param int worker_pid
 * @param int exit_code
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onWorkerError);

/**
 * 定时器事件。
 * 
 * @param \swoole_server serv
 * @param int interval
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onTimer);

/**
 * 任务事件。
 * 
 * @param \swoole_server serv
 * @param int task_id
 * @param int from_id
 * @param string data
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onTask);

/**
 * 任务完成事件。
 * 
 * @param \swoole_server serv
 * @param int task_id
 * @param string data
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onFinish);

/**
 * 客户端连接事件。
 * 
 * @param \swoole_server serv
 * @param int fd
 * @param int from_id
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onConnect);

/**
 * 客户端断开事件。
 * 
 * @param \swoole_server serv
 * @param int fd
 * @param int from_id
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onClose);

/**
 * 数据接收事件。
 * 
 * @param \swoole_server serv
 * @param int fd
 * @param int from_id
 * @param string data
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_ISwooleEventDispatcher, onReceive);

