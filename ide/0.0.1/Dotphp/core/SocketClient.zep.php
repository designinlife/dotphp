<?php

namespace DotPHP\Core;

/**
 * 基于 Swoole 扩展的 TCP 客户端工具类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class SocketClient
{

    private $host = "127.0.0.1";


    private $port = 9501;


    private $instance = null;


    /**
     * 构造函数。
     *
     * @param string $host TCP 主机地址。
     * @param int $port 连接端口。
     * @return void 
     */
    public function __construct($host, $port) {}

    /**
     * 析构函数。
     *
     * @return void 
     */
    public function __destruct() {}

    /**
     * 连接主机。
     *
     * @return void 
     */
    public function connect() {}

    /**
     * 断开连接。
     *
     * @return void 
     */
    public function close() {}

    /**
     * 发送数据。
     *
     * @param mixed $msg 
     * @return void 
     */
    public function send($msg) {}

    /**
     * 接收数据。
     *
     * @param int $size 
     * @param boolean $waitall 
     * @return void 
     */
    public function recv($size = 65535, $waitall = false) {}

    /**
     * 是否已连接？
     *
     * @return void 
     */
    public function isConnected() {}

}
