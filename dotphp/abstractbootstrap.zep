namespace DotPHP;

/**
 * DotPHP 启动器抽象类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
abstract class AbstractBootstrap {
    /**
     * 时区。
     * 
     * @var string
     */
    private timezone = "Asia/Shanghai";

    /**
     * 错误报告级别。
     * 
     * @var int
     */
    private error_level = 32759;

    /**
     * 框架版本。
     * 
     * @var string
     */
    private version = "0.1a";

    /**
     * 系统时间偏移值。
     * 
     * @var int
     */
    private time_offset = 0;

    /**
     * 是否开启调试模式？
     * 
     * @var boolean
     */
    private _debug = false;

    /**
     * 是否命令行模式运行？
     * 
     * @var boolean
     */
    private is_cli_mode = false;

    /**
     * 数据库参数对象。
     * 
     * @var \DotPHP\Bean\DbParameter
     */
    private db_parameter = null;

    /**
     * 控制器命名空间。
     * 
     * @var string
     */
    protected controller_ns = null;

    /**
     * 日志输出目录。
     * 
     * @var string
     */
    protected log_directory = null;

    /**
     * 日志输出级别。
     * 
     * @var int
     */
    protected log_level = 0;

    /**
     * 日志输出模式。(1,控制台 | 2,文件)
     * 
     * @var int
     */
    protected log_mode = 1;

    /**
     * 日志模块名称。
     * 
     * @var string
     */
    protected log_module = "sys";

    /**
     * IDb 数据库操作对象。
     * 
     * @var \DotPHP\Interfaces\IDb
     */
    protected db = null;

    /**
     * ILogger 日志操作对象。
     * 
     * @var \DotPHP\Interfaces\ILogger
     */
    protected logger = null;

    /**
     * 命令行参数列表。
     * 
     * @var array
     */
    public argv = null;

    /**
     * 启动程序。
     * 
     * @param array argv
     * @return void
     */
    public function dispatch(array argv = null) -> void {
        if 0 === strcmp("cli", PHP_SAPI) {
            let this->is_cli_mode = true;
        }

        let this->argv = argv;

        var objMsgRoute = null;

        this->setup();                   // 安装系统环境设置
        this->initialize();              // 初始化事件
        this->initializeComplete();      // 初始化完成事件

        let objMsgRoute = this->route(); // 解析路由并返回路由结果对象
        
        this->validate();                // 验证请求合法性
        this->before();                  // before 事件
        this->execute(objMsgRoute);      // 执行控制器方法
        this->after();                   // after 事件
    }

    /**
     * 初始化事件。
     * 
     * @return void
     */
    abstract protected function initialize() -> void {}

    /**
     * 初始化完成事件。
     * 
     * @return void
     */
    abstract protected function initializeComplete() -> void {}

    /**
     * 执行路由解析。
     * 
     * @return \DotPHP\Bean\RouteMessage
     */
    abstract protected function route() -> <\DotPHP\Bean\RouteMessage> | null {}

    /**
     * 执行验证。
     * 
     * @return void
     */
    abstract protected function validate() -> void {}

    /**
     * 执行程序。
     * 
     * @param \DotPHP\Bean\RouteMessage route_message
     * @return void
     */
    abstract protected function execute(<\DotPHP\Bean\RouteMessage> route_message) -> void {}

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
    public function shutdown() -> void {}

    /**
     * 缺省异常处理。
     * 
     * @return void
     */
    public function defExceptionHandler(<\Exception> ex) -> void {
        echo ex->getMessage(), "\r\n", ex->getTraceAsString();
        exit(2);
    }

    /**
     * 缺省错误处理。
     * 
     * @param int errno
     * @param string errstr
     * @param string errfile
     * @param int errline
     * @return void
     */
    final public function defErrorHandler(int errno, string errstr, string errfile, int errline) -> void {
        throw new \ErrorException(errstr, errno, 0, errfile, errline);
    }

    /**
     * 获取 IDb 对象。
     * 
     * @return \DotPHP\Interfaces\IDb
     */
    public function getDb() -> <\DotPHP\Interfaces\IDb> {
        return this->db;
    }

    /**
     * 获取 ILogger 对象。
     * 
     * @return \DotPHP\Interfaces\ILogger
     */
    public function getLogger() -> <\DotPHP\Interfaces\ILogger> {
        return this->logger;
    }

    /**
     * 指示是否命令行运行模式？
     * 
     * @return boolean
     */
    public function isCliMode() -> boolean {
        return this->is_cli_mode;
    }

    /**
     * 获取当前设定的系统时区。
     * 
     * @return string
     */
    public function getTimezone() -> string {
        return this->timezone;
    }

    /**
     * 设置系统使用的时区。
     * 
     * @param string timezone
     * @return \DotPHP\AbstractBootstrap
     */
    public function setTimezone(string timezone) -> <\DotPHP\AbstractBootstrap> {
        let this->timezone = timezone;

        return this;
    }

    /**
     * 获取系统时间偏移值。(秒)
     * 
     * @return string
     */
    public function getTimeOffset() -> string {
        return this->time_offset;
    }

    /**
     * 设置系统时间偏移值。(秒)
     * 
     * @param string offset
     * @return \DotPHP\AbstractBootstrap
     */
    public function setTimeOffset(int offset) -> <\DotPHP\AbstractBootstrap> {
        let this->time_offset = offset;

        return this;
    }

    /**
     * 获取错误追踪级别。
     * 
     * @return int
     */
    public function getErrorLevel() -> string {
        return this->error_level;
    }

    /**
     * 设置错误追踪级别。
     * 
     * @param int error_level
     * @return \DotPHP\AbstractBootstrap
     */
    public function setErrorLevel(string error_level) -> <\DotPHP\AbstractBootstrap> {
        let this->error_level = error_level;

        return this;
    }

    /**
     * 获取控制器命名空间。
     * 
     * @return string
     */
    public function getControllerNS() -> string {
        return this->controller_ns;
    }

    /**
     * 设置控制器命名空间。
     * 
     * @param string controller_ns
     * @return \DotPHP\AbstractBootstrap
     */
    public function setControllerNS(string controller_ns) -> <\DotPHP\AbstractBootstrap> {
        let this->controller_ns = controller_ns;

        return this;
    }

    /**
     * 设置数据库连接参数对象。
     * 
     * @param \DotPHP\Bean\DbParameter db_parameter
     * @return \DotPHP\AbstractBootstrap
     */
    public function setDbParameter(<\DotPHP\Bean\DbParameter> db_parameter) -> <\DotPHP\AbstractBootstrap> {
        let this->db_parameter = db_parameter;

        return this;
    }

    /**
     * 获取日志目录。
     * 
     * @return string
     */
    public function getLogDirectory() -> string {
        return this->log_directory;
    }

    /**
     * 设置日志目录。
     * 
     * @param string log_dir
     * @return \DotPHP\AbstractBootstrap
     */
    public function setLogDirectory(string log_dir) -> <\DotPHP\AbstractBootstrap> {
        let this->log_directory = log_dir;

        return this;
    }

    /**
     * 获取日志输出级别。
     * 
     * @return int
     */
    public function getLogLevel() -> int {
        return this->log_level;
    }

    /**
     * 设置日志输出级别。
     * 
     * @param int level
     * @return \DotPHP\AbstractBootstrap
     */
    public function setLogLevel(int level) -> <\DotPHP\AbstractBootstrap> {
        let this->log_level = level;

        return this;
    }

    /**
     * 获取日志输出模式。(1,控制台 | 2,文件)
     * 
     * @return int
     */
    public function getLogMode() -> int {
        return this->log_mode;
    }

    /**
     * 设置日志输出模式。(1,控制台 | 2,文件)
     * 
     * @param int mode
     * @return \DotPHP\AbstractBootstrap
     */
    public function setLogMode(int mode) -> <\DotPHP\AbstractBootstrap> {
        let this->log_mode = mode;

        return this;
    }

    /**
     * 获取日志模块名称。
     * 
     * @return string
     */
    public function getLogModule() -> string {
        return this->log_module;
    }

    /**
     * 设置日志模块名称。
     * 
     * @param string module
     * @return \DotPHP\AbstractBootstrap
     */
    public function setLogModule(string module) -> <\DotPHP\AbstractBootstrap> {
        let this->log_module = module;

        return this;
    }

    /**
     * 获取系统版本号。
     * 
     * @return string
     */
    public function getVersion() -> string {
        return this->version;
    }

    /**
     * 指示是否启用调试？
     * 
     * @return boolean
     */
    public function isDebug() -> boolean {
        return this->_debug;
    }

    /**
     * 设置调试模式开关。
     * 
     * @param boolean debug
     * @return \DotPHP\AbstractBootstrap
     */
    public function debug(boolean debug) -> <\DotPHP\AbstractBootstrap> {
        let this->_debug = debug;

        return this;
    }

    /**
     * 打印数据。
     * 
     * @param mixed data
     * @return void
     */
    public function dump(var data) -> void {
        if (typeof data == "array") {
            echo "<pre>";
            print_r(data);
            echo "</pre>";
        } else {
            echo data;
        }

        exit(0);
    }

    /**
     * 获取当前系统时间。
     * 
     * @return int
     */
    public function cts() -> int {
        return time() + this->time_offset;
    }

    /**
     * 系统环境设置。
     * 
     * @return void
     */
    private function setup() -> void {
        date_default_timezone_set(this->timezone);

        register_shutdown_function([this, "shutdown"]);

        // 注册异常处理回调方法.
        set_exception_handler([this, "defExceptionHandler"]);
        set_error_handler([this, "defErrorHandler"], this->error_level);

        // 初始化必需的 IDb/ILogger 实例对象 ...
        let this->db     = new \DotPHP\DB\DbPdo(this);
        let this->logger = new \DotPHP\Core\GenericLogger(this);

        this->logger->setModule(this->log_module)
                    ->setMode(this->log_mode)
                    ->setLevel(this->log_level);

        this->db->set(this->db_parameter);
    }
}