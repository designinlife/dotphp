namespace DotPHP\Interfaces;

/**
 * DotPHP 命令行进程接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface IProcess {
    /**
     * 构造函数。
     * 
     * @param \DotPHP\CliBootstrap bootstrap 上下文对象。
     * @return void
     */
    public function __construct(<\DotPHP\CliBootstrap> bootstrap) -> void;

    /**
     * 初始化事件。
     * 
     * @return void
     */
    public function initialize() -> void;

    /**
     * 执行任务。
     * 
     * @return void
     */
    public function execute() -> void;
}