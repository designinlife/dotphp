namespace DotPHP\Bean;

/**
 * 适用于 IDb 接口的参数对象。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
final class DbParameter {
    private host = "127.0.0.1";

    private port = 3306;

    private user = "root";

    private passwd = "";

    private db = "test";

    private charset = "utf8";

    private unix_socket = null;

    /**
     * 构造函数。
     * 
     * @param string host
     * @param int    port
     * @param string user
     * @param string passwd
     * @param string db
     * @param string charset
     * @param string unix_socket
     */
    public function __construct(string host, int port, string user, string passwd, string db, string charset = "utf8", string unix_socket = null) {
        let this->host = host;
        let this->port = port;
        let this->user = user;
        let this->passwd = passwd;
        let this->db = db;
        let this->charset = charset;
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
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setHost(string host) -> <\DotPHP\Bean\DbParameter> {
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
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setPort(string port) -> <\DotPHP\Bean\DbParameter> {
        let this->port = port;
        return this;
    }

    /**
     * 获取登录帐号。
     * 
     * @return string
     */
    public function getUser() -> string {
        return this->user;
    }

    /**
     * 设置登录帐号。
     * 
     * @param string user
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setUser(string user) -> <\DotPHP\Bean\DbParameter> {
        let this->user = user;
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
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setPass(string passwd) -> <\DotPHP\Bean\DbParameter> {
        let this->passwd = passwd;
        return this;
    }

    /**
     * 获取数据库名称。
     * 
     * @return string
     */
    public function getDb() -> string {
        return this->db;
    }

    /**
     * 设置数据库名称。
     * 
     * @param string db
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setDb(string db) -> <\DotPHP\Bean\DbParameter> {
        let this->db = db;
        return this;
    }

    /**
     * 获取字符集。
     * 
     * @return string
     */
    public function getCharset() -> string {
        return this->charset;
    }

    /**
     * 设置字符集。
     * 
     * @param string charset
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setCharset(string charset) -> <\DotPHP\Bean\DbParameter> {
        let this->charset = charset;
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
     * @return <\DotPHP\Bean\DbParameter>
     */
    public function setUnixSocket(string unix_socket) -> <\DotPHP\Bean\DbParameter> {
        let this->unix_socket = unix_socket;
        return this;
    }
}