<?php

namespace DotPHP\Bean;

/**
 * 适用于 IDb 接口的参数对象。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
final class DbParameter
{

    private $host = "127.0.0.1";


    private $port = 3306;


    private $user = "root";


    private $passwd = "";


    private $db = "test";


    private $charset = "utf8";


    private $unix_socket = null;


    /**
     * 构造函数。
     *
     * @param string $host 
     * @param int $port 
     * @param string $user 
     * @param string $passwd 
     * @param string $db 
     * @param string $charset 
     * @param string $unix_socket 
     */
    public function __construct($host, $port, $user, $passwd, $db, $charset = "utf8", $unix_socket = null) {}

    /**
     * 获取主机地址。
     *
     * @return string 
     */
    public function getHost() {}

    /**
     * 设置主机地址。
     *
     * @param string $host 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setHost($host) {}

    /**
     * 获取端口。
     *
     * @return int 
     */
    public function getPort() {}

    /**
     * 设置端口。
     *
     * @param int $port 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setPort($port) {}

    /**
     * 获取登录帐号。
     *
     * @return string 
     */
    public function getUser() {}

    /**
     * 设置登录帐号。
     *
     * @param string $user 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setUser($user) {}

    /**
     * 获取密码。
     *
     * @return string 
     */
    public function getPass() {}

    /**
     * 设置密码。
     *
     * @param string $passwd 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setPass($passwd) {}

    /**
     * 获取数据库名称。
     *
     * @return string 
     */
    public function getDb() {}

    /**
     * 设置数据库名称。
     *
     * @param string $db 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setDb($db) {}

    /**
     * 获取字符集。
     *
     * @return string 
     */
    public function getCharset() {}

    /**
     * 设置字符集。
     *
     * @param string $charset 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setCharset($charset) {}

    /**
     * 获取 UNIX 套接字地址。
     *
     * @return string 
     */
    public function getUnixSocket() {}

    /**
     * 设置 UNIX 套接字地址。
     *
     * @param string $unix_socket 
     * @return <\DotPHP\Bean\DbParameter> 
     */
    public function setUnixSocket($unix_socket) {}

}
