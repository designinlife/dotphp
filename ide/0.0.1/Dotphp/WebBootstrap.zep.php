<?php

namespace DotPHP;

/**
 * DotPHP - 基于 HTTP 协议的启动器。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class WebBootstrap extends \DotPHP\AbstractBootstrap
{
    /**
     * 模板目录。
     *
     * @var string
     */
    private $template_dir = null;

    /**
     * 模板编译目录。
     *
     * @var string
     */
    private $template_cache_dir = null;

    /**
     * 模板类名。
     *
     * @var string
     */
    private $template_class = null;

    /**
     * ITemplate 模板对象实例。
     *
     * @var \DotPHP\Interfaces\ITemplate
     */
    private $template_instance = null;

    /**
     * 当前执行的 IController 实例。
     *
     * @var \DotPHP\Interfaces\IController
     */
    protected $ctl_instance = null;


    /**
     * 初始化事件。
     *
     * @return void 
     */
    protected function initialize() {}

    /**
     * 初始化完成事件。
     *
     * @return void 
     */
    protected function initializeComplete() {}

    /**
     * 执行路由解析。
     *
     * @return \DotPHP\Bean\RouteMessage 
     */
    protected function route() {}

    /**
     * 执行验证。
     *
     * @return void 
     */
    protected function validate() {}

    /**
     * 执行程序。
     *
     * @param \DotPHP\Bean\RouteMessage $route_message 
     * @return void 
     */
    protected function execute(\DotPHP\Bean\RouteMessage $route_message) {}

    /**
     * 获取模板目录。
     *
     * @return string 
     */
    public function getTemplateDirectory() {}

    /**
     * 设置模板目录。
     *
     * @param string $dir 
     * @return \DotPHP\WebBootstrap 
     */
    public function setTemplateDirectory($dir) {}

    /**
     * 获取模板编译目录。
     *
     * @return string 
     */
    public function getTemplateCacheDirectory() {}

    /**
     * 设置模板编译目录。
     *
     * @param string $dir 
     * @return \DotPHP\WebBootstrap 
     */
    public function setTemplateCacheDirectory($dir) {}

    /**
     * 设置模板类名。
     *
     * @param string $cls_name 
     * @return \DotPHP\WebBootstrap 
     */
    public function setTemplateClass($cls_name) {}

    /**
     * 获取 ITemplate 对象实例。
     *
     * @return \DotPHP\Interfaces\ITemplate 
     */
    public function getTemplate() {}

}
