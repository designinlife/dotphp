<?php

namespace DotPHP\Base;

/**
 * DotPHP - 基于 HTTP 的控制器基类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class WebControllerBase extends \DotPHP\Base\DotBase implements \DotPHP\Interfaces\IController
{
    /**
     * 是否 POST 请求方式？
     *
     * @var boolean
     */
    protected $_isPostback = false;


    /**
     * 构造函数。
     *
     * @param \DotPHP\WebBootstrap $bootstrap 
     */
    public function __construct(\DotPHP\WebBootstrap $bootstrap) {}

    /**
     * 指示当前是否 POST 请求方式？
     *
     * @return boolean 
     */
    public function isPostback() {}

    /**
     * 初始化事件。
     *
     * @return void 
     */
    public function initialize() {}

    /**
     * 在目标方法调用之前触发此事件。
     *
     * @return void 
     */
    public function before() {}

    /**
     * 在目标方法调用之后触发此事件。
     *
     * @return void 
     */
    public function after() {}

}
