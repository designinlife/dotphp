namespace DotPHP;

/**
 * DotPHP 常量定义。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
final class Dot {
    // PDO 操作常量
    // --------------------------------------[BEGIN]--
    const SQL_TYPE_INSERT    = 1;
    const SQL_TYPE_UPDATE    = 2;
    const SQL_TYPE_DELETE    = 3;
    const SQL_TYPE_DDL       = 4;
    const SQL_TYPE_FETCH     = 5;
    const SQL_TYPE_FETCH_ALL = 6;
    const SQL_TYPE_SCALAR    = 7;
    // --------------------------------------[END]----

    // ILogger 常量
    // --------------------------------------[BEGIN]--
    const LOG_OFF   = 0;
    const LOG_FATAL = 100;
    const LOG_ERROR = 200;
    const LOG_WARN  = 300;
    const LOG_INFO  = 400;
    const LOG_DEBUG = 500;
    const LOG_TRACE = 600;
    const LOG_ALL   = 9999;

    const LOG_OUT_CONSOLE    = 1;
    const LOG_OUT_DAILY_FILE = 2;
    // --------------------------------------[END]----

    /**
     * 系统根目录。
     *
     * @var string
     */
    static private sys_root = null;

    /**
     * DotPHP 环境初始化方法。
     * 
     * @param string   sys_root_dir
     * @param callable class_auto_handler
     * @param int      error_level
     * @return void
     */
    static public function setup(string sys_root_dir, var class_auto_handler = null, int error_level = 32759) -> void {
        let self::sys_root = rtrim(sys_root_dir, "/\\") . DIRECTORY_SEPARATOR;

        error_reporting(error_level);

        if (typeof class_auto_handler == "callable") {
            spl_autoload_register(class_auto_handler);
        } else {
            spl_autoload_register("\DotPHP\Dot::def_class_auto_handler");
        }
    }

    /**
     * 获取系统根目录路径。
     * 
     * @return string
     */
    static public function getRootDirectory() -> string {
        return self::sys_root;
    }

    /**
     * SPL 类自动加载处理器。
     * 
     * @param string class_name
     * @return void
     */
    static public function def_class_auto_handler(string class_name) -> void {
        var file;

        // 设置 Twig 模版引擎支持 ...
        if (0 === strpos(class_name, "Twig")) {
            let file = self::sys_root . "libs" . DIRECTORY_SEPARATOR . str_replace("\0", "", str_replace("_", DIRECTORY_SEPARATOR, class_name)) . ".php";
        } elseif (0 === strpos(class_name, "Application")) {
            let file = self::sys_root . str_replace("\\", DIRECTORY_SEPARATOR, class_name) . ".php";
        } else {
            let file = self::sys_root . "libs" . DIRECTORY_SEPARATOR . str_replace("\\", DIRECTORY_SEPARATOR, class_name) . ".php";
        }

        require file;
    }
}