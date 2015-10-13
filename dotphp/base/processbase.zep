namespace DotPHP\Base;

/**
 * DotPHP 进程基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class ProcessBase {
    /**
     * CliBootstrap 上下文对象。
     * 
     * @var \DotPHP\CliBootstrap
     */
    protected bootstrap = null;

    /**
     * 构造函数。
     * 
     * @param \DotPHP\CliBootstrap bootstrap
     */
    public function __construct(<\DotPHP\CliBootstrap> bootstrap) {
        let this->bootstrap = bootstrap;
    }

    /**
     * 析构函数。
     * 
     */
    public function __destruct() {
        unset this->bootstrap;
    }

    /**
     * 初始化事件。
     * 
     * @return void
     */
    public function initialize() {}
}