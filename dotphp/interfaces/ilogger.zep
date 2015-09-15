namespace DotPHP\Interfaces;

/**
 * DotPHP 日志接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface ILogger {
    /**
     * 设置日志模块名称。
     * 
     * @param string module
     * @return \DotPHP\Interfaces\ILogger
     */
    public function setModule(string module) -> <\DotPHP\Interfaces\ILogger>;

    /**
     * 设置日志输出模式。(1,写入文件并输出到控制台 | 2,按天切分)
     * 
     * @param int mode
     * @return \DotPHP\Interfaces\ILogger
     */
    public function setMode(int mode) -> <\DotPHP\Interfaces\ILogger>;

    /**
     * 设置日志输出级别。
     * 
     * @param int level
     * @return \DotPHP\Interfaces\ILogger
     */
    public function setLevel(int level) -> <\DotPHP\Interfaces\ILogger>;

    /**
     * 调试。
     * 
     * @param mixed msg
     * @param array context
     * @return void
     */
    public function debug(var msg, array context = []) -> void;

    /**
     * 错误。
     * 
     * @param mixed msg
     * @param array context
     * @param \Exception ex
     * @return void
     */
    public function error(var msg, array context = [], <\Exception> ex = null) -> void;

    /**
     * 严重错误。
     * 
     * @param mixed msg
     * @param array context
     * @return void
     */
    public function fatal(var msg, array context = []) -> void;

    /**
     * 信息。
     * 
     * @param mixed msg
     * @param array context
     * @return void
     */
    public function info(var msg, array context = []) -> void;

    /**
     * 跟踪。
     * 
     * @param mixed msg
     * @param array context
     * @return void
     */
    public function trace(var msg, array context = []) -> void;

    /**
     * 警告。
     * 
     * @param mixed msg
     * @param array context
     * @return void
     */
    public function warn(var msg, array context = []) -> void;
}