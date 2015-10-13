
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exit.h"
#include "kernel/exception.h"
#include "kernel/time.h"
#include "kernel/array.h"


/**
 * DotPHP 启动器抽象类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_AbstractBootstrap) {

	ZEPHIR_REGISTER_CLASS(DotPHP, AbstractBootstrap, dotphp, abstractbootstrap, dotphp_abstractbootstrap_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 时区。
	 * 
	 * @var string
	 */
	zend_declare_property_string(dotphp_abstractbootstrap_ce, SL("timezone"), "Asia/Shanghai", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 错误报告级别。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_abstractbootstrap_ce, SL("error_level"), 32759, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 框架版本。
	 * 
	 * @var string
	 */
	zend_declare_property_string(dotphp_abstractbootstrap_ce, SL("version"), "0.1a", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 系统时间偏移值。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_abstractbootstrap_ce, SL("time_offset"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 是否命令行模式运行？
	 * 
	 * @var boolean
	 */
	zend_declare_property_bool(dotphp_abstractbootstrap_ce, SL("is_cli_mode"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 数据库参数对象。
	 * 
	 * @var \DotPHP\Bean\DbParameter
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("db_parameter"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 缓存参数对象。
	 * 
	 * @var \DotPHP\Bean\CacheParameter
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("cache_parameter"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 路由解析器对象。
	 * 
	 * @var \DotPHP\Interfaces\IRouteParser
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("route_parser"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 路由消息对象。
	 * 
	 * @var \DotPHP\Bean\RouteMessage
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("route_message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 是否开启调试模式？
	 * 
	 * @var boolean
	 */
	zend_declare_property_bool(dotphp_abstractbootstrap_ce, SL("_debug"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 控制器命名空间。
	 * 
	 * @var string
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("controller_ns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志输出目录。
	 * 
	 * @var string
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("log_directory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志输出级别。
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_abstractbootstrap_ce, SL("log_level"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志输出模式。(1,控制台 | 2,文件)
	 * 
	 * @var int
	 */
	zend_declare_property_long(dotphp_abstractbootstrap_ce, SL("log_mode"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志模块名称。
	 * 
	 * @var string
	 */
	zend_declare_property_string(dotphp_abstractbootstrap_ce, SL("log_module"), "sys", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * IDb 数据库操作对象。
	 * 
	 * @var \DotPHP\Interfaces\IDb
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ILogger 日志操作对象。
	 * 
	 * @var \DotPHP\Interfaces\ILogger
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("logger"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Redis 缓存对象。
	 * 
	 * @var \Redis
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 命令行参数列表。
	 * 
	 * @var array
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("argv"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置参数列表。
	 * 
	 * @var array
	 */
	zend_declare_property_null(dotphp_abstractbootstrap_ce, SL("cfgs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 启动程序。
 * 
 * @param array argv
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, dispatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *cfgs_param = NULL, *_0, _1, *_2 = NULL, *_3 = NULL, *_4;
	zval *argv = NULL, *cfgs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &argv_param, &cfgs_param);

	if (!argv_param) {
		ZEPHIR_INIT_VAR(argv);
		array_init(argv);
	} else {
		zephir_get_arrval(argv, argv_param);
	}
	if (!cfgs_param) {
		ZEPHIR_INIT_VAR(cfgs);
		array_init(cfgs);
	} else {
		zephir_get_arrval(cfgs, cfgs_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_SAPI");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "cli", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", NULL, 1, &_1, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_2, 0)) {
		if (1) {
			zephir_update_property_this(this_ptr, SL("is_cli_mode"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("is_cli_mode"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	if (ZEPHIR_GLOBAL(debug)) {
		zephir_update_property_this(this_ptr, SL("_debug"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_debug"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("argv"), argv TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("cfgs"), cfgs TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setup", NULL, 2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializecomplete", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "route", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("route_message"), _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "before", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("route_message"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "after", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 载入系统核心组件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, loadComponents) {

	zend_bool _17$$3;
	zval *_0, *_1, *_2, *_23, *_24, *_3$$3, *_4$$3 = NULL, *_16$$3, *_18$$3, *_19$$3 = NULL, *_5$$4, *_6$$4, *_7$$4 = NULL, *_8$$5, *_9$$5, *_10$$5 = NULL, *_11$$5, *_12$$5 = NULL, *_13$$5, *_14$$5, *_15$$5, *_20$$6, *_21$$6, *_22$$6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, dotphp_db_dbpdo_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 3, this_ptr);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("db"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("cache"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_2))) {
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "getunixsocket", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(_4$$3))) {
			_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_7$$4, _6$$4, "getunixsocket", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _5$$4, "connect", NULL, 0, _7$$4);
			zephir_check_call_status();
		} else {
			_8$$5 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
			_9$$5 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_10$$5, _9$$5, "gethost", NULL, 0);
			zephir_check_call_status();
			_11$$5 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_12$$5, _11$$5, "getport", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_13$$5);
			ZVAL_LONG(_13$$5, 1);
			ZEPHIR_INIT_VAR(_14$$5);
			ZVAL_NULL(_14$$5);
			ZEPHIR_INIT_VAR(_15$$5);
			ZVAL_LONG(_15$$5, 100);
			ZEPHIR_CALL_METHOD(NULL, _8$$5, "connect", NULL, 0, _10$$5, _12$$5, _13$$5, _14$$5, _15$$5);
			zephir_check_call_status();
		}
		_16$$3 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
		_17$$3 = zephir_is_true(_16$$3);
		if (_17$$3) {
			_18$$3 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_19$$3, _18$$3, "getpass", NULL, 0);
			zephir_check_call_status();
			_17$$3 = !(ZEPHIR_IS_EMPTY(_19$$3));
		}
		if (_17$$3) {
			_20$$6 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
			_21$$6 = zephir_fetch_nproperty_this(this_ptr, SL("cache_parameter"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_22$$6, _21$$6, "getpass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _20$$6, "auth", NULL, 0, _22$$6);
			zephir_check_call_status();
		}
	}
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("db_parameter"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _23, "set", NULL, 0, _24);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadcomponents", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化完成事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, initializeComplete) {

}

/**
 * 执行路由解析。
 * 
 * @return \DotPHP\Bean\RouteMessage
 */
PHP_METHOD(DotPHP_AbstractBootstrap, route) {

}

/**
 * 执行验证。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, validate) {

}

/**
 * 执行程序。
 * 
 * @param \DotPHP\Bean\RouteMessage route_message
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, execute) {

}

/**
 * 在 execute() 调用之前执行。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, before) {

	


}

/**
 * 在 execute() 调用之后执行。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, after) {

	


}

/**
 * 释放资源。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, shutdown) {

	zval *_0, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "close", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("db"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("cache"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("logger"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 缺省异常处理。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, defExceptionHandler) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *ex, *_0 = NULL, *_1 = NULL, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ex);



	ZEPHIR_CALL_METHOD(&_0, ex, "getmessage", NULL, 0);
	zephir_check_call_status();
	zend_print_zval(_0, 0);
	php_printf("%s", "\r\n");
	ZEPHIR_CALL_METHOD(&_1, ex, "gettraceasstring", NULL, 0);
	zephir_check_call_status();
	zend_print_zval(_1, 0);
	ZEPHIR_MM_RESTORE();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 2);
	zephir_exit(&_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * 缺省错误处理。
 * 
 * @param int errno
 * @param string errstr
 * @param string errfile
 * @param int errline
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, defErrorHandler) {

	zval *errstr = NULL, *errfile = NULL;
	zval *errno_param = NULL, *errstr_param = NULL, *errfile_param = NULL, *errline_param = NULL, *_0, *_1, *_2, *_3;
	int errno, errline, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &errno_param, &errstr_param, &errfile_param, &errline_param);

	errno = zephir_get_intval(errno_param);
	zephir_get_strval(errstr, errstr_param);
	zephir_get_strval(errfile, errfile_param);
	errline = zephir_get_intval(errline_param);


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, errno);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, errline);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 4, errstr, _1, _2, errfile, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "dotphp/abstractbootstrap.zep", 293 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 获取 IDb 对象。
 * 
 * @return \DotPHP\Interfaces\IDb
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getDb) {

	

	RETURN_MEMBER(this_ptr, "db");

}

/**
 * 获取 ILogger 对象。
 * 
 * @return \DotPHP\Interfaces\ILogger
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getLogger) {

	

	RETURN_MEMBER(this_ptr, "logger");

}

/**
 * 获取 Redis 对象。
 * 
 * @return \Redis
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getCache) {

	

	RETURN_MEMBER(this_ptr, "cache");

}

/**
 * 获取 RouteMessage 对象。
 * 
 * @return \DotPHP\Bean\RouteMessage
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getRouteMessage) {

	

	RETURN_MEMBER(this_ptr, "route_message");

}

/**
 * 指示是否命令行运行模式？
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_AbstractBootstrap, isCliMode) {

	

	RETURN_MEMBER(this_ptr, "is_cli_mode");

}

/**
 * 获取系统配置参数列表。
 * 
 * @return array
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getAppSettings) {

	

	RETURN_MEMBER(this_ptr, "cfgs");

}

/**
 * 获取当前设定的系统时区。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getTimezone) {

	

	RETURN_MEMBER(this_ptr, "timezone");

}

/**
 * 设置系统使用的时区。
 * 
 * @param string timezone
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setTimezone) {

	zval *timezone_param = NULL;
	zval *timezone = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timezone_param);

	zephir_get_strval(timezone, timezone_param);


	zephir_update_property_this(this_ptr, SL("timezone"), timezone TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取系统时间偏移值。(秒)
 * 
 * @return string
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getTimeOffset) {

	

	RETURN_MEMBER(this_ptr, "time_offset");

}

/**
 * 设置系统时间偏移值。(秒)
 * 
 * @param string offset
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setTimeOffset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_this(this_ptr, SL("time_offset"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取错误追踪级别。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getErrorLevel) {

	

	RETURN_MEMBER(this_ptr, "error_level");

}

/**
 * 设置错误追踪级别。
 * 
 * @param int error_level
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setErrorLevel) {

	zval *error_level_param = NULL;
	zval *error_level = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_level_param);

	zephir_get_strval(error_level, error_level_param);


	zephir_update_property_this(this_ptr, SL("error_level"), error_level TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取控制器命名空间。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getControllerNS) {

	

	RETURN_MEMBER(this_ptr, "controller_ns");

}

/**
 * 设置控制器命名空间。
 * 
 * @param string controller_ns
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setControllerNS) {

	zval *controller_ns_param = NULL;
	zval *controller_ns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controller_ns_param);

	zephir_get_strval(controller_ns, controller_ns_param);


	zephir_update_property_this(this_ptr, SL("controller_ns"), controller_ns TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 设置数据库连接参数对象。
 * 
 * @param \DotPHP\Bean\DbParameter db_parameter
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setDbParameter) {

	zval *db_parameter;

	zephir_fetch_params(0, 1, 0, &db_parameter);



	zephir_update_property_this(this_ptr, SL("db_parameter"), db_parameter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 设置 Redis 连接参数对象。
 * 
 * @param \DotPHP\Bean\CacheParameter cache_parameter
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setCacheParameter) {

	zval *cache_parameter;

	zephir_fetch_params(0, 1, 0, &cache_parameter);



	zephir_update_property_this(this_ptr, SL("cache_parameter"), cache_parameter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 设置路由解析器对象。
 * 
 * @param \DotPHP\Interfaces\IRouteParser parser
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setRouteParser) {

	zval *parser;

	zephir_fetch_params(0, 1, 0, &parser);



	zephir_update_property_this(this_ptr, SL("route_parser"), parser TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取日志目录。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getLogDirectory) {

	

	RETURN_MEMBER(this_ptr, "log_directory");

}

/**
 * 设置日志目录。
 * 
 * @param string log_dir
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setLogDirectory) {

	zval *log_dir_param = NULL;
	zval *log_dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &log_dir_param);

	zephir_get_strval(log_dir, log_dir_param);


	zephir_update_property_this(this_ptr, SL("log_directory"), log_dir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取日志输出级别。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getLogLevel) {

	

	RETURN_MEMBER(this_ptr, "log_level");

}

/**
 * 设置日志输出级别。
 * 
 * @param int level
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setLogLevel) {

	zval *level_param = NULL, *_0;
	int level;

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_this(this_ptr, SL("log_level"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取日志输出模式。(1,控制台 | 2,文件)
 * 
 * @return int
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getLogMode) {

	

	RETURN_MEMBER(this_ptr, "log_mode");

}

/**
 * 设置日志输出模式。(1,控制台 | 2,文件)
 * 
 * @param int mode
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setLogMode) {

	zval *mode_param = NULL, *_0;
	int mode;

	zephir_fetch_params(0, 1, 0, &mode_param);

	mode = zephir_get_intval(mode_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, mode);
	zephir_update_property_this(this_ptr, SL("log_mode"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * 获取日志模块名称。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getLogModule) {

	

	RETURN_MEMBER(this_ptr, "log_module");

}

/**
 * 设置日志模块名称。
 * 
 * @param string module
 * @return \DotPHP\AbstractBootstrap
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setLogModule) {

	zval *module_param = NULL;
	zval *module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_strval(module, module_param);


	zephir_update_property_this(this_ptr, SL("log_module"), module TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取系统版本号。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_AbstractBootstrap, getVersion) {

	

	RETURN_MEMBER(this_ptr, "version");

}

/**
 * 指示是否启用调试？
 * 
 * @return boolean
 */
PHP_METHOD(DotPHP_AbstractBootstrap, isDebug) {

	

	RETURN_MEMBER(this_ptr, "_debug");

}

/**
 * 打印数据。
 * 
 * @param mixed data
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, dump) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_ARRAY) {
		php_printf("%s", "<pre>");
		ZEPHIR_CALL_FUNCTION(NULL, "print_r", NULL, 5, data);
		zephir_check_call_status();
		php_printf("%s", "</pre>");
	} else {
		zend_print_zval(data, 0);
	}
	ZEPHIR_MM_RESTORE();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	zephir_exit(&_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取当前系统时间。
 * 
 * @return int
 */
PHP_METHOD(DotPHP_AbstractBootstrap, cts) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("time_offset"), PH_NOISY_CC);
	zephir_add_function(return_value, _0, _1);
	RETURN_MM();

}

/**
 * 系统环境设置。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_AbstractBootstrap, setup) {

	zval *_1, *_3, *_4;
	zval *_0, *_2 = NULL, *_5, *_6, *_7 = NULL, *_8, *_9 = NULL, *_10, *_11;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("timezone"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, 6, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_1, this_ptr);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "shutdown", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 7, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "defExceptionHandler", 1);
	zephir_array_fast_append(_3, _2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 8, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "defErrorHandler", 1);
	zephir_array_fast_append(_4, _2);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("error_level"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 9, _4, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, dotphp_core_genericlogger_ce);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 10, this_ptr);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("logger"), _2 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("logger"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("log_module"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "setmodule", NULL, 0, _8);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("log_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _7, "setmode", NULL, 0, _10);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("log_level"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _9, "setlevel", NULL, 0, _11);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

