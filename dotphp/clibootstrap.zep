namespace DotPHP;

/**
 * DotPHP - 基于 CLI 命令行的启动器。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class CliBootstrap extends \DotPHP\AbstractBootstrap {
    /**
     * 初始化完成事件。
     * 
     * @return void
     */
    protected function initializeComplete() -> void {}

    /**
     * 执行路由解析。
     * 
     * @return \DotPHP\Bean\RouteMessage
     */
    protected function route() -> <\DotPHP\Bean\RouteMessage> | null {
        return null;
    }

    /**
     * 执行验证。
     * 
     * @return void
     */
    protected function validate() -> void {}

    /**
     * 执行程序。
     * 
     * @param \DotPHP\Bean\RouteMessage route_message
     * @return void
     */
    protected function execute(<\DotPHP\Bean\RouteMessage> route_message) -> void {
        if empty this->argv[1] {
            throw new \DotPHP\ArgumentException("未指定命令名称。(Usage: /usr/bin/php cli.php [命令名称])");
        }

        var cls_n;
        var cls_o;

        let cls_n = call_user_func_array("\DotPHP\Utils\StringUtil::ns", [this->getControllerNS(), this->argv[1]]);
        let cls_o = new {cls_n}(this);
        
        cls_o->initialize();
        cls_o->execute();
    }
}