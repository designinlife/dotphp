namespace DotPHP\Interfaces;

/**
 * DotPHP - 标准控制器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface IController {
    /**
     * 初始化事件。
     * 
     * @return void
     */
    public function initialize() -> void;

    /**
     * 在目标方法调用之前触发此事件。
     * 
     * @return void
     */
    public function before() -> void;

    /**
     * 在目标方法调用之后触发此事件。
     * 
     * @return void
     */
    public function after() -> void;
}