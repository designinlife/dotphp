namespace DotPHP\DB;

/**
 * DotPHP 数据库操作类。(基于 PDO 扩展)
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class DbPdo extends \DotPHP\Base\DotBase implements \DotPHP\Interfaces\IDb {
    /**
     * 数据库参数对象。
     * 
     * @var \DotPHP\Bean\DbParameter
     */
    private dbParameter = null;

    /**
     * 是否已连接 DB 服务器？
     * 
     * @var boolean
     */
    private is_connected = false;

    /**
     * PDO 对象。
     * 
     * @var \PDO
     */
    private dbo = null;

    /**
     * 事务计数。
     * 
     * @var int
     */
    private transactions = 0;

    /**
     * 构造函数。
     * 
     * @param \DotPHP\AbstractBootstrap bootstrap
     */
    public function __construct(<\DotPHP\AbstractBootstrap> bootstrap) {
        parent::__construct(bootstrap);
    }

    /**
     * 析构函数。
     * 
     * @return void
     */
    public function __destruct() {
        unset this->dbParameter;
    }

    /**
     * 设置 DB 参数。
     * 
     * @param \DotPHP\Bean\DbParameter param
     * @return void
     */
    public function set(<\DotPHP\Bean\DbParameter> param) -> void {
        let this->dbParameter = param;
    }

    /**
     * 开启事务。
     * 
     * @return boolean
     */
    public function begin() -> boolean {
        if !this->is_connected {
            this->connect();
        }

        if !this->dbo {
            throw new \DotPHP\DbException("检测到无效的 PDO 实例对象。");
        }

        let this->transactions++;

        if this->transactions == 1 {
            this->dbo->exec("BEGIN");

            return true;
        }

        return false;
    }

    /**
     * 提交事务。
     * 
     * @return boolean
     */
    public function commit() -> boolean {
        if !this->dbo {
            throw new \DotPHP\DbException("检测到无效的 PDO 实例对象。");
        }

        if this->transactions == 1 {
            this->dbo->exec("COMMIT");

            let this->transactions--;

            return true;
        } else {
            let this->transactions--;
        }

        return false;
    }

    /**
     * 回滚事务。
     * 
     * @return boolean
     */
    public function rollback() -> boolean {
        if !this->dbo {
            throw new \DotPHP\DbException("检测到无效的 PDO 实例对象。");
        }

        if this->transactions == 1 {
            let this->transactions = 0;

            this->dbo->exec("ROLLBACK");

            return true;
        } else {
            let this->transactions--;
        }

        return false;
    }

    /**
     * 执行一条或多条 SQL 语句并返回影响的行数。
     * 
     * @param array|string sql
     * @return int
     * @throw \DotPHP\DbException
     */
    public function exec(var sql) -> int {
        if !this->is_connected {
            this->connect();
        }

        if !this->dbo {
            throw new \DotPHP\DbException("检测到无效的 PDO 实例对象。");
        }

        var e;
        int affected = 0;

        if (typeof sql == "array") {
            var v;

            try {
                for v in sql {
                    let affected += ( int ) this->dbo->exec(v);
                }
            } catch \PDOException, e {
                throw new \DotPHP\DbException(e->getMessage(), e->getCode(), v);
            }
        } else {
            try {
                let affected += ( int ) this->dbo->exec(sql);
            } catch \PDOException, e {
                throw new \DotPHP\DbException(e->getMessage(), e->getCode(), sql);
            }
        }

        return affected;
    }

    /**
     * 执行 INSERT/UPDATE/DELETE 语句并返回影响的行数或 AUTO_INCREMENT 自增值。
     * 
     * @param string sql    指定 SQL 语句。
     * @param array  params 指定参数集合。
     * @param int    type   指定 SQL 查询类型。(注: 请务必使用 \DotPHP\Dot::SQL_TYPE_* 常量定义。)
     * @return var
     */
    public function execute(string sql, array params, int type) -> var {
        if !this->is_connected {
            this->connect();
        }

        if !this->dbo {
            throw new \DotPHP\DbException("检测到无效的 PDO 实例对象。");
        }

        var d, e, sth, key, value;

        let d = false;

        try {
            let sth = this->dbo->prepare(sql);

            if !(empty params) {
                for key, value in params {
                    if (typeof value == "array") {
                        sth->bindValue(1 + key, value[0], value[1]);
                    } else {
                        sth->bindValue(1 + key, value);
                    }
                }
            }

            sth->execute();
        } catch \PDOException, e {
            throw e;
        }

        switch type {
            case \DotPHP\Dot::SQL_TYPE_INSERT: // INSERT
                let d = this->dbo->lastInsertId();
                break;
            case \DotPHP\Dot::SQL_TYPE_UPDATE: // UPDATE
            case \DotPHP\Dot::SQL_TYPE_DELETE: // DELETE
                let d = sth->rowCount();
                break;
            case \DotPHP\Dot::SQL_TYPE_DDL:    // DDL
                let d = true;
                break;
            case \DotPHP\Dot::SQL_TYPE_FETCH:
                let d = sth->{"fetch"}(2);

                if empty d {
                    let d = false;
                }
                break;
            case \DotPHP\Dot::SQL_TYPE_FETCH_ALL:
                let d = sth->fetchAll(2);

                if empty d {
                    let d = false;
                }
                break;
            case \DotPHP\Dot::SQL_TYPE_SCALAR:
                let d = sth->fetchColumn(0);
                break;
            default:
                throw new \DotPHP\ArgumentException("当前 SQL 类型不被支持。");
        }

        sth->closeCursor();
        // let sth = null;

        return d;
    }

    /**
     * 查询单行记录。
     * 
     * @param string sql
     * @param array  params
     * @return array
     */
    public function get(string sql, array params = null) -> array | boolean {
        var d;

        let d = this->execute(sql, params, \DotPHP\Dot::SQL_TYPE_FETCH);

        return d;
    }

    /**
     * 查询全部记录。
     * 
     * @param string sql
     * @param array  params
     * @return array
     */
    public function all(string sql, array params = null) -> array | boolean {
        var d;

        let d = this->execute(sql, params, \DotPHP\Dot::SQL_TYPE_FETCH_ALL);

        return d;
    }

    /**
     * 查询单行、单列数据。
     * 
     * @param string sql
     * @param array  params
     * @return var
     */
    public function scalar(string sql, array params = null) -> string | int | boolean {
        var d;

        let d = this->execute(sql, params, \DotPHP\Dot::SQL_TYPE_SCALAR);

        return d;
    }

    /**
     * PING 数据库服务器。
     * 
     * @return void
     */
    public function ping() -> void {
        if this->dbo {
            var e;

            try {
                this->dbo->query("SELECT 1");
            } catch \PDOException, e {
                this->close();
                this->connect();
            }
        } else {
            this->connect();
        }
    }

    /**
     * 切换数据库上下文。
     * 
     * @param string db_name
     * @return void
     */
    public function changedb(string db_name) -> void {
        if !this->is_connected {
            this->connect();
        }

        if !this->dbo {
            throw new \DotPHP\DbException("检测到无效的 PDO 实例对象。");
        }

        this->dbo->exec("USE `" . db_name . "`");
    }

    /**
     * 连接数据库服务器。
     * 
     * @return void
     * @throw \DotPHP\ArgumentException
     * @throw \DotPHP\DbException
     */
    public function connect() -> void {
        if this->dbParameter == null {
            throw new \DotPHP\ArgumentException("尚未设置 DB 连接参数。");
        }

        if false == this->is_connected {
            string dsn = "";
            array opts = [];
            var e;

            let opts[3]    = 2;
            let opts[17]   = false;
            let opts[0]    = false;
            let opts[12]   = false;
            let opts[8]    = 0;
            let opts[19]   = 2;
            let opts[20]   = 0;
            let opts[1002] = "SET NAMES `" . this->dbParameter->getCharset() . "`";

            if empty this->dbParameter->getUnixSocket() {
                let dsn = "mysql:host=" . this->dbParameter->getHost() . ";port=" . this->dbParameter->getPort() . ";dbname=" . this->dbParameter->getDb() . ";";
            } else {
                let dsn = "mysql:unix_socket=" . this->dbParameter->getUnixSocket() . ";dbname=" . this->dbParameter->getDb() . ";";
            }

            try {
                let this->dbo = new \PDO(dsn, this->dbParameter->getUser(), this->dbParameter->getPass(), opts);
            } catch \PDOException, e {
                throw new \DotPHP\DbException("数据库连接失败。(" . this->dbParameter->getHost() . ")");
            }

            let this->is_connected = true;
        }
    }

    /**
     * 关闭数据库连接。
     * 
     * @return void
     */
    public function close() -> void {
        if this->dbo {
            let this->dbo = null;
        }

        let this->is_connected = false;
    }

    /**
     * 指示是否已连接 DB 服务器？
     * 
     * @return boolean
     */
    public function isConnected() -> boolean {
        return this->is_connected;
    }
}