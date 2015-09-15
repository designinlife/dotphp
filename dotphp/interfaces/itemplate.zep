namespace DotPHP\Interfaces;

/**
 * DotPHP 模板引擎接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface ITemplate {
    /**
     * 构造函数。
     * 
     * @param \DotPHP\WebBootstrap bootstrap 上下文对象。
     * @return void
     */
    public function __construct(<\DotPHP\WebBootstrap> bootstrap) -> void;

    /**
     * 模板变量赋值。
     * 
     * @param string key
     * @param mixed value
     * @return \DotPHP\Interfaces\ITemplate
     */
    public function assign(var key, var value) -> <\DotPHP\Interfaces\ITemplate>;

    /**
     * 输出模板内容。
     * 
     * @param string tpl_file 模板文件名称。
     * @return void
     */
    public function display(string tpl_file) -> void;
}