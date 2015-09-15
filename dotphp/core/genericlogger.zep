namespace DotPHP\Core;

/**
 * 通用日志管理类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class GenericLogger extends \DotPHP\Base\DotBase implements \DotPHP\Interfaces\ILogger {
    /**
     * 模块名称。
     * 
     * @var string
     */
    private _module = "sys";

    /**
     * 输出模式。
     * 
     * @var int
     */
    private _mode = 1;

    /**
     * 日志输出级别。
     * 
     * @var int
     */
    private _level = 0;

    /**
     * 日志类型名称。
     * 
     * @var array
     */
    private _types = [0: "OFF", 100: "FATAL", 200: "ERROR", 300: "WARN", 400: "INFO", 500: "DEBUG", 600: "TRACE", 9999: "ALL"];

    /**
     * 设置日志模块名称。
     * 
     * @param string module
     * @return \DotPHP\Interfaces\ILogger
     */
    public function setModule(string module) -> <\DotPHP\Interfaces\ILogger> {
        let this->_module = module;

        return this;
    }

    /**
     * 设置日志输出模式。(1,写入文件并输出到控制台 | 2,按天切分)
     * 
     * @param int mode
     * @return \DotPHP\Interfaces\ILogger
     */
    public function setMode(int mode) -> <\DotPHP\Interfaces\ILogger> {
        let this->_mode = mode;

        return this;
    }

    /**
     * 设置日志输出级别。
     * 
     * @param int level
     * @return \DotPHP\Interfaces\ILogger
     */
    public function setLevel(int level) -> <\DotPHP\Interfaces\ILogger> {
        let this->_level = level;

        return this;
    }

    /**
     * 调试。
     * 
     * @param var msg
     * @param array context
     * @return void
     */
    public function debug(var msg, array context = []) -> void {
        this->_log_write(\DotPHP\Dot::LOG_DEBUG, msg, context);
    }

    /**
     * 错误。
     * 
     * @param var msg
     * @param array context
     * @param \Exception ex
     * @return void
     */
    public function error(var msg, array context = [], <\Exception> ex = null) -> void {
        this->_log_write(\DotPHP\Dot::LOG_ERROR, msg, context, ex);
    }

    /**
     * 严重错误。
     * 
     * @param var msg
     * @param array context
     * @return void
     */
    public function fatal(var msg, array context = []) -> void {
        this->_log_write(\DotPHP\Dot::LOG_FATAL, msg, context);
    }

    /**
     * 信息。
     * 
     * @param var msg
     * @param array context
     * @return void
     */
    public function info(var msg, array context = []) -> void {
        this->_log_write(\DotPHP\Dot::LOG_INFO, msg, context);
    }

    /**
     * 跟踪。
     * 
     * @param var msg
     * @param array context
     * @return void
     */
    public function trace(var msg, array context = []) -> void {
        this->_log_write(\DotPHP\Dot::LOG_TRACE, msg, context);
    }

    /**
     * 警告。
     * 
     * @param var msg
     * @param array context
     * @return void
     */
    public function warn(var msg, array context = []) -> void {
        this->_log_write(\DotPHP\Dot::LOG_WARN, msg, context);
    }

    /**
     * 日志输出控制函数。
     * 
     * @param int level
     * @param mixed msg
     * @param array context
     * @param \Exception ex
     * @return boolean
     */
    private function _log_write(int level, var msg, array context = [], <\Exception> ex = null) -> boolean {
        if this->_mode <= 0 {
            return false;
        }

        if level > this->_level {
            return false;
        }

        var date_str, t, micro, file, k, v;
        string file_pattern, msg_pattern;
        array reps1, reps2;

        let date_str     = date("Ymd");
        let file_pattern = "%d.%m.log";
        let msg_pattern  = "%d [%l] %m%n";

        let t     = microtime(true);
        let micro = sprintf("%03d", (t - floor(t)) * 1000);

        let reps1 = ["%d": date_str, "%m": strtolower(this->_module)];
        let reps2 = ["%d": date("Y-m-d H:i:s," . micro, t), "%l": this->_types[level], "%m": msg, "%n": PHP_EOL];

        let file = this->bootstrap->getLogDirectory() . "/" . file_pattern;
        let msg  = msg_pattern;

        for k, v in reps1 {
            let file = str_replace(k, v, file);
        }

        for k, v in reps2 {
            let msg = str_replace(k, v, msg);
        }

        // Zephir 目前存在 str_replace 参数不能使用数组的问题, 暂时变通解决!
        // let file = str_replace(["%d", "%m"], [date_str, strtolower(this->_module)], this->bootstrap->getLogDirectory() . "/" . file_pattern);
        // let msg  = str_replace(["%d", "%l", "%m", "%n"], [date("Y-m-d H:i:s," . micro, t), this->_types[level], msg, PHP_EOL], msg_pattern);

        if !empty context {
            for k, v in context {
                let msg = str_replace("{" . k . "}", v, msg);
            }
        }

        if ex {
            let msg .= ex->getTraceAsString() . PHP_EOL;
        }

        if 1 == (this->_mode & 1) {
            echo msg;
        }

        if 2 == (this->_mode & 2) {
            var fp;

            let fp = fopen(file, "a");

            if fp {
                fwrite(fp, msg);
                fclose(fp);
            }
        }

        return true;
    }
}