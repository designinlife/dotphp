namespace DotPHP\Base;

/**
 * DotPHP - 基于 HTTP 的控制器基类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class WebControllerBase extends \DotPHP\Base\DotBase implements \DotPHP\Interfaces\IController {
    /**
     * 是否 POST 请求方式？
     *
     * @var boolean
     */
    protected _isPostback = false;

    /**
     * 构造函数。
     * 
     * @param \DotPHP\WebBootstrap bootstrap
     */
    public function __construct(<\DotPHP\WebBootstrap> bootstrap) {
        parent::__construct(bootstrap);

        let this->_isPostback = 0 === strcmp("POST", _SERVER["REQUEST_METHOD"]) ? true : false;
    }

    /**
     * 指示当前是否 POST 请求方式？
     * 
     * @return boolean
     */
    public function isPostback() -> boolean {
        return this->_isPostback;
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