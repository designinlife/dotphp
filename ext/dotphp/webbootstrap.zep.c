
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exit.h"


/**
 * DotPHP - 基于 HTTP 协议的启动器。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_WebBootstrap) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP, WebBootstrap, dotphp, webbootstrap, dotphp_abstractbootstrap_ce, dotphp_webbootstrap_method_entry, 0);

	/**
	 * 模板目录。
	 * 
	 * @var string
	 */
	zend_declare_property_null(dotphp_webbootstrap_ce, SL("template_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 模板编译目录。
	 * 
	 * @var string
	 */
	zend_declare_property_null(dotphp_webbootstrap_ce, SL("template_cache_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 模板类名。
	 * 
	 * @var string
	 */
	zend_declare_property_null(dotphp_webbootstrap_ce, SL("template_class"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * ITemplate 模板对象实例。
	 * 
	 * @var \DotPHP\Interfaces\ITemplate
	 */
	zend_declare_property_null(dotphp_webbootstrap_ce, SL("template_instance"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 当前执行的 IController 实例。
	 * 
	 * @var \DotPHP\Interfaces\IController
	 */
	zend_declare_property_null(dotphp_webbootstrap_ce, SL("ctl_instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 初始化事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_WebBootstrap, initialize) {

	zend_class_entry *_3;
	zval *cls_n = NULL, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, dotphp_webbootstrap_ce, this_ptr, "initialize", &_0, 49);
	zephir_check_call_status();
	cls_n = zephir_fetch_nproperty_this(this_ptr, SL("template_class"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fetch_safe_class(_2, cls_n);
		_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _3);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("template_instance"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化完成事件。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_WebBootstrap, initializeComplete) {

	


}

/**
 * 执行路由解析。
 * 
 * @return \DotPHP\Bean\RouteMessage
 */
PHP_METHOD(DotPHP_WebBootstrap, route) {

	zval *_0, *_1$$3, *_2$$4, *_3$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("route_parser"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("route_parser"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_1$$3, "parse", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		object_init_ex(return_value, dotphp_bean_routemessage_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "Index", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "defaults", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 50, _2$$4, _3$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 执行验证。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_WebBootstrap, validate) {

	


}

/**
 * 执行程序。
 * 
 * @param \DotPHP\Bean\RouteMessage route_message
 * @return void
 */
PHP_METHOD(DotPHP_WebBootstrap, execute) {

	zval *_8;
	zend_class_entry *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *route_message, *cls_n = NULL, *cls_m = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_5, *_6, *_7, *_9, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route_message);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontrollerns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, route_message, "getcontroller", NULL, 51);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(cls_n);
	ZEPHIR_CONCAT_VSV(cls_n, _0, "\\", _1);
	ZEPHIR_CALL_METHOD(&cls_m, route_message, "getmethod", NULL, 52);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_fetch_safe_class(_3, cls_n);
		_4 = zend_fetch_class(Z_STRVAL_P(_3), Z_STRLEN_P(_3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_2, _4);
	if (zephir_has_constructor(_2 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("ctl_instance"), _2 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("ctl_instance"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _5, "initialize", NULL, 0);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("ctl_instance"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _6, "before", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property_this(&_9, this_ptr, SL("ctl_instance"), PH_NOISY_CC);
	zephir_array_fast_append(_8, _9);
	zephir_array_fast_append(_8, cls_m);
	ZEPHIR_INIT_VAR(_10);
	array_init(_10);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_7, _8, _10);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("ctl_instance"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _11, "after", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 缺省异常处理。
 * 
 * @return void
 */
PHP_METHOD(DotPHP_WebBootstrap, defExceptionHandler) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *ex, *_0 = NULL, *_1, _3, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ex);



	php_printf("%s", "<!DOCTYPE html><html lang=\"zh-CN\"><head><title>系统错误!</title><meta charset=\"UTF-8\" /><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"/><style type=\"text/css\">");
	php_printf("%s", "html, body { font-family: SimSun, Tahoma, Arial; font-size: 12px; }");
	php_printf("%s", "#container { margin: 18px; }");
	php_printf("%s", "p { line-height: 20px; }");
	php_printf("%s", "pre { padding: 12px; background: #FFC; -moz-border-radius: 6px; -webkit-border-radius: 6px; border-radius: 6px; }");
	php_printf("%s", "</style></head><body>");
	php_printf("%s", "<div id=\"container\"><h1 style=\"font-family: Arial;\">Exception Found!</h1><p>");
	ZEPHIR_CALL_METHOD(&_0, ex, "getmessage", NULL, 0);
	zephir_check_call_status();
	zend_print_zval(_0, 0);
	php_printf("%s", "</p>");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		php_printf("%s", "<pre>");
		ZEPHIR_CALL_METHOD(&_2$$3, ex, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(_2$$3, 0);
		php_printf("%s", "</pre></div>");
	}
	php_printf("%s", "</body></html>");
	ZEPHIR_MM_RESTORE();
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 2);
	zephir_exit(&_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取模板目录。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_WebBootstrap, getTemplateDirectory) {

	

	RETURN_MEMBER(this_ptr, "template_dir");

}

/**
 * 设置模板目录。
 * 
 * @param string dir
 * @return \DotPHP\WebBootstrap
 */
PHP_METHOD(DotPHP_WebBootstrap, setTemplateDirectory) {

	zval *dir_param = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	zephir_update_property_this(this_ptr, SL("template_dir"), dir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取模板编译目录。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_WebBootstrap, getTemplateCacheDirectory) {

	

	RETURN_MEMBER(this_ptr, "template_cache_dir");

}

/**
 * 设置模板编译目录。
 * 
 * @param string dir
 * @return \DotPHP\WebBootstrap
 */
PHP_METHOD(DotPHP_WebBootstrap, setTemplateCacheDirectory) {

	zval *dir_param = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	zephir_update_property_this(this_ptr, SL("template_cache_dir"), dir TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 设置模板类名。
 * 
 * @param string cls_name
 * @return \DotPHP\WebBootstrap
 */
PHP_METHOD(DotPHP_WebBootstrap, setTemplateClass) {

	zval *cls_name_param = NULL;
	zval *cls_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cls_name_param);

	zephir_get_strval(cls_name, cls_name_param);


	zephir_update_property_this(this_ptr, SL("template_class"), cls_name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取 ITemplate 对象实例。
 * 
 * @return \DotPHP\Interfaces\ITemplate
 */
PHP_METHOD(DotPHP_WebBootstrap, getTemplate) {

	

	RETURN_MEMBER(this_ptr, "template_instance");

}

