namespace DotPHP\Interfaces;

/**
 * Swoole 事件处理器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface ISwooleEventDispatcher {
    /**
     * 构造函数。
     * 
     * @param \DotPHP\SwooleBootstrap bootstrap 上下文对象。
     * @return void
     */
    public function __construct(<\DotPHP\SwooleBootstrap> bootstrap) -> void;

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
    public function onStart(serv) -> void;

    /**
     * 服务器关闭事件。
     * 
     * @param \swoole_server serv
     * @return void
     */
    public function onShutdown(serv) -> void;

    /**
     * 管理进程启动事件。
     * 
     * @param \swoole_server serv
     * @return void
     */
    public function onManagerStart(serv) -> void;

    /**
     * 管理进程结束事件。
     * 
     * @param \swoole_server serv
     * @return void
     */
    public function onManagerStop(serv) -> void;

    /**
     * 工作进程启动事件。
     * 
     * @param \swoole_server serv
     * @param int worker_id
     * @return void
     */
    public function onWorkerStart(serv, int worker_id) -> void;

    /**
     * 工作进程结束事件。
     * 
     * @param \swoole_server serv
     * @param int worker_id
     * @return void
     */
    public function onWorkerStop(serv, int worker_id) -> void;

    /**
     * 工作进程出错事件。
     * 
     * @param \swoole_server serv
     * @param int worker_id
     * @param int worker_pid
     * @param int exit_code
     * @return void
     */
    public function onWorkerError(serv, int worker_id, int worker_pid, int exit_code) -> void;

    /**
     * 定时器事件。
     * 
     * @param \swoole_server serv
     * @param int interval
     * @return void
     */
    public function onTimer(serv, int interval) -> void;

    /**
     * 任务事件。
     * 
     * @param \swoole_server serv
     * @param int task_id
     * @param int from_id
     * @param string data
     * @return void
     */
    public function onTask(serv, int task_id, int from_id, string data) -> void;

    /**
     * 任务完成事件。
     * 
     * @param \swoole_server serv
     * @param int task_id
     * @param string data
     * @return void
     */
    public function onFinish(serv, int task_id, string data) -> void;

    /**
     * 客户端连接事件。
     * 
     * @param \swoole_server serv
     * @param int fd
     * @param int from_id
     * @return void
     */
    public function onConnect(serv, int fd, int from_id) -> void;

    /**
     * 客户端断开事件。
     * 
     * @param \swoole_server serv
     * @param int fd
     * @param int from_id
     * @return void
     */
    public function onClose(serv, int fd, int from_id) -> void;

    /**
     * 数据接收事件。
     * 
     * @param \swoole_server serv
     * @param int fd
     * @param int from_id
     * @param string data
     * @return void
     */
    public function onReceive(serv, int fd, int from_id, string data) -> void;
}