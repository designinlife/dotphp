
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/exception.h"


/**
 * DotPHP 字符串工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Utils_StringUtil) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Utils, StringUtil, dotphp, utils_stringutil, dotphp_utils_stringutil_method_entry, 0);

	return SUCCESS;

}

/**
 * 在查询中使用一个字符串。
 * 
 * @param var data
 * @return var
 */
PHP_METHOD(DotPHP_Utils_StringUtil, quote) {

	zend_bool _0, _1, _2;
	zval *data, *_3, _4, _5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = (Z_TYPE_P(data) == IS_LONG);
	if (!(_0)) {
		_0 = (Z_TYPE_P(data) == IS_LONG);
	}
	_1 = _0;
	if (!(_1)) {
		_1 = (Z_TYPE_P(data) == IS_DOUBLE);
	}
	_2 = _1;
	if (!(_2)) {
		_2 = (Z_TYPE_P(data) == IS_DOUBLE);
	}
	if (_2) {
		RETVAL_ZVAL(data, 1, 0);
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "'", 0);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "\\'", 0);
		zephir_fast_str_replace(&_3, &_4, &_5, data TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "'", _3, "'");
		RETURN_MM();
	}

}

/**
 * 替换字符串变量。
 *
 * @param string message 指定消息文本内容。
 * @param array  vars    指定 HashMap 键值对列表。
 * @param string prefix  指定变量命名规范前缀字符。(可选 | 默认: % 百分号)
 * @return string
 */
PHP_METHOD(DotPHP_Utils_StringUtil, translate) {

	HashTable *_1;
	HashPosition _0;
	zval *vars = NULL;
	zval *message_param = NULL, *vars_param = NULL, *prefix = NULL, *key = NULL, *value = NULL, **_2, *_3 = NULL;
	zval *message = NULL, *ss = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &message_param, &vars_param, &prefix);

	zephir_get_strval(message, message_param);
	zephir_get_arrval(vars, vars_param);
	if (!prefix) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "%", 1);
	}


	zephir_is_iterable(vars, &_1, &_0, 0, 0, "dotphp/utils/stringutil.zep", 43);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, prefix, "{", key, "}");
		ZEPHIR_INIT_NVAR(ss);
		zephir_fast_str_replace(&ss, _3, value, message TSRMLS_CC);
	}
	RETURN_CTOR(ss);

}

/**
 * 字符串变量替换。(支持可变参数)
 *
 * @return string
 * @example
 *            [Call]:   Util::substitute('My name is {1}, an alias, also called {0}! {2}-year-old.', 'Lei', 'Li Lei', 30);
 *            [Output]: My name is Li Lei, an alias, also called Lei! 30-year-old.
 */
PHP_METHOD(DotPHP_Utils_StringUtil, substitute) {

	zval *_5 = NULL;
	zend_bool _0;
	int i, ZEPHIR_LAST_CALL_STATUS, _1;
	zval *args = NULL, *size = NULL, *str = NULL, *_2 = NULL, *_3 = NULL, _4 = zval_used_for_init, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 27);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&size, "func_num_args", NULL, 28);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(str);
	zephir_array_fetch_long(&str, args, 0, PH_NOISY, "dotphp/utils/stringutil.zep", 60 TSRMLS_CC);
	ZEPHIR_CPY_WRT(_2, size);
	_1 = 1;
	_0 = 0;
	if (ZEPHIR_GE_LONG(_2, _1)) {
		while (1) {
			if (_0) {
				_1++;
				if (!(ZEPHIR_GE_LONG(_2, _1))) {
					break;
				}
			} else {
				_0 = 1;
			}
			i = _1;
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, ((i - 1)));
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "{", &_4, "}");
			zephir_array_fetch_long(&_6, args, i, PH_NOISY | PH_READONLY, "dotphp/utils/stringutil.zep", 63 TSRMLS_CC);
			zephir_fast_str_replace(&_3, _5, _6, str TSRMLS_CC);
			ZEPHIR_CPY_WRT(str, _3);
		}
	}
	RETURN_CCTOR(str);

}

/**
 * 获取字符串真实长度。(注: 中文以 2 个字节计算)
 *
 * @param string str      指定测试字符串。
 * @param string encoding 指定字符串编码。(默认值: UTF-8)
 * @return int
 */
PHP_METHOD(DotPHP_Utils_StringUtil, length) {

	int v, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding_param = NULL, *_0 = NULL;
	zval *str = NULL, *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding_param);

	zephir_get_strval(str, str_param);
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
		zephir_get_strval(encoding, encoding_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mb_strlen", NULL, 31, str, encoding);
	zephir_check_call_status();
	v = (long) (zephir_safe_div_long_long((zephir_fast_strlen_ev(str) + zephir_get_numberval(_0)), 2 TSRMLS_CC));
	RETURN_MM_LONG(v);

}

/**
 * 生成 alpha ID 编码。
 *
 * @param int|string  in       String or long input to translate
 * @param boolean     to_num   Reverses translation when true
 * @param int|boolean pad_up   Number or boolean padds the result up to a specified length
 * @param string      pass_key Supplying a password makes it harder to calculate the original ID
 * @return string
 */
PHP_METHOD(DotPHP_Utils_StringUtil, alphaID) {

	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL;
	zval *i, *p;
	int n, t, a, len, _1, _2, ZEPHIR_LAST_CALL_STATUS, _9, _10, _11, _12, _17, _18, _20;
	zval *pass_key = NULL;
	zend_bool to_num, _0, _8;
	zval *input = NULL, *to_num_param = NULL, *pad_up = NULL, *pass_key_param = NULL, *out = NULL, *index = NULL, *base, *pass_hash = NULL, *bcp = NULL, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL, *_14 = NULL, _15 = zval_used_for_init, *_16 = NULL, *_19 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &input, &to_num_param, &pad_up, &pass_key_param);

	ZEPHIR_SEPARATE_PARAM(input);
	if (!to_num_param) {
		to_num = 0;
	} else {
		to_num = zephir_get_boolval(to_num_param);
	}
	if (!pad_up) {
		ZEPHIR_CPY_WRT(pad_up, ZEPHIR_GLOBAL(global_false));
	} else {
		ZEPHIR_SEPARATE_PARAM(pad_up);
	}
	if (!pass_key_param) {
		ZEPHIR_INIT_VAR(pass_key);
		ZVAL_EMPTY_STRING(pass_key);
	} else {
		zephir_get_strval(pass_key, pass_key_param);
	}
	ZEPHIR_INIT_VAR(i);
	array_init(i);
	ZEPHIR_INIT_VAR(p);
	array_init(p);


	ZEPHIR_INIT_VAR(out);
	ZVAL_STRING(out, "", 1);
	ZEPHIR_INIT_VAR(index);
	ZVAL_STRING(index, "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);
	ZEPHIR_INIT_VAR(base);
	ZVAL_LONG(base, zephir_fast_strlen_ev(index));
	if (!ZEPHIR_IS_STRING_IDENTICAL(pass_key, "")) {
		len = zephir_fast_strlen_ev(index);
		_2 = (len - 1);
		_1 = 0;
		_0 = 0;
		if (_1 <= _2) {
			while (1) {
				if (_0) {
					_1++;
					if (!(_1 <= _2)) {
						break;
					}
				} else {
					_0 = 1;
				}
				n = _1;
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, n);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, 1);
				ZEPHIR_INIT_NVAR(_5);
				zephir_substr(_5, index, zephir_get_intval(&_3), 1 , 0);
				zephir_array_append(&i, _5, PH_SEPARATE, "dotphp/utils/stringutil.zep", 105);
			}
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "sha256", 0);
		ZEPHIR_CALL_FUNCTION(&pass_hash, "hash", &_6, 32, &_3, pass_key);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		if (zephir_fast_strlen_ev(pass_hash) < zephir_fast_strlen_ev(index)) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "sha512", 0);
			ZEPHIR_CALL_FUNCTION(&_7, "hash", &_6, 32, &_3, pass_key);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_7, pass_hash);
		}
		ZEPHIR_CPY_WRT(pass_hash, _7);
		len = zephir_fast_strlen_ev(index);
		_10 = (len - 1);
		_9 = 0;
		_8 = 0;
		if (_9 <= _10) {
			while (1) {
				if (_8) {
					_9++;
					if (!(_9 <= _10)) {
						break;
					}
				} else {
					_8 = 1;
				}
				n = _9;
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, n);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, 1);
				ZEPHIR_INIT_NVAR(_5);
				zephir_substr(_5, pass_hash, zephir_get_intval(&_3), 1 , 0);
				zephir_array_append(&p, _5, PH_SEPARATE, "dotphp/utils/stringutil.zep", 113);
			}
		}
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 3);
		Z_SET_ISREF_P(p);
		ZEPHIR_CALL_FUNCTION(NULL, "array_multisort", NULL, 33, p, _5, i);
		Z_UNSET_ISREF_P(p);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(index);
		zephir_fast_join_str(index, SL(""), i TSRMLS_CC);
	}
	if (to_num) {
		len = (zephir_fast_strlen_ev(input) - 1);
		_12 = len;
		_11 = _12;
		_0 = 0;
		if (_11 >= 0) {
			while (1) {
				if (_0) {
					_11--;
					if (!(_11 >= 0)) {
						break;
					}
				} else {
					_0 = 1;
				}
				t = _11;
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, (len - t));
				ZEPHIR_CALL_FUNCTION(&bcp, "bcpow", &_13, 34, base, &_3);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, t);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, 1);
				ZEPHIR_INIT_NVAR(_5);
				zephir_substr(_5, input, zephir_get_intval(&_3), 1 , 0);
				ZEPHIR_INIT_NVAR(_14);
				zephir_fast_strpos(_14, index, _5, 0 );
				ZEPHIR_SINIT_NVAR(_15);
				mul_function(&_15, _14, bcp TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_7);
				zephir_add_function_ex(_7, out, &_15 TSRMLS_CC);
				ZEPHIR_CPY_WRT(out, _7);
			}
		}
		if (zephir_is_numeric(pad_up)) {
			ZEPHIR_SEPARATE(pad_up);
			zephir_decrement(pad_up);
			if (ZEPHIR_GT_LONG(pad_up, 0)) {
				ZEPHIR_INIT_NVAR(_5);
				zephir_pow_function(_5, base, pad_up);
				ZEPHIR_SUB_ASSIGN(out, _5);
			}
		}
	} else {
		if (zephir_is_numeric(pad_up)) {
			ZEPHIR_SEPARATE(pad_up);
			zephir_decrement(pad_up);
			if (ZEPHIR_GT_LONG(pad_up, 0)) {
				ZEPHIR_INIT_NVAR(_5);
				zephir_pow_function(_5, base, pad_up);
				ZEPHIR_ADD_ASSIGN(input, _5);
			}
		}
		ZEPHIR_INIT_LNVAR(_7);
		if (!ZEPHIR_IS_LONG(input, 0)) {
			ZEPHIR_CALL_FUNCTION(&_16, "log", NULL, 35, input, base);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_DOUBLE(_7, zephir_floor(_16 TSRMLS_CC));
		} else {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 0);
		}
		len = zephir_get_numberval(_7);
		_18 = len;
		_17 = _18;
		_0 = 0;
		if (_17 >= 0) {
			while (1) {
				if (_0) {
					_17--;
					if (!(_17 >= 0)) {
						break;
					}
				} else {
					_0 = 1;
				}
				t = _17;
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, t);
				ZEPHIR_CALL_FUNCTION(&bcp, "bcpow", &_13, 34, base, &_3);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_3);
				div_function(&_3, input, bcp TSRMLS_CC);
				a = (long) (zephir_safe_mod_double_zval(zephir_floor(&_3 TSRMLS_CC), base TSRMLS_CC));
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, a);
				ZEPHIR_SINIT_NVAR(_15);
				ZVAL_LONG(&_15, 1);
				ZEPHIR_INIT_NVAR(_5);
				zephir_substr(_5, index, zephir_get_intval(&_4), 1 , 0);
				ZEPHIR_INIT_LNVAR(_19);
				ZEPHIR_CONCAT_VV(_19, out, _5);
				ZEPHIR_CPY_WRT(out, _19);
				_20 = (zephir_get_numberval(input) - ((a * zephir_get_numberval(bcp))));
				ZEPHIR_INIT_NVAR(input);
				ZVAL_LONG(input, _20);
			}
		}
	}
	RETURN_CCTOR(out);

}

/**
 * 生成 GUID 全球唯一标识。
 *
 * @return string
 */
PHP_METHOD(DotPHP_Utils_StringUtil, guid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *hyphen, *uuid = NULL;
	zval *charid, *_0, *_1 = NULL, *_2 = NULL, _3, _4, *_5, _6, _7, *_8, _9, _10, *_11, _12, _13, *_14, _15, _16, *_17, *_18;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "mt_rand", NULL, 36);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "uniqid", NULL, 37, _1, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_md5(_0, _2);
	ZEPHIR_INIT_VAR(charid);
	zephir_fast_strtoupper(charid, _0);
	ZEPHIR_INIT_VAR(hyphen);
	ZVAL_STRING(hyphen, "-", 1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 8);
	ZEPHIR_INIT_VAR(_5);
	zephir_substr(_5, charid, 0 , 8 , 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 8);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 4);
	ZEPHIR_INIT_VAR(_8);
	zephir_substr(_8, charid, 8 , 4 , 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 12);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 4);
	ZEPHIR_INIT_VAR(_11);
	zephir_substr(_11, charid, 12 , 4 , 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 16);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 4);
	ZEPHIR_INIT_VAR(_14);
	zephir_substr(_14, charid, 16 , 4 , 0);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, 20);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, 12);
	ZEPHIR_INIT_VAR(_17);
	zephir_substr(_17, charid, 20 , 12 , 0);
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_VVVVVVVVV(_18, _5, hyphen, _8, hyphen, _11, hyphen, _14, hyphen, _17);
	zephir_get_strval(uuid, _18);
	RETURN_CTOR(uuid);

}

/**
 * 生成完全限定类名。
 *
 * @return string
 */
PHP_METHOD(DotPHP_Utils_StringUtil, ns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *size = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&size, "func_num_args", NULL, 28);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(size, 0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 27);
	zephir_check_call_status();
	zephir_fast_join_str(return_value, SL("\\"), args TSRMLS_CC);
	RETURN_MM();

}

/**
 * IP 地址转换为整数。
 *
 * @param string $ip_addr 指定 IP 地址。
 * @return int
 */
PHP_METHOD(DotPHP_Utils_StringUtil, ip) {

	long v;
	zval *addr, *ips, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &addr);



	ZEPHIR_INIT_VAR(ips);
	zephir_fast_explode_str(ips, SL("."), addr, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_array_fetch_long(&_0, ips, 0, PH_NOISY, "dotphp/utils/stringutil.zep", 208 TSRMLS_CC);
	v = (zephir_get_intval(_0) * 16777216);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch_long(&_1, ips, 1, PH_NOISY, "dotphp/utils/stringutil.zep", 209 TSRMLS_CC);
	v += (zephir_get_intval(_1) * 65536);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_long(&_2, ips, 2, PH_NOISY, "dotphp/utils/stringutil.zep", 210 TSRMLS_CC);
	v += (zephir_get_intval(_2) * 256);
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_long(&_3, ips, 3, PH_NOISY, "dotphp/utils/stringutil.zep", 211 TSRMLS_CC);
	v += zephir_get_intval(_3);
	RETURN_MM_LONG(v);

}

/**
 * 对称加密算法 - (加密)。
 *
 * @param string s
 * @param string secure_key
 * @return string
 * @throws TypeException
 */
PHP_METHOD(DotPHP_Utils_StringUtil, encrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *s_param = NULL, *secure_key_param = NULL, *td = NULL, *td_size = NULL, *iv = NULL, *key, *ret = NULL, _0 = zval_used_for_init, _1, _2, _3, *_4 = NULL;
	zval *s = NULL, *secure_key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &s_param, &secure_key_param);

	zephir_get_strval(s, s_param);
	zephir_get_strval(secure_key, secure_key_param);


	if (ZEPHIR_IS_EMPTY(s)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "加密源字符串不能为空。", "dotphp/utils/stringutil.zep", 226);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "tripledes", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "ecb", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "", 0);
	ZEPHIR_CALL_FUNCTION(&td, "mcrypt_module_open", NULL, 38, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&td_size, "mcrypt_enc_get_iv_size", NULL, 39, td);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&iv, "mcrypt_create_iv", NULL, 40, td_size, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(key);
	zephir_substr(key, secure_key, 0 , zephir_get_intval(td_size), 0);
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_init", NULL, 41, td, key, iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "mcrypt_generic", NULL, 42, td, s);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ret, "base64_encode", NULL, 43, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_deinit", NULL, 44, td);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_module_close", NULL, 45, td);
	zephir_check_call_status();
	RETURN_CCTOR(ret);

}

/**
 * 对称加密算法 - (解密)。
 *
 * @param string s
 * @param string secure_key
 * @return string
 * @throws <\DotPHP\ArgumentException>
 */
PHP_METHOD(DotPHP_Utils_StringUtil, decrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *s_param = NULL, *secure_key_param = NULL, *td = NULL, *td_size = NULL, *iv = NULL, *key, *ret, _0 = zval_used_for_init, _1, _2, _3, *_4 = NULL, *_5 = NULL;
	zval *s = NULL, *secure_key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &s_param, &secure_key_param);

	zephir_get_strval(s, s_param);
	zephir_get_strval(secure_key, secure_key_param);


	if (ZEPHIR_IS_EMPTY(s)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(dotphp_argumentexception_ce, "解密源字符串不能为空。", "dotphp/utils/stringutil.zep", 256);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "tripledes", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "ecb", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "", 0);
	ZEPHIR_CALL_FUNCTION(&td, "mcrypt_module_open", NULL, 38, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&td_size, "mcrypt_enc_get_iv_size", NULL, 39, td);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&iv, "mcrypt_create_iv", NULL, 40, td_size, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(key);
	zephir_substr(key, secure_key, 0 , zephir_get_intval(td_size), 0);
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_init", NULL, 41, td, key, iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "base64_decode", NULL, 46, s);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "mdecrypt_generic", NULL, 47, td, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(ret);
	zephir_fast_trim(ret, _5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_deinit", NULL, 44, td);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_module_close", NULL, 45, td);
	zephir_check_call_status();
	RETURN_CCTOR(ret);

}

