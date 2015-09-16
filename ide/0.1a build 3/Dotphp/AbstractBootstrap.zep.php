<?php

namespace DotPHP;

/**
 * DotPHP 启动器抽象类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
abstract class AbstractBootstrap
{
    /**
     * 时区。
     *
     * @var string
     */
    private $timezone = "Asia/Shanghai";

    /**
     * 错误报告级别。
     *
     * @var int
     */
    private $error_level = 32759;

    /**
     * 框架版本。
     *
     * @var string
     */
    private $version = "0.1a";

    /**
     * 系统时间偏移值。
     *
     * @var int
     */
    private $time_offset = 0;

    /**
     * 是否开启调试模式？
     *
     * @var boolean
     */
    private $_debug = false;

    /**
     * 是否命令行模式运行？
     *
     * @var boolean
     */
    private $is_cli_mode = false;

    /**
     * 数据库参数对象。
     *
     * @var \DotPHP\Bean\DbParameter
     */
    private $db_parameter = null;

    /**
     * 控制器命名空间。
     *
     * @var string
     */
    protected $controller_ns = null;

    /**
     * 日志输出目录。
     *
     * @var string
     */
    protected $log_directory = null;

    /**
     * 日志输出级别。
     *
     * @var int
     */
    protected $log_level = 0;

    /**
     * 日志输出模式。(1,控制台 | 2,文件)
     *
     * @var int
     */
    protected $log_mode = 1;

    /**
     * 日志模块名称。
     *
     * @var string
     */
    protected $log_module = "sys";

    /**
     * IDb 数据库操作对象。
     *
     * @var \DotPHP\Interfaces\IDb
     */
    protected $db = null;

    /**
     * ILogger 日志操作对象。
     *
     * @var \DotPHP\Interfaces\ILogger
     */
    protected $logger = null;

    /**
     * 命令行参数列表。
     *
     * @var array
     */
    protected $argv = null;


    /**
     * 启动程序。
     *
     * @param array $argv 
     * @return void 
     */
    public function dispatch($argv = null) {}

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
    abstract protected function initializeComplete();

    /**
     * 执行路由解析。
     *
     * @return \DotPHP\Bean\RouteMessage 
     */
    abstract protected function route();

    /**
     * 执行验证。
     *
     * @return void 
     */
    abstract protected function validate();

    /**
     * 执行程序。
     *
     * @param \DotPHP\Bean\RouteMessage $route_message 
     * @return void 
     */
    abstract protected function execute(\DotPHP\Bean\RouteMessage $route_message);

    /**
     * 在 execute() 调用之前执行。
     *
     * @return void 
     */
    protected function before() {}

    /**
     * 在 execute() 调用之后执行。
     *
     * @return void 
     */
    protected function after() {}

    /**
     * 释放资源。
     *
     * @return void 
     */
    public function shutdown() {}

    /**
     * 缺省异常处理。
     *
     * @param mixed $ex 
     * @return void 
     */
    public function defExceptionHandler(\Exception $ex) {}

    /**
     * 缺省错误处理。
     *
     * @param int $errno 
     * @param string $errstr 
     * @param string $errfile 
     * @param int $errline 
     * @return void 
     */
    final public function defErrorHandler($errno, $errstr, $errfile, $errline) {}

    /**
     * 获取 IDb 对象。
     *
     * @return \DotPHP\Interfaces\IDb 
     */
    public function getDb() {}

    /**
     * 获取 ILogger 对象。
     *
     * @return \DotPHP\Interfaces\ILogger 
     */
    public function getLogger() {}

    /**
     * 指示是否命令行运行模式？
     *
     * @return boolean 
     */
    public function isCliMode() {}

    /**
     * 获取当前设定的系统时区。
     *
     * @return string 
     */
    public function getTimezone() {}

    /**
     * 设置系统使用的时区。
     *
     * @param string $timezone 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setTimezone($timezone) {}

    /**
     * 获取系统时间偏移值。(秒)
     *
     * @return string 
     */
    public function getTimeOffset() {}

    /**
     * 设置系统时间偏移值。(秒)
     *
     * @param string $offset 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setTimeOffset($offset) {}

    /**
     * 获取错误追踪级别。
     *
     * @return int 
     */
    public function getErrorLevel() {}

    /**
     * 设置错误追踪级别。
     *
     * @param int $error_level 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setErrorLevel($error_level) {}

    /**
     * 获取控制器命名空间。
     *
     * @return string 
     */
    public function getControllerNS() {}

    /**
     * 设置控制器命名空间。
     *
     * @param string $controller_ns 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setControllerNS($controller_ns) {}

    /**
     * 设置数据库连接参数对象。
     *
     * @param \DotPHP\Bean\DbParameter $db_parameter 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setDbParameter(\DotPHP\Bean\DbParameter $db_parameter) {}

    /**
     * 获取日志目录。
     *
     * @return string 
     */
    public function getLogDirectory() {}

    /**
     * 设置日志目录。
     *
     * @param string $log_dir 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setLogDirectory($log_dir) {}

    /**
     * 获取日志输出级别。
     *
     * @return int 
     */
    public function getLogLevel() {}

    /**
     * 设置日志输出级别。
     *
     * @param int $level 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setLogLevel($level) {}

    /**
     * 获取日志输出模式。(1,控制台 | 2,文件)
     *
     * @return int 
     */
    public function getLogMode() {}

    /**
     * 设置日志输出模式。(1,控制台 | 2,文件)
     *
     * @param int $mode 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setLogMode($mode) {}

    /**
     * 获取日志模块名称。
     *
     * @return string 
     */
    public function getLogModule() {}

    /**
     * 设置日志模块名称。
     *
     * @param string $module 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function setLogModule($module) {}

    /**
     * 获取系统版本号。
     *
     * @return string 
     */
    public function getVersion() {}

    /**
     * 指示是否启用调试？
     *
     * @return boolean 
     */
    public function isDebug() {}

    /**
     * 设置调试模式开关。
     *
     * @param boolean $debug 
     * @return \DotPHP\AbstractBootstrap 
     */
    public function debug($debug) {}

    /**
     * 打印数据。
     *
     * @param mixed $data 
     * @return void 
     */
    public function dump($data) {}

    /**
     * 获取当前系统时间。
     *
     * @return int 
     */
    public function cts() {}

    /**
     * 系统环境设置。
     *
     * @return void 
     */
    final protected function setup() {}

}
