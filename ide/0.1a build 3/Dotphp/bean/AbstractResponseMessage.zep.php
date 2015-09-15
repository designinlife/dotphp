<?php

namespace DotPHP\Bean;

/**
 * DotPHP 消息协议类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
abstract class AbstractResponseMessage
{

    protected $_timestamp = 0;


    protected $_module = 0;


    protected $_method = 0;


    protected $_data = null;


    protected $_errno = 0;


    protected $_errstr = null;


    protected $_op_code = 0;


    protected $_trace = null;


    /**
     * 获取错误代码。
     *
     * @return int 
     */
    public function getErrorCode() {}

    /**
     * 设置错误代码。
     *
     * @param int $errno 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setErrorCode($errno) {}

    /**
     * 获取错误消息。
     *
     * @return string 
     */
    public function getErrorMessage() {}

    /**
     * 设置错误消息。
     *
     * @param string $errstr 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setErrorMessage($errstr) {}

    /**
     * 获取异常堆栈消息。
     *
     * @return string 
     */
    public function getTrace() {}

    /**
     * 设置异常堆栈消息。
     *
     * @param string $trace 
     * @param string $errstr 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setTrace($trace) {}

    /**
     * 获取模块编号。
     *
     * @return int 
     */
    public function getModule() {}

    /**
     * 设置模块编号。
     *
     * @param int $module 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setModule($module) {}

    /**
     * 获取接口编号。
     *
     * @return int 
     */
    public function getMethod() {}

    /**
     * 设置接口编号。
     *
     * @param int $method 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setMethod($method) {}

    /**
     * 获取数据对象。
     *
     * @return mixed 
     */
    public function getData() {}

    /**
     * 设置数据对象。
     *
     * @param mixed $data 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setData($data) {}

    /**
     * 获取操作代码。
     *
     * @return int 
     */
    public function getOpCode() {}

    /**
     * 设置操作代码。
     *
     * @param int $op_code 
     * @return \DotPHP\Bean\AbstractResponseMessage 
     */
    public function setOpCode($op_code) {}

    /**
     * 数据编码。
     *
     * @return string 
     */
    abstract public function encode();

}
