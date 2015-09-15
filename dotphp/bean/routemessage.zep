namespace DotPHP\Bean;

/**
 * 路由解析结果对象。
 * 
 * @author Lei Lee
 * @version 0.1a
 * @date 2015-09-09
 */
final class RouteMessage {
    private controller = "Index";

    private method = "defaults";

    private parameters = null;

    public function __construct(string controller, string method, array parameters = null) {
        let this->controller = controller;
        let this->method = method;
        let this->parameters = parameters;
    }

    public function getController() -> string {
        return this->controller;
    }

    public function getMethod() -> string {
        return this->method;
    }

    public function getParameters() -> array|null {
        return this->parameters;
    }
}