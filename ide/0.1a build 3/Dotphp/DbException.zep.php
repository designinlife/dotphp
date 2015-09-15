<?php

namespace DotPHP;

/**
 * 数据库操作异常。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class DbException extends \DotPHP\BaseException
{
    /**
     * 当前查询的 SQL 语句。
     *
     * @var string
     */
    private $sql = null;


    /**
     * 构造函数。
     *
     * @param string $message 
     * @param int $code 
     * @param string $sql 
     * @param \Exception $previous 
     */
    public function __construct($message = null, $code = 0, $sql, \Exception $previous = null) {}

    /**
     * 获取当前查询的 SQL 语句。
     *
     * @return string 
     */
    final public function getSql() {}

    /**
     * 打印输出。
     *
     * @return string 
     */
    public function __toString() {}

}
