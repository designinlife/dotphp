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

    private data_item = null;

    /**
     * 构造函数。
     * 
     * @param string controller 控制器名称。
     * @param string method     方法名称。
     * @param array  parameters 参数集合。
     * @param array  data_item  命令数据集合。
     */
    public function __construct(string controller, string method, array parameters = null, array data_item = null) {
        let this->controller = controller;
        let this->method = method;
        let this->parameters = parameters;
        let this->data_item = data_item;
    }

    /**
     * 获取控制器名称。
     * 
     * @return string
     */
    public function getController() -> string {
        return this->controller;
    }

    /**
     * 获取方法名称。
     * 
     * @return string
     */
    public function getMethod() -> string {
        return this->method;
    }

    /**
     * 获取参数集合。
     * 
     * @return array|null
     */
    public function getParameters() -> array|null {
        return this->parameters;
    }

    /**
     * 获取命令数据集合。
     * 
     * @return array|null
     */
    public function getDataItem() -> array|null {
        return this->data_item;
    }
}