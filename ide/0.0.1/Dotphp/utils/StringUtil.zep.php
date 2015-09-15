<?php

namespace DotPHP\Utils;

/**
 * DotPHP 字符串工具类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class StringUtil
{

    /**
     * 在查询中使用一个字符串。
     *
     * @param var $data 
     * @return var 
     */
    static public function quote($data) {}

    /**
     * 替换字符串变量。
     *
     * @param string $message 指定消息文本内容。
     * @param array $vars 指定 HashMap 键值对列表。
     * @param string $prefix 指定变量命名规范前缀字符。(可选 | 默认: % 百分号)
     * @return string 
     */
    static public function translate($message, $vars, $prefix = "%") {}

    /**
     * 字符串变量替换。(支持可变参数)
     *
     * @example
     * [Call]:   Util::substitute('My name is {1}, an alias, also called {0}! {2}-year-old.', 'Lei', 'Li Lei', 30);
     * [Output]: My name is Li Lei, an alias, also called Lei! 30-year-old.
     * @return string 
     */
    static public function substitute() {}

    /**
     * 获取字符串真实长度。(注: 中文以 2 个字节计算)
     *
     * @param string $str 指定测试字符串。
     * @param string $encoding 指定字符串编码。(默认值: UTF-8)
     * @return int 
     */
    static public function length($str, $encoding = "UTF-8") {}

    /**
     * 生成 alpha ID 编码。
     *
     * @param mixed $input 
     * @param boolean $to_num Reverses translation when true
     * @param int|boolean $pad_up Number or boolean padds the result up to a specified length
     * @param string $pass_key Supplying a password makes it harder to calculate the original ID
     * @param int|string $in String or long input to translate
     * @return string 
     */
    static public function alphaID($input, $to_num = false, $pad_up = false, $pass_key = null) {}

    /**
     * 生成 GUID 全球唯一标识。
     *
     * @return string 
     */
    static public function guid() {}

    /**
     * 生成完全限定类名。
     *
     * @return string 
     */
    static public function ns() {}

    /**
     * IP 地址转换为整数。
     *
     * @param mixed $addr 
     * @param string $$ip_addr 指定 IP 地址。
     * @return int 
     */
    static public function ip($addr) {}

    /**
     * 对称加密算法 - (加密)。
     *
     * @throws TypeException
     * @param string $s 
     * @param string $secure_key 
     * @return string 
     */
    static public function encrypt($s, $secure_key) {}

    /**
     * 对称加密算法 - (解密)。
     *
     * @throws <\DotPHP\ArgumentException>
     * @param string $s 
     * @param string $secure_key 
     * @return string 
     */
    static public function decrypt($s, $secure_key) {}

}
