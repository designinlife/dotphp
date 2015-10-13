
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * 基于 Swoole 扩展的 TCP 客户端工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Core_SocketClient) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Core, SocketClient, dotphp, core_socketclient, dotphp_core_socketclient_method_entry, 0);

	zend_declare_property_string(dotphp_core_socketclient_ce, SL("host"), "127.0.0.1", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(dotphp_core_socketclient_ce, SL("port"), 9501, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(dotphp_core_socketclient_ce, SL("instance"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数。
 * 
 * @param string host TCP 主机地址。
 * @param int port 连接端口。
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, __construct) {

	int port;
	zval *host_param = NULL, *port_param = NULL, *_0;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host_param, &port_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);


	zephir_update_property_this(this_ptr, SL("host"), host TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, port);
	zephir_update_property_this(this_ptr, SL("port"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 析构函数。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, __destruct) {

	

	zephir_unset_property(this_ptr, "instance" TSRMLS_CC);

}

/**
 * 连接主机。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, connect) {

	zval *_0, *_1$$3, *_2$$3 = NULL, *_3$$3, *_4$$3 = NULL, *_5$$3, *_6$$3, *_7$$4, *_8$$4, *_9$$4, *_10$$4, *_11$$4, *_12$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zephir_get_internal_ce(SS("swoole_client") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 0, _2$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("instance"), _1$$3 TSRMLS_CC);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("host"), PH_NOISY_CC);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_LONG(_2$$3, -1);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "connect", NULL, 0, _5$$3, _6$$3, _2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(_4$$3))) {
			ZEPHIR_INIT_VAR(_7$$4);
			object_init_ex(_7$$4, dotphp_socketexception_ce);
			_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("host"), PH_NOISY_CC);
			_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
			_10$$4 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_11$$4);
			zephir_read_property(&_11$$4, _10$$4, SL("errCode"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_12$$4);
			ZEPHIR_CONCAT_SVSVSVS(_12$$4, "连接主机 ", _8$$4, ":", _9$$4, " 失败。(#", _11$$4, ")");
			ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", NULL, 18, _12$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$4, "dotphp/core/socketclient.zep", 50 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 断开连接。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, close) {

	zval *_0, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "close", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 发送数据。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, send) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *msg, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &msg);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "send", NULL, 0, msg);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 接收数据。
 * 
 * @param int size
 * @param boolean waitall
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, recv) {

	zend_bool waitall;
	zval *size_param = NULL, *waitall_param = NULL, *_0, *_1, *_2;
	int size, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &size_param, &waitall_param);

	if (!size_param) {
		size = 65535;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!waitall_param) {
		waitall = 0;
	} else {
		waitall = zephir_get_boolval(waitall_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, size);
	ZEPHIR_INIT_VAR(_2);
	if (waitall) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(_0, "recv", NULL, 0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否已连接？
 * 
 * @return void
 */
PHP_METHOD(DotPHP_Core_SocketClient, isConnected) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("instance"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "isconnected", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

