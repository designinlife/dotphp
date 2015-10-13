
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP 数据库接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IDb) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, IDb, dotphp, interfaces_idb, dotphp_interfaces_idb_method_entry);

	return SUCCESS;

}

/**
 * 设置 DB 参数。
 * 
 * @param \DotPHP\Bean\DbParameter param
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, set);

/**
 * 开启事务。
 * 
 * @return boolean
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, begin);

/**
 * 提交事务。
 * 
 * @return boolean
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, commit);

/**
 * 回滚事务。
 * 
 * @return boolean
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, rollback);

/**
 * 执行一条或多条 SQL 语句并返回影响的行数。
 * 
 * @param array|string sql
 * @return int
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, exec);

/**
 * 执行 INSERT/UPDATE/DELETE 语句并返回影响的行数或 AUTO_INCREMENT 自增值。
 * 
 * @param string sql    指定 SQL 语句。
 * @param array  params 指定参数集合。
 * @param int    type   指定 SQL 查询类型。(注: 请务必使用 DOTPHP_DB_SQL_* 常量定义。)
 * @return var
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, execute);

/**
 * 查询单行记录。
 * 
 * @param string sql
 * @param array  params
 * @return array
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, get);

/**
 * 查询全部记录。
 * 
 * @param string sql
 * @param array  params
 * @return array
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, all);

/**
 * 查询单行、单列数据。
 * 
 * @param string sql
 * @param array  params
 * @return var
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, scalar);

/**
 * PING 数据库服务器。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, ping);

/**
 * 切换数据库上下文。
 * 
 * @param string db_name
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, changedb);

/**
 * 连接数据库服务器。
 * 
 * @return void
 * @throw \DotPHP\ArgumentException
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, connect);

/**
 * 关闭数据库连接。
 * 
 * @return void
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, close);

/**
 * 指示是否已连接 DB 服务器？
 * 
 * @return boolean
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IDb, isConnected);

