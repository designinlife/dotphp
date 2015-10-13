namespace DotPHP\Bean;

/**
 * 缓存参数对象。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
final class CacheParameter {
    private host = "127.0.0.1";

    private port = 6379;

    private passwd = null;

    private unix_socket = null;

    /**
     * 构造函数。
     * 
     * @param string host
     * @param int    port
     * @param string passwd
     * @param string unix_socket
     */
    public function __construct(string host, int port, string passwd = null, string unix_socket = null) {
        let this->host = host;
        let this->port = port;
        let this->passwd = passwd;
        let this->unix_socket = unix_socket;
    }

    /**
     * 获取主机地址。
     * 
     * @return string
     */
    public function getHost() -> string {
        return this->host;
    }

    /**
     * 设置主机地址。
     * 
     * @param string host
     * @return \DotPHP\Bean\CacheParameter
     */
    public function setHost(string host) -> <\DotPHP\Bean\CacheParameter> {
        let this->host = host;
        return this;
    }

    /**
     * 获取端口。
     * 
     * @return int
     */
    public function getPort() -> int {
        return this->port;
    }

    /**
     * 设置端口。
     * 
     * @param int port
     * @return \DotPHP\Bean\CacheParameter
     */
    public function setPort(string port) -> <\DotPHP\Bean\CacheParameter> {
        let this->port = port;
        return this;
    }

    /**
     * 获取密码。
     * 
     * @return string
     */
    public function getPass() -> string {
        return this->passwd;
    }

    /**
     * 设置密码。
     * 
     * @param string passwd
     * @return \DotPHP\Bean\CacheParameter
     */
    public function setPass(string passwd) -> <\DotPHP\Bean\CacheParameter> {
        let this->passwd = passwd;
        return this;
    }

    /**
     * 获取 UNIX 套接字地址。
     * 
     * @return string
     */
    public function getUnixSocket() -> string {
        return this->unix_socket;
    }

    /**
     * 设置 UNIX 套接字地址。
     * 
     * @param string unix_socket
     * @return \DotPHP\Bean\CacheParameter
     */
    public function setUnixSocket(string unix_socket) -> <\DotPHP\Bean\CacheParameter> {
        let this->unix_socket = unix_socket;
        return this;
    }
}