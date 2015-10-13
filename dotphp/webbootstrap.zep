namespace DotPHP;

/**
 * DotPHP - 基于 HTTP 协议的启动器。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class WebBootstrap extends \DotPHP\AbstractBootstrap {
    /**
     * 模板目录。
     * 
     * @var string
     */
    private template_dir = null;

    /**
     * 模板编译目录。
     * 
     * @var string
     */
    private template_cache_dir = null;

    /**
     * 模板类名。
     * 
     * @var string
     */
    private template_class = null;

    /**
     * ITemplate 模板对象实例。
     * 
     * @var \DotPHP\Interfaces\ITemplate
     */
    private template_instance = null;

    /**
     * 当前执行的 IController 实例。
     * 
     * @var \DotPHP\Interfaces\IController
     */
    protected ctl_instance = null;

    /**
     * 初始化事件。
     * 
     * @return void
     */
    protected function initialize() -> void {
        parent::initialize();

        var cls_n;
        let cls_n = this->template_class;

        let this->template_instance = new {cls_n}(this);
    }

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
        if this->route_parser != null {
            return this->route_parser->parse();
        } else {
            return new \DotPHP\Bean\RouteMessage("Index", "defaults");
        }
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
        var cls_n, cls_m;

        let cls_n = this->getControllerNS() . "\\" . route_message->getController();
        let cls_m = route_message->getMethod();
        let this->ctl_instance = new {cls_n}(this);

        this->ctl_instance->initialize();
        this->ctl_instance->before();
        call_user_func_array([this->ctl_instance, cls_m], []);
        this->ctl_instance->after();
    }

    /**
     * 缺省异常处理。
     * 
     * @return void
     */
    public function defExceptionHandler(<\Exception> ex) -> void {
        echo "<!DOCTYPE html><html lang=\"zh-CN\"><head><title>系统错误!</title><meta charset=\"UTF-8\" /><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"/><style type=\"text/css\">";
        echo "html, body { font-family: SimSun, Tahoma, Arial; font-size: 12px; }";
        echo "#container { margin: 18px; }";
        echo "p { line-height: 20px; }";
        echo "pre { padding: 12px; background: #FFC; -moz-border-radius: 6px; -webkit-border-radius: 6px; border-radius: 6px; }";
        echo "</style></head><body>";

        echo "<div id=\"container\"><h1 style=\"font-family: Arial;\">Exception Found!</h1><p>", ex->getMessage(), "</p>";

        if this->_debug {
            echo "<pre>", ex->getTraceAsString(), "</pre></div>";
        }
        
        echo "</body></html>";
        exit(2);
    }

    /**
     * 获取模板目录。
     * 
     * @return string
     */
    public function getTemplateDirectory() -> string {
        return this->template_dir;
    }

    /**
     * 设置模板目录。
     * 
     * @param string dir
     * @return \DotPHP\WebBootstrap
     */
    public function setTemplateDirectory(string dir) -> <\DotPHP\WebBootstrap> {
        let this->template_dir = dir;

        return this;
    }

    /**
     * 获取模板编译目录。
     * 
     * @return string
     */
    public function getTemplateCacheDirectory() -> string {
        return this->template_cache_dir;
    }

    /**
     * 设置模板编译目录。
     * 
     * @param string dir
     * @return \DotPHP\WebBootstrap
     */
    public function setTemplateCacheDirectory(string dir) -> <\DotPHP\WebBootstrap> {
        let this->template_cache_dir = dir;

        return this;
    }

    /**
     * 设置模板类名。
     * 
     * @param string cls_name
     * @return \DotPHP\WebBootstrap
     */
    public function setTemplateClass(string cls_name) -> <\DotPHP\WebBootstrap> {
        let this->template_class = cls_name;

        return this;
    }

    /**
     * 获取 ITemplate 对象实例。
     * 
     * @return \DotPHP\Interfaces\ITemplate
     */
    public function getTemplate() -> <\DotPHP\Interfaces\ITemplate> {
        return this->template_instance;
    }
}