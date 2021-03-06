namespace DotPHP;

/**
 * DotPHP - 基于 Swoole 的 TCP Server 启动器。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
abstract class SwooleBootstrap extends \DotPHP\AbstractBootstrap {
    /**
     * 设置主机地址。
     * 
     * @var string
     */
    private host = "0.0.0.0";

    /**
     * 模板目录。
     * 
     * @var string
     */
    private port = 9501;

    /**
     * Swoole 服务器参数选项。
     * 
     * @var array
     */
    private server_options = [];

    /**
     * Swoole 服务实例。
     * 
     * @var \swoole_server
     */
    private serv = null;

    /**
     * Swoole 事件调度器。
     * 
     * @var \DotPHP\Interfaces\ISwooleEventDispatcher
     */
    private event_dispatcher = null;

    /**
     * 初始化完成事件。
     * 
     * @return void
     */
    protected function initializeComplete() -> void {}

    /**
     * 执行路由解析。
     * 
     * @return \DotPHP\Bean\RouteMessage
     */
    protected function route() -> <\DotPHP\Bean\RouteMessage> | null {
        return null;
    }

    /**
     * 执行验证。
     * 
     * @return void
     */
    protected function validate() -> void {}

    /**
     * 执行程序。
     * 
     * @param \DotPHP\Bean\RouteMessage route_message
     * @return void
     */
    protected function execute(<\DotPHP\Bean\RouteMessage> route_message) -> void {
        if empty this->event_dispatcher {
            throw new \DotPHP\ConfigurationException("尚未设置 ISwooleEventDispatcher 对象。");
        }

        let this->serv = swoole_server_create("0.0.0.0", this->port, SWOOLE_PROCESS, SWOOLE_SOCK_TCP);

        this->serv->set(this->server_options);
        this->serv->on("start",        [this->event_dispatcher, "onStart"]);
        this->serv->on("shutdown",     [this->event_dispatcher, "onShutdown"]);
        this->serv->on("managerStart", [this->event_dispatcher, "onManagerStart"]);
        this->serv->on("managerStop",  [this->event_dispatcher, "onManagerStop"]);
        this->serv->on("workerStart",  [this->event_dispatcher, "onWorkerStart"]);
        this->serv->on("workerStop",   [this->event_dispatcher, "onWorkerStop"]);
        this->serv->on("workerError",  [this->event_dispatcher, "onWorkerError"]);
        this->serv->on("timer",        [this->event_dispatcher, "onTimer"]);
        this->serv->on("task",         [this->event_dispatcher, "onTask"]);
        this->serv->on("finish",       [this->event_dispatcher, "onFinish"]);
        this->serv->on("connect",      [this->event_dispatcher, "onConnect"]);
        this->serv->on("close",        [this->event_dispatcher, "onClose"]);
        this->serv->on("receive",      [this->event_dispatcher, "onReceive"]);
        this->serv->start();
    }

    /**
     * 获取服务监听地址。
     * 
     * @return string
     */
    public function getHost() -> string {
        return this->host;
    }

    /**
     * 设置服务监听地址。
     * 
     * @param string host
     * @return \DotPHP\SwooleBootstrap
     */
    public function setHost(string host) -> <\DotPHP\SwooleBootstrap> {
        let this->host = host;

        return this;
    }

    /**
     * 获取服务绑定端口。
     * 
     * @return int
     */
    public function getPort() -> string {
        return this->port;
    }

    /**
     * 设置服务绑定端口。
     * 
     * @param int port
     * @return \DotPHP\SwooleBootstrap
     */
    public function setPort(int port) -> <\DotPHP\SwooleBootstrap> {
        let this->port = port;

        return this;
    }

    /**
     * 获取 TCP 服务参数选项。
     * 
     * @return array
     */
    public function getServerOptions() -> array {
        return this->server_options;
    }

    /**
     * 设置 TCP 服务参数选项。
     * 
     * @param int port
     * @return \DotPHP\SwooleBootstrap
     */
    public function setServerOptions(array server_options) -> <\DotPHP\SwooleBootstrap> {
        let this->server_options = server_options;

        return this;
    }

    /**
     * 设置 Swoole 事件处理对象。
     * 
     * @param \DotPHP\Interfaces\ISwooleEventDispatcher event_dispatcher
     * @return \DotPHP\SwooleBootstrap
     */
    public function setEventDispatcher(<\DotPHP\Interfaces\ISwooleEventDispatcher> event_dispatcher) -> <\DotPHP\SwooleBootstrap> {
        let this->event_dispatcher = event_dispatcher;

        return this;
    }
}