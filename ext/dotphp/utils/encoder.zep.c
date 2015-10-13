
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * 数据编码/解码工具类。
 * 
 * 注: 目前仅支持 JSON/MessagePack/igbinary 三种数据格式。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Utils_Encoder) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Utils, Encoder, dotphp, utils_encoder, dotphp_utils_encoder_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_class_constant_long(dotphp_utils_encoder_ce, SL("JSON"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_utils_encoder_ce, SL("MSGPACK"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_utils_encoder_ce, SL("IGBINARY"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_utils_encoder_ce, SL("AMF"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(dotphp_utils_encoder_ce, SL("XML"), 5 TSRMLS_CC);

	zend_class_implements(dotphp_utils_encoder_ce TSRMLS_CC, 1, dotphp_interfaces_iencoder_ce);
	return SUCCESS;

}

/**
 * 数据编码。
 * 
 * @param mixed data
 * @param int enc_type
 * @param int options
 * @return string
 */
PHP_METHOD(DotPHP_Utils_Encoder, encode) {

	int enc_type, options, ZEPHIR_LAST_CALL_STATUS;
	zval *data, *enc_type_param = NULL, *options_param = NULL, _0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data, &enc_type_param, &options_param);

	if (!enc_type_param) {
		enc_type = 2;
	} else {
		enc_type = zephir_get_intval(enc_type_param);
	}
	if (!options_param) {
		options = 320;
	} else {
		options = zephir_get_intval(options_param);
	}


	do {
		if (enc_type == 1) {
			ZEPHIR_SINIT_VAR(_0$$3);
			ZVAL_LONG(&_0$$3, options);
			zephir_json_encode(return_value, &(return_value), data, zephir_get_intval(&_0$$3)  TSRMLS_CC);
			RETURN_MM();
		}
		if (enc_type == 2) {
			ZEPHIR_RETURN_CALL_FUNCTION("msgpack_serialize", NULL, 24, data);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (enc_type == 3) {
			ZEPHIR_RETURN_CALL_FUNCTION("igbinary_serialize", NULL, 25, data);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_notimplementedexception_ce, "接口尚未实现。", "dotphp/utils/encoder.zep", 40);
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * 数据解码。
 * 
 * @param string data
 * @param int enc_type
 * @return mixed
 */
PHP_METHOD(DotPHP_Utils_Encoder, decode) {

	int enc_type, ZEPHIR_LAST_CALL_STATUS;
	zval *data, *enc_type_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &enc_type_param);

	if (!enc_type_param) {
		enc_type = 2;
	} else {
		enc_type = zephir_get_intval(enc_type_param);
	}


	do {
		if (enc_type == 1) {
			zephir_json_decode(return_value, &(return_value), data, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
			RETURN_MM();
		}
		if (enc_type == 2) {
			ZEPHIR_RETURN_CALL_FUNCTION("msgpack_unserialize", NULL, 26, data);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (enc_type == 3) {
			ZEPHIR_RETURN_CALL_FUNCTION("igbinary_unserialize", NULL, 27, data);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_notimplementedexception_ce, "接口尚未实现。", "dotphp/utils/encoder.zep", 62);
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

