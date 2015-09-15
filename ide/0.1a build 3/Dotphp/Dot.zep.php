<?php

namespace DotPHP;

/**
 * DotPHP 常量定义。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
final class Dot
{

    const SQL_TYPE_INSERT = 1;


    const SQL_TYPE_UPDATE = 2;


    const SQL_TYPE_DELETE = 3;


    const SQL_TYPE_DDL = 4;


    const SQL_TYPE_FETCH = 5;


    const SQL_TYPE_FETCH_ALL = 6;


    const SQL_TYPE_SCALAR = 7;


    const LOG_OFF = 0;


    const LOG_FATAL = 100;


    const LOG_ERROR = 200;


    const LOG_WARN = 300;


    const LOG_INFO = 400;


    const LOG_DEBUG = 500;


    const LOG_TRACE = 600;


    const LOG_ALL = 9999;


    const LOG_OUT_CONSOLE = 1;


    const LOG_OUT_DAILY_FILE = 2;

    /**
     * 系统根目录。
     *
     * @var string
     */
    static private $sys_root = null;


    /**
     * DotPHP 环境初始化方法。
     *
     * @param string $sys_root_dir 
     * @param callable $class_auto_handler 
     * @param int $error_level 
     * @return void 
     */
    static public function setup($sys_root_dir, $class_auto_handler = null, $error_level = 32759) {}

    /**
     * 获取系统根目录路径。
     *
     * @return string 
     */
    static public function getRootDirectory() {}

    /**
     * SPL 类自动加载处理器。
     *
     * @param string $class_name 
     * @return void 
     */
    static public function def_class_auto_handler($class_name) {}

}
