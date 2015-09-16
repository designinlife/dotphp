namespace DotPHP\Core;

/**
 * 基于 Swoole 扩展的 TCP 客户端工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class SocketClient {
    private host = "127.0.0.1";

    private port = 9501;

    private instance = null;

    /**
     * 构造函数。
     * 
     * @param string host TCP 主机地址。
     * @param int port 连接端口。
     * @return void
     */
    public function __construct(string host, int port) -> void {
        let this->host = host;
        let this->port = port;
    }

    /**
     * 析构函数。
     * 
     * @return void
     */
    public function __destruct() -> void {
        unset(this->instance);
    }

    /**
     * 连接主机。
     * 
     * @return void
     */
    public function connect() -> void {
        if !this->instance {
            let this->instance = new \swoole_client(SWOOLE_SOCK_TCP);

            if !this->instance->connect(this->host, this->port, -1) {
                throw new \DotPHP\SocketException("连接主机 " . this->host . ":" . this->port . " 失败。(#" . this->instance->errCode . ")");
            }
        }
    }

    /**
     * 断开连接。
     * 
     * @return void
     */
    public function close() -> void {
        if this->instance {
            this->instance->close();
        }
    }

    /**
     * 发送数据。
     * 
     * @return void
     */
    public function send(msg) -> int {
        this->connect();

        return this->instance->send(msg);
    }

    /**
     * 接收数据。
     * 
     * @param int size
     * @param boolean waitall
     * @return void
     */
    public function recv(int size = 65535, boolean waitall = false) -> string {
        return this->instance->recv(size, waitall);
    }

    /**
     * 是否已连接？
     * 
     * @return void
     */
    public function isConnected() -> boolean {
        return this->instance->isConnected();
    }
}