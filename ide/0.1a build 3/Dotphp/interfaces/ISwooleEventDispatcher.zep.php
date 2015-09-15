<?php

namespace DotPHP\Interfaces;

/**
 * Swoole 事件处理器接口。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface ISwooleEventDispatcher
{

    /**
     * 构造函数。
     *
     * @param \DotPHP\SwooleBootstrap $bootstrap 上下文对象。
     * @return void 
     */
    public function __construct(\DotPHP\SwooleBootstrap $bootstrap);

    /**
     * 主进程的主线程启动之后触发此事件。
     * 在此事件之前进行了如下操作:
     * 1).已创建了管理进程
     * 2).已创建了工作进程
     * 3).已监听所有 TCP/UDP 端口
     * 4).已监听了 Timer 定时器
     *
     * @param \swoole_server $serv 
     * @return void 
     */
    public function onStart($serv);

    /**
     * 服务器关闭事件。
     *
     * @param \swoole_server $serv 
     * @return void 
     */
    public function onShutdown($serv);

    /**
     * 管理进程启动事件。
     *
     * @param \swoole_server $serv 
     * @return void 
     */
    public function onManagerStart($serv);

    /**
     * 管理进程结束事件。
     *
     * @param \swoole_server $serv 
     * @return void 
     */
    public function onManagerStop($serv);

    /**
     * 工作进程启动事件。
     *
     * @param \swoole_server $serv 
     * @param int $worker_id 
     * @return void 
     */
    public function onWorkerStart($serv, $worker_id);

    /**
     * 工作进程结束事件。
     *
     * @param \swoole_server $serv 
     * @param int $worker_id 
     * @return void 
     */
    public function onWorkerStop($serv, $worker_id);

    /**
     * 工作进程出错事件。
     *
     * @param \swoole_server $serv 
     * @param int $worker_id 
     * @param int $worker_pid 
     * @param int $exit_code 
     * @return void 
     */
    public function onWorkerError($serv, $worker_id, $worker_pid, $exit_code);

    /**
     * 定时器事件。
     *
     * @param \swoole_server $serv 
     * @param int $interval 
     * @return void 
     */
    public function onTimer($serv, $interval);

    /**
     * 任务事件。
     *
     * @param \swoole_server $serv 
     * @param int $task_id 
     * @param int $from_id 
     * @param string $data 
     * @return void 
     */
    public function onTask($serv, $task_id, $from_id, $data);

    /**
     * 任务完成事件。
     *
     * @param \swoole_server $serv 
     * @param int $task_id 
     * @param string $data 
     * @return void 
     */
    public function onFinish($serv, $task_id, $data);

    /**
     * 客户端连接事件。
     *
     * @param \swoole_server $serv 
     * @param int $fd 
     * @param int $from_id 
     * @return void 
     */
    public function onConnect($serv, $fd, $from_id);

    /**
     * 客户端断开事件。
     *
     * @param \swoole_server $serv 
     * @param int $fd 
     * @param int $from_id 
     * @return void 
     */
    public function onClose($serv, $fd, $from_id);

    /**
     * 数据接收事件。
     *
     * @param \swoole_server $serv 
     * @param int $fd 
     * @param int $from_id 
     * @param string $data 
     * @return void 
     */
    public function onReceive($serv, $fd, $from_id, $data);

}
