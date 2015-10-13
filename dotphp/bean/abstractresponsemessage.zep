namespace DotPHP\Bean;

/**
 * DotPHP 消息协议类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
abstract class AbstractResponseMessage {
    protected _timestamp = 0;

    protected _module = 0;

    protected _method = 0;

    protected _data = null;

    protected _errno = 0;

    protected _errstr = null;

    protected _op_code = 0;

    protected _trace = null;

    protected _delimiter = "\r\r";

    /**
     * 获取错误代码。
     * 
     * @return int
     */
    public function getErrorCode() -> int {
        return this->_errno;
    }

    /**
     * 设置错误代码。
     * 
     * @param int errno
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setErrorCode(int errno) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_errno = errno;

        return this;
    }

    /**
     * 获取错误消息。
     * 
     * @return string
     */
    public function getErrorMessage() -> string {
        return this->_errstr;
    }

    /**
     * 设置错误消息。
     * 
     * @param string errstr
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setErrorMessage(string errstr) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_errstr = errstr;

        return this;
    }

    /**
     * 获取异常堆栈消息。
     * 
     * @return string
     */
    public function getTrace() -> string {
        return this->_trace;
    }

    /**
     * 设置异常堆栈消息。
     * 
     * @param string errstr
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setTrace(string trace) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_trace = trace;

        return this;
    }

    /**
     * 获取模块编号。
     * 
     * @return int
     */
    public function getModule() -> int {
        return this->_module;
    }

    /**
     * 设置模块编号。
     * 
     * @param int module
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setModule(int module) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_module = module;

        return this;
    }

    /**
     * 获取接口编号。
     * 
     * @return int
     */
    public function getMethod() -> int {
        return this->_method;
    }

    /**
     * 设置接口编号。
     * 
     * @param int method
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setMethod(int method) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_method = method;

        return this;
    }

    /**
     * 获取数据对象。
     * 
     * @return mixed
     */
    public function getData() {
        return this->_data;
    }

    /**
     * 设置数据对象。
     * 
     * @param mixed data
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setData(data) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_data = data;

        return this;
    }

    /**
     * 获取操作代码。
     * 
     * @return int
     */
    public function getOpCode() -> int {
        return this->_op_code;
    }

    /**
     * 设置操作代码。
     * 
     * @param int op_code
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setOpCode(int op_code) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_op_code = op_code;

        return this;
    }

    /**
     * 获取消息分隔符。
     * 
     * @return int
     */
    public function getDelimiter() -> string {
        return this->_delimiter;
    }

    /**
     * 设置消息分隔符。
     * 
     * @param string delimiter
     * @return \DotPHP\Bean\AbstractResponseMessage
     */
    public function setDelimiter(string delimiter) -> <\DotPHP\Bean\AbstractResponseMessage> {
        let this->_delimiter = delimiter;

        return this;
    }

    /**
     * 数据编码。
     * 
     * @return string
     */
    abstract public function encode() -> string;
}