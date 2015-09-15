<?php

namespace DotPHP\Bean;

/**
 * 路由解析结果对象。
 *
 * @author Lei Lee
 * @version 0.1a
 * @date 2015-09-09
 */
final class RouteMessage
{

    private $controller = "Index";


    private $method = "defaults";


    private $parameters = null;


    /**
     * @param string $controller 
     * @param string $method 
     * @param array $parameters 
     */
    public function __construct($controller, $method, $parameters = null) {}

    /**
     * @return string 
     */
    public function getController() {}

    /**
     * @return string 
     */
    public function getMethod() {}

    /**
     * @return array|null 
     */
    public function getParameters() {}

}
