namespace DotPHP;

/**
 * 数据库操作异常。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class DbException extends \DotPHP\BaseException {
    /**
     * 当前查询的 SQL 语句。
     * 
     * @var string
     */
    private sql = null;

    /**
     * 构造函数。
     * 
     * @param string message
     * @param int code
     * @param string sql
     * @param \Exception previous
     */
    public function __construct(string message = null, int code = 0, string sql, <\Exception> previous = null) {
        parent::__construct(message, code, previous);

        let this->sql = sql;
    }

    /**
     * 获取当前查询的 SQL 语句。
     * 
     * @return string
     */
    final public function getSql() -> string {
        return this->sql;
    }

    /**
     * 打印输出。
     * 
     * @return string
     */
    public function __toString() {
        return this->message . " | 查询: " . this->sql;
    }
}