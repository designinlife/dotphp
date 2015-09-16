
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * DotPHP - 基于 Swoole 的 TCP Server 启动器。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_SwooleBootstrap) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP, SwooleBootstrap, dotphp, swoolebootstrap, dotphp_abstractbootstrap_ce, dotphp_swoolebootstrap_method_entry, 0);

	/**
	 * 模板目录。
	 * 
	 * @var string
	 */
	zend_declare_property_long(dotphp_swoolebootstrap_ce, SL("port"), 9501, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Swoole 服务器参数选项。
	 * 
	 * @var array
	 */
	zend_declare_property_null(dotphp_swoolebootstrap_ce, SL("server_options"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Swoole 服务实例。
	 * 
	 * @var \swoole_server
	 */
	zend_declare_property_null(dotphp_swoolebootstrap_ce, SL("serv"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Swoole 事件调度器。
	 * 
	 * @var \DotPHP\Interfaces\ISwooleEventDispatcher
	 */
	zend_declare_property_null(dotphp_swoolebootstrap_ce, SL("event_dispatcher"), ZEND_ACC_PRIVATE TSRMLS_CC);

	dotphp_swoolebootstrap_ce->create_object = zephir_init_properties_DotPHP_SwooleBootstrap;
	return SUCCESS;

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_SwooleBootstrap, initialize) {



}

/**
 * 初始化完成事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_SwooleBootstrap, initializeComplete) {



}

/**
 * 执行路由解析。
 * 
 * @return \DotPHP\Bean\RouteMessage
 */
PHP_METHOD(DotPHP_SwooleBootstrap, route) {


	RETURN_NULL();

}

/**
 * 执行验证。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_SwooleBootstrap, validate) {



}

/**
 * 执行程序。
 * 
 * @param \DotPHP\Bean\RouteMessage route_message
 * @return void
 */
PHP_METHOD(DotPHP_SwooleBootstrap, execute) {

	zval *_9, *_13, *_15, *_17, *_19, *_21, *_23, *_25, *_27, *_29, *_31, *_33, *_35;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route_message, *_0, *_1, _2, _3, _4, *_5 = NULL, *_6, *_7, *_8, *_10 = NULL, *_11 = NULL, *_12, *_14, *_16, *_18, *_20, *_22, *_24, *_26, *_28, *_30, *_32, *_34, *_36;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route_message);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_configurationexception_ce, "尚未设置 ISwooleEventDispatcher 对象。", "dotphp/swoolebootstrap.zep", 79);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "0.0.0.0", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "swoole_server_create", NULL, 20, &_2, _1, &_3, &_4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("serv"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("server_options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _6, "set", NULL, 0, _7);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_9);
	zephir_create_array(_9, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_9, _10);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "onStart", 1);
	zephir_array_fast_append(_9, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "start", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _8, "on", NULL, 0, _11, _9);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_13, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onShutdown", 1);
	zephir_array_fast_append(_13, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "shutdown", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _12, "on", NULL, 0, _11, _13);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_15);
	zephir_create_array(_15, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_15, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onManagerStart", 1);
	zephir_array_fast_append(_15, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "managerStart", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _14, "on", NULL, 0, _11, _15);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_17);
	zephir_create_array(_17, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_17, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onManagerStop", 1);
	zephir_array_fast_append(_17, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "managerStop", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _16, "on", NULL, 0, _11, _17);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_19);
	zephir_create_array(_19, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_19, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onWorkerStart", 1);
	zephir_array_fast_append(_19, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "workerStart", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _18, "on", NULL, 0, _11, _19);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_21);
	zephir_create_array(_21, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_21, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onWorkerStop", 1);
	zephir_array_fast_append(_21, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "workerStop", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _20, "on", NULL, 0, _11, _21);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_23);
	zephir_create_array(_23, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_23, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onWorkerError", 1);
	zephir_array_fast_append(_23, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "workerError", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _22, "on", NULL, 0, _11, _23);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_25);
	zephir_create_array(_25, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_25, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onTimer", 1);
	zephir_array_fast_append(_25, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "timer", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _24, "on", NULL, 0, _11, _25);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_27);
	zephir_create_array(_27, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_27, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onTask", 1);
	zephir_array_fast_append(_27, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "task", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _26, "on", NULL, 0, _11, _27);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_29);
	zephir_create_array(_29, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_29, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onFinish", 1);
	zephir_array_fast_append(_29, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _28, "on", NULL, 0, _11, _29);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_31);
	zephir_create_array(_31, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_31, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onConnect", 1);
	zephir_array_fast_append(_31, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "connect", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _30, "on", NULL, 0, _11, _31);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_32 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_33);
	zephir_create_array(_33, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_33, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onClose", 1);
	zephir_array_fast_append(_33, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "close", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _32, "on", NULL, 0, _11, _33);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_34 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_35);
	zephir_create_array(_35, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_10);
	zephir_read_property_this(&_10, this_ptr, SL("event_dispatcher"), PH_NOISY_CC);
	zephir_array_fast_append(_35, _10);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "onReceive", 1);
	zephir_array_fast_append(_35, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "receive", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _34, "on", NULL, 0, _11, _35);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_36 = zephir_fetch_nproperty_this(this_ptr, SL("serv"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _36, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取服务绑定端口。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_SwooleBootstrap, getPort) {


	RETURN_MEMBER(this_ptr, "port");

}

/**
 * 设置服务绑定端口。
 * 
 * @param int port
 * @return \DotPHP\SwooleBootstrap
 */
PHP_METHOD(DotPHP_SwooleBootstrap, setPort) {

	zval *port_param = NULL, *_0;
	int port;

	zephir_fetch_params(0, 1, 0, &port_param);

	port = zephir_get_intval(port_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, port);
	zephir_update_property_this(this_ptr, SL("port"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取 TCP 服务参数选项。
 * 
 * @return array
 */
PHP_METHOD(DotPHP_SwooleBootstrap, getServerOptions) {


	RETURN_MEMBER(this_ptr, "server_options");

}

/**
 * 设置 TCP 服务参数选项。
 * 
 * @param int port
 * @return \DotPHP\SwooleBootstrap
 */
PHP_METHOD(DotPHP_SwooleBootstrap, setServerOptions) {

	zval *server_options_param = NULL;
	zval *server_options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &server_options_param);

	zephir_get_arrval(server_options, server_options_param);


	zephir_update_property_this(this_ptr, SL("server_options"), server_options TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 设置 Swoole 事件处理对象。
 * 
 * @param \DotPHP\Interfaces\ISwooleEventDispatcher event_dispatcher
 * @return \DotPHP\SwooleBootstrap
 */
PHP_METHOD(DotPHP_SwooleBootstrap, setEventDispatcher) {

	zval *event_dispatcher;

	zephir_fetch_params(0, 1, 0, &event_dispatcher);



	zephir_update_property_this(this_ptr, SL("event_dispatcher"), event_dispatcher TSRMLS_CC);
	RETURN_THISW();

}

static zend_object_value zephir_init_properties_DotPHP_SwooleBootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("server_options"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("server_options"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

