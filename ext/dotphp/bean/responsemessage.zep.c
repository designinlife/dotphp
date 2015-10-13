
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * ResponseMessage 消息协议类。
 *
 * --------------------------------------------------------
 * @author        Lei Lee <web.developer.network@gmail.com>
 * @version       0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * @package       Application\Entity
 * --------------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Bean_ResponseMessage) {

	ZEPHIR_REGISTER_CLASS_EX(DotPHP\\Bean, ResponseMessage, dotphp, bean_responsemessage, dotphp_bean_abstractresponsemessage_ce, dotphp_bean_responsemessage_method_entry, 0);

	return SUCCESS;

}

/**
 * 数据编码输出。
 *
 * @return string
 */
PHP_METHOD(DotPHP_Bean_ResponseMessage, encode) {

	zval *s = NULL, *es = NULL, *_0 = NULL, *_1 = NULL, _3, _4;
	zval *d = NULL;
	int ZEPHIR_LAST_CALL_STATUS, len = 0;
	zephir_fcall_cache_entry *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(d);
	zephir_create_array(d, 7, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_op_code"), PH_NOISY_CC);
	zephir_array_update_string(&d, SL("o"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_module"), PH_NOISY_CC);
	zephir_array_update_string(&d, SL("c"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_method"), PH_NOISY_CC);
	zephir_array_update_string(&d, SL("m"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_update_string(&d, SL("d"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	zephir_time(_1);
	zephir_array_update_string(&d, SL("t"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_errno"), PH_NOISY_CC);
	zephir_array_update_string(&d, SL("r"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_errstr"), PH_NOISY_CC);
	zephir_array_update_string(&d, SL("e"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_CE_STATIC(&s, dotphp_utils_encoder_ce, "encode", &_2, 12, d, _1);
	zephir_check_call_status();
	len = zephir_fast_strlen_ev(s);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "cNa*", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, len);
	ZEPHIR_CALL_FUNCTION(&es, "pack", NULL, 13, &_3, ZEPHIR_GLOBAL(global_false), &_4, s);
	zephir_check_call_status();
	RETURN_CCTOR(es);

}

/**
 * 字符串转换输出。
 * 
 * @return string
 */
PHP_METHOD(DotPHP_Bean_ResponseMessage, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "encode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

