namespace DotPHP\Interfaces;

/**
 * DotPHP 路由解析器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface IRouteParser {
    /**
     * 解析路由并返回消息对象。
     * 
     * @return \DotPHP\Bean\RouteMessage
     */
    public function parse() -> <\DotPHP\Bean\RouteMessage>;
}