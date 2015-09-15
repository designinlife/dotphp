<?php

namespace DotPHP\Interfaces;

/**
 * DotPHP 数据库接口。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface IDb
{

    /**
     * 设置 DB 参数。
     *
     * @param \DotPHP\Bean\DbParameter $param 
     * @return void 
     */
    public function set(\DotPHP\Bean\DbParameter $param);

    /**
     * 开启事务。
     *
     * @return void 
     */
    public function begin();

    /**
     * 提交事务。
     *
     * @return void 
     */
    public function commit();

    /**
     * 回滚事务。
     *
     * @return void 
     */
    public function rollback();

    /**
     * 执行一条或多条 SQL 语句并返回影响的行数。
     *
     * @param array|string $sql 
     * @return int 
     */
    public function exec($sql);

    /**
     * 执行 INSERT/UPDATE/DELETE 语句并返回影响的行数或 AUTO_INCREMENT 自增值。
     *
     * @param string $sql 指定 SQL 语句。
     * @param array $params 指定参数集合。
     * @param int $type 指定 SQL 查询类型。(注: 请务必使用 DOTPHP_DB_SQL_* 常量定义。)
     * @return var 
     */
    public function execute($sql, $params, $type);

    /**
     * 查询单行记录。
     *
     * @param string $sql 
     * @param array $params 
     * @return array 
     */
    public function get($sql, $params = null);

    /**
     * 查询全部记录。
     *
     * @param string $sql 
     * @param array $params 
     * @return array 
     */
    public function all($sql, $params = null);

    /**
     * 查询单行、单列数据。
     *
     * @param string $sql 
     * @param array $params 
     * @return var 
     */
    public function scalar($sql, $params = null);

    /**
     * PING 数据库服务器。
     *
     * @return void 
     */
    public function ping();

    /**
     * 切换数据库上下文。
     *
     * @param string $db_name 
     * @return void 
     */
    public function changedb($db_name);

    /**
     * 连接数据库服务器。
     *
     * @throw \DotPHP\ArgumentException
     * @return void 
     */
    public function connect();

    /**
     * 关闭数据库连接。
     *
     * @return void 
     */
    public function close();

    /**
     * 指示是否已连接 DB 服务器？
     *
     * @return boolean 
     */
    public function isConnected();

}
