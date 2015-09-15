<?php

namespace DotPHP\Core;

/**
 * 通用日志管理类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class GenericLogger extends \DotPHP\Base\DotBase implements \DotPHP\Interfaces\ILogger
{
    /**
     * 模块名称。
     *
     * @var string
     */
    private $_module = "sys";

    /**
     * 输出模式。
     *
     * @var int
     */
    private $_mode = 1;

    /**
     * 日志输出级别。
     *
     * @var int
     */
    private $_level = 0;

    /**
     * 日志类型名称。
     *
     * @var array
     */
    private $_types = array(0 => "OFF", 100 => "FATAL", 200 => "ERROR", 300 => "WARN", 400 => "INFO", 500 => "DEBUG", 600 => "TRACE", 9999 => "ALL");


    /**
     * 设置日志模块名称。
     *
     * @param string $module 
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function setModule($module) {}

    /**
     * 设置日志输出模式。(1,写入文件并输出到控制台 | 2,按天切分)
     *
     * @param int $mode 
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function setMode($mode) {}

    /**
     * 设置日志输出级别。
     *
     * @param int $level 
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function setLevel($level) {}

    /**
     * 调试。
     *
     * @param var $msg 
     * @param array $context 
     * @return void 
     */
    public function debug($msg, $context = array()) {}

    /**
     * 错误。
     *
     * @param var $msg 
     * @param array $context 
     * @param \Exception $ex 
     * @return void 
     */
    public function error($msg, $context = array(), \Exception $ex = null) {}

    /**
     * 严重错误。
     *
     * @param var $msg 
     * @param array $context 
     * @return void 
     */
    public function fatal($msg, $context = array()) {}

    /**
     * 信息。
     *
     * @param var $msg 
     * @param array $context 
     * @return void 
     */
    public function info($msg, $context = array()) {}

    /**
     * 跟踪。
     *
     * @param var $msg 
     * @param array $context 
     * @return void 
     */
    public function trace($msg, $context = array()) {}

    /**
     * 警告。
     *
     * @param var $msg 
     * @param array $context 
     * @return void 
     */
    public function warn($msg, $context = array()) {}

    /**
     * 日志输出控制函数。
     *
     * @param int $level 
     * @param mixed $msg 
     * @param array $context 
     * @param \Exception $ex 
     * @return boolean 
     */
    private function _log_write($level, $msg, $context = array(), \Exception $ex = null) {}

}
