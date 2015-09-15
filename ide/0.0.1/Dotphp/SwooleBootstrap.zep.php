<?php

namespace DotPHP;

/**
 * DotPHP - 基于 Swoole 的 TCP Server 启动器。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class SwooleBootstrap extends \DotPHP\AbstractBootstrap
{
    /**
     * 模板目录。
     *
     * @var string
     */
    private $port = 9501;

    /**
     * Swoole 服务器参数选项。
     *
     * @var array
     */
    private $server_options = array();

    /**
     * Swoole 服务实例。
     *
     * @var \swoole_server
     */
    private $serv = null;

    /**
     * Swoole 事件调度器。
     *
     * @var \DotPHP\Interfaces\ISwooleEventDispatcher
     */
    private $event_dispatcher = null;


    /**
     * 初始化事件。
     *
     * @return void 
     */
    protected function initialize() {}

    /**
     * 初始化完成事件。
     *
     * @return void 
     */
    protected function initializeComplete() {}

    /**
     * 执行路由解析。
     *
     * @return \DotPHP\Bean\RouteMessage 
     */
    protected function route() {}

    /**
     * 执行验证。
     *
     * @return void 
     */
    protected function validate() {}

    /**
     * 执行程序。
     *
     * @param \DotPHP\Bean\RouteMessage $route_message 
     * @return void 
     */
    protected function execute(\DotPHP\Bean\RouteMessage $route_message) {}

    /**
     * 获取服务绑定端口。
     *
     * @return int 
     */
    public function getPort() {}

    /**
     * 设置服务绑定端口。
     *
     * @param int $port 
     * @return \DotPHP\SwooleBootstrap 
     */
    public function setPort($port) {}

    /**
     * 获取 TCP 服务参数选项。
     *
     * @return array 
     */
    public function getServerOptions() {}

    /**
     * 设置 TCP 服务参数选项。
     *
     * @param array $server_options 
     * @param int $port 
     * @return \DotPHP\SwooleBootstrap 
     */
    public function setServerOptions($server_options) {}

    /**
     * 设置 Swoole 事件处理对象。
     *
     * @param \DotPHP\Interfaces\ISwooleEventDispatcher $event_dispatcher 
     * @return \DotPHP\SwooleBootstrap 
     */
    public function setEventDispatcher(\DotPHP\Interfaces\ISwooleEventDispatcher $event_dispatcher) {}

}
