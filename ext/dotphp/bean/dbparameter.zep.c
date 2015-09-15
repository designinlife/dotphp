
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * 适用于 IDb 接口的参数对象。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Bean_DbParameter) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Bean, DbParameter, dotphp, bean_dbparameter, dotphp_bean_dbparameter_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(dotphp_bean_dbparameter_ce, SL("host"), "127.0.0.1", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(dotphp_bean_dbparameter_ce, SL("port"), 3306, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(dotphp_bean_dbparameter_ce, SL("user"), "root", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(dotphp_bean_dbparameter_ce, SL("passwd"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(dotphp_bean_dbparameter_ce, SL("db"), "test", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(dotphp_bean_dbparameter_ce, SL("charset"), "utf8", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(dotphp_bean_dbparameter_ce, SL("unix_socket"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param string host
 * @param int    port
 * @param string user
 * @param string passwd
 * @param string db
 * @param string charset
 * @param string unix_socket
 */
PHP_METHOD(DotPHP_Bean_DbParameter, __construct) {

	int port;
	zval *host_param = NULL, *port_param = NULL, *user_param = NULL, *passwd_param = NULL, *db_param = NULL, *charset_param = NULL, *unix_socket_param = NULL, *_0;
	zval *host = NULL, *user = NULL, *passwd = NULL, *db = NULL, *charset = NULL, *unix_socket = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 2, &host_param, &port_param, &user_param, &passwd_param, &db_param, &charset_param, &unix_socket_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);
	zephir_get_strval(db, db_param);
	if (!charset_param) {
		ZEPHIR_INIT_VAR(charset);
		ZVAL_STRING(charset, "utf8", 1);
	} else {
		zephir_get_strval(charset, charset_param);
	}
	if (!unix_socket_param) {
		ZEPHIR_INIT_VAR(unix_socket);
		ZVAL_EMPTY_STRING(unix_socket);
	} else {
		zephir_get_strval(unix_socket, unix_socket_param);
	}


	zephir_update_property_this(this_ptr, SL("host"), host TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, port);
	zephir_update_property_this(this_ptr, SL("port"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("user"), user TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("passwd"), passwd TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("db"), db TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("charset"), charset TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("unix_socket"), unix_socket TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取主机地址。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getHost) {


	RETURN_MEMBER(this_ptr, "host");

}

/**
 * 设置主机地址。
 * 
 * @param string host
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setHost) {

	zval *host_param = NULL;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_param);

	zephir_get_strval(host, host_param);


	zephir_update_property_this(this_ptr, SL("host"), host TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取端口。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getPort) {


	RETURN_MEMBER(this_ptr, "port");

}

/**
 * 设置端口。
 * 
 * @param int port
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setPort) {

	zval *port_param = NULL;
	zval *port = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port_param);

	zephir_get_strval(port, port_param);


	zephir_update_property_this(this_ptr, SL("port"), port TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取登录帐号。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getUser) {


	RETURN_MEMBER(this_ptr, "user");

}

/**
 * 设置登录帐号。
 * 
 * @param string user
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setUser) {

	zval *user_param = NULL;
	zval *user = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user_param);

	zephir_get_strval(user, user_param);


	zephir_update_property_this(this_ptr, SL("user"), user TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取密码。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getPass) {


	RETURN_MEMBER(this_ptr, "passwd");

}

/**
 * 设置密码。
 * 
 * @param string passwd
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setPass) {

	zval *passwd_param = NULL;
	zval *passwd = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &passwd_param);

	zephir_get_strval(passwd, passwd_param);


	zephir_update_property_this(this_ptr, SL("passwd"), passwd TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取数据库名称。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getDb) {


	RETURN_MEMBER(this_ptr, "db");

}

/**
 * 设置数据库名称。
 * 
 * @param string db
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setDb) {

	zval *db_param = NULL;
	zval *db = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &db_param);

	zephir_get_strval(db, db_param);


	zephir_update_property_this(this_ptr, SL("db"), db TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取字符集。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getCharset) {


	RETURN_MEMBER(this_ptr, "charset");

}

/**
 * 设置字符集。
 * 
 * @param string charset
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setCharset) {

	zval *charset_param = NULL;
	zval *charset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &charset_param);

	zephir_get_strval(charset, charset_param);


	zephir_update_property_this(this_ptr, SL("charset"), charset TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取 UNIX 套接字地址。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_DbParameter, getUnixSocket) {


	RETURN_MEMBER(this_ptr, "unix_socket");

}

/**
 * 设置 UNIX 套接字地址。
 * 
 * @param string unix_socket
 * @return <\DotPHP\Bean\DbParameter>
 */
PHP_METHOD(DotPHP_Bean_DbParameter, setUnixSocket) {

	zval *unix_socket_param = NULL;
	zval *unix_socket = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unix_socket_param);

	zephir_get_strval(unix_socket, unix_socket_param);


	zephir_update_property_this(this_ptr, SL("unix_socket"), unix_socket TSRMLS_CC);
	RETURN_THIS();

}

