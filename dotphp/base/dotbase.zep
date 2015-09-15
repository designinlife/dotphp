namespace DotPHP\Base;

/**
 * DotPHP 基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class DotBase {
    /**
     * AbstractBootstrap 上下文对象。
     * 
     * @var \DotPHP\AbstractBootstrap|\DotPHP\WebBootstrap|\DotPHP\SwooleBootstrap
     */
    protected bootstrap = null;

    /**
     * 构造函数。
     * 
     * @param \DotPHP\AbstractBootstrap bootstrap
     */
    public function __construct(<\DotPHP\AbstractBootstrap> bootstrap) {
        let this->bootstrap = bootstrap;
    }

    /**
     * 析构函数。
     * 
     */
    public function __destruct() {
        unset this->bootstrap;
    }
}