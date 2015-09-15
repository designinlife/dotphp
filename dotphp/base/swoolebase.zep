namespace DotPHP\Base;

/**
 * DotPHP - 基于 Swoole Socket 的控制器基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class SwooleBase extends \DotPHP\Base\DotBase implements \DotPHP\Interfaces\IController {
    /**
     * 构造函数。
     * 
     * @param \DotPHP\SwooleBootstrap bootstrap
     */
    public function __construct(<\DotPHP\SwooleBootstrap> bootstrap) {
        parent::__construct(bootstrap);
    }

    /**
     * 初始化事件。
     * 
     * @return void
     */
    public function initialize() -> void {}

    /**
     * 在目标方法调用之前触发此事件。
     * 
     * @return void
     */
    public function before() -> void {}
    
    /**
     * 在目标方法调用之后触发此事件。
     * 
     * @return void
     */
    public function after() -> void {}
}