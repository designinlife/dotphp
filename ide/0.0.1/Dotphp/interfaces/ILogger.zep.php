<?php

namespace DotPHP\Interfaces;

/**
 * DotPHP 日志接口。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface ILogger
{

    /**
     * 设置日志模块名称。
     *
     * @param string $module 
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function setModule($module);

    /**
     * 设置日志输出模式。(1,写入文件并输出到控制台 | 2,按天切分)
     *
     * @param int $mode 
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function setMode($mode);

    /**
     * 设置日志输出级别。
     *
     * @param int $level 
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function setLevel($level);

    /**
     * 调试。
     *
     * @param mixed $msg 
     * @param array $context 
     * @return void 
     */
    public function debug($msg, $context = array());

    /**
     * 错误。
     *
     * @param mixed $msg 
     * @param array $context 
     * @param \Exception $ex 
     * @return void 
     */
    public function error($msg, $context = array(), \Exception $ex = null);

    /**
     * 严重错误。
     *
     * @param mixed $msg 
     * @param array $context 
     * @return void 
     */
    public function fatal($msg, $context = array());

    /**
     * 信息。
     *
     * @param mixed $msg 
     * @param array $context 
     * @return void 
     */
    public function info($msg, $context = array());

    /**
     * 跟踪。
     *
     * @param mixed $msg 
     * @param array $context 
     * @return void 
     */
    public function trace($msg, $context = array());

    /**
     * 警告。
     *
     * @param mixed $msg 
     * @param array $context 
     * @return void 
     */
    public function warn($msg, $context = array());

}