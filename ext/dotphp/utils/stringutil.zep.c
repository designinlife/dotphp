
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
	zval *data, *_3$$4, _4$$4, _5$$4;

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
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_STRING(&_4$$4, "'", 0);
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "\\'", 0);
		zephir_fast_str_replace(&_3$$4, &_4$$4, &_5$$4, data TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "'", _3$$4, "'");
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
	zval *message_param = NULL, *vars_param = NULL, *prefix = NULL, *key = NULL, *value = NULL, **_2, *_3$$3 = NULL;
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
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSVS(_3$$3, prefix, "{", key, "}");
		ZEPHIR_INIT_NVAR(ss);
		zephir_fast_str_replace(&ss, _3$$3, value, message TSRMLS_CC);
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

	zval *_5$$3 = NULL;
	zend_bool _0;
	zval *args = NULL, *size = NULL, *str = NULL, *_2 = NULL, *_3$$3 = NULL, _4$$3 = zval_used_for_init, *_6$$3;
	int ZEPHIR_LAST_CALL_STATUS, i = 0, _1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 29);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&size, "func_num_args", NULL, 30);
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
			ZEPHIR_INIT_NVAR(_3$$3);
			ZEPHIR_SINIT_NVAR(_4$$3);
			ZVAL_LONG(&_4$$3, ((i - 1)));
			ZEPHIR_INIT_LNVAR(_5$$3);
			ZEPHIR_CONCAT_SVS(_5$$3, "{", &_4$$3, "}");
			zephir_array_fetch_long(&_6$$3, args, i, PH_NOISY | PH_READONLY, "dotphp/utils/stringutil.zep", 63 TSRMLS_CC);
			zephir_fast_str_replace(&_3$$3, _5$$3, _6$$3, str TSRMLS_CC);
			ZEPHIR_CPY_WRT(str, _3$$3);
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

	int ZEPHIR_LAST_CALL_STATUS, v = 0;
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


	ZEPHIR_CALL_FUNCTION(&_0, "mb_strlen", NULL, 33, str, encoding);
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

	zval *i, *p;
	int ZEPHIR_LAST_CALL_STATUS, n = 0, t = 0, a = 0, len = 0, _1$$3, _2$$3, _10$$3, _11$$3, _17$$6, _18$$6, _31$$10, _32$$10, _38$$13;
	zephir_fcall_cache_entry *_7 = NULL, *_20 = NULL;
	zval *pass_key = NULL;
	zend_bool to_num, _0$$3, _9$$3, _16$$6, _30$$10;
	zval *input = NULL, *to_num_param = NULL, *pad_up = NULL, *pass_key_param = NULL, *out = NULL, *index = NULL, *base = NULL, *pass_hash = NULL, *bcp = NULL, _6$$3 = zval_used_for_init, *_8$$3 = NULL, *_15$$3, _3$$4 = zval_used_for_init, _4$$4 = zval_used_for_init, *_5$$4 = NULL, _12$$5 = zval_used_for_init, _13$$5 = zval_used_for_init, *_14$$5 = NULL, _19$$7 = zval_used_for_init, _21$$7 = zval_used_for_init, *_22$$7 = NULL, *_23$$7 = NULL, _24$$7 = zval_used_for_init, *_25$$7 = NULL, *_26$$9, *_27$$12, *_28$$10 = NULL, *_29$$10 = NULL, _33$$13 = zval_used_for_init, _34$$13 = zval_used_for_init, _35$$13 = zval_used_for_init, *_36$$13 = NULL, *_37$$13 = NULL;

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
		_2$$3 = (len - 1);
		_1$$3 = 0;
		_0$$3 = 0;
		if (_1$$3 <= _2$$3) {
			while (1) {
				if (_0$$3) {
					_1$$3++;
					if (!(_1$$3 <= _2$$3)) {
						break;
					}
				} else {
					_0$$3 = 1;
				}
				n = _1$$3;
				ZEPHIR_SINIT_NVAR(_3$$4);
				ZVAL_LONG(&_3$$4, n);
				ZEPHIR_SINIT_NVAR(_4$$4);
				ZVAL_LONG(&_4$$4, 1);
				ZEPHIR_INIT_NVAR(_5$$4);
				zephir_substr(_5$$4, index, zephir_get_intval(&_3$$4), 1 , 0);
				zephir_array_append(&i, _5$$4, PH_SEPARATE, "dotphp/utils/stringutil.zep", 105);
			}
		}
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "sha256", 0);
		ZEPHIR_CALL_FUNCTION(&pass_hash, "hash", &_7, 34, &_6$$3, pass_key);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$3);
		if (zephir_fast_strlen_ev(pass_hash) < zephir_fast_strlen_ev(index)) {
			ZEPHIR_SINIT_NVAR(_6$$3);
			ZVAL_STRING(&_6$$3, "sha512", 0);
			ZEPHIR_CALL_FUNCTION(&_8$$3, "hash", &_7, 34, &_6$$3, pass_key);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(_8$$3, pass_hash);
		}
		ZEPHIR_CPY_WRT(pass_hash, _8$$3);
		len = zephir_fast_strlen_ev(index);
		_11$$3 = (len - 1);
		_10$$3 = 0;
		_9$$3 = 0;
		if (_10$$3 <= _11$$3) {
			while (1) {
				if (_9$$3) {
					_10$$3++;
					if (!(_10$$3 <= _11$$3)) {
						break;
					}
				} else {
					_9$$3 = 1;
				}
				n = _10$$3;
				ZEPHIR_SINIT_NVAR(_12$$5);
				ZVAL_LONG(&_12$$5, n);
				ZEPHIR_SINIT_NVAR(_13$$5);
				ZVAL_LONG(&_13$$5, 1);
				ZEPHIR_INIT_NVAR(_14$$5);
				zephir_substr(_14$$5, pass_hash, zephir_get_intval(&_12$$5), 1 , 0);
				zephir_array_append(&p, _14$$5, PH_SEPARATE, "dotphp/utils/stringutil.zep", 113);
			}
		}
		ZEPHIR_INIT_VAR(_15$$3);
		ZVAL_LONG(_15$$3, 3);
		ZEPHIR_MAKE_REF(p);
		ZEPHIR_CALL_FUNCTION(NULL, "array_multisort", NULL, 35, p, _15$$3, i);
		ZEPHIR_UNREF(p);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(index);
		zephir_fast_join_str(index, SL(""), i TSRMLS_CC);
	}
	if (to_num) {
		len = (zephir_fast_strlen_ev(input) - 1);
		_18$$6 = len;
		_17$$6 = _18$$6;
		_16$$6 = 0;
		if (_17$$6 >= 0) {
			while (1) {
				if (_16$$6) {
					_17$$6--;
					if (!(_17$$6 >= 0)) {
						break;
					}
				} else {
					_16$$6 = 1;
				}
				t = _17$$6;
				ZEPHIR_SINIT_NVAR(_19$$7);
				ZVAL_LONG(&_19$$7, (len - t));
				ZEPHIR_CALL_FUNCTION(&bcp, "bcpow", &_20, 36, base, &_19$$7);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_19$$7);
				ZVAL_LONG(&_19$$7, t);
				ZEPHIR_SINIT_NVAR(_21$$7);
				ZVAL_LONG(&_21$$7, 1);
				ZEPHIR_INIT_NVAR(_22$$7);
				zephir_substr(_22$$7, input, zephir_get_intval(&_19$$7), 1 , 0);
				ZEPHIR_INIT_NVAR(_23$$7);
				zephir_fast_strpos(_23$$7, index, _22$$7, 0 );
				ZEPHIR_SINIT_NVAR(_24$$7);
				mul_function(&_24$$7, _23$$7, bcp TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_25$$7);
				zephir_add_function(_25$$7, out, &_24$$7);
				ZEPHIR_CPY_WRT(out, _25$$7);
			}
		}
		if (zephir_is_numeric(pad_up)) {
			ZEPHIR_SEPARATE(pad_up);
			zephir_decrement(pad_up);
			if (ZEPHIR_GT_LONG(pad_up, 0)) {
				ZEPHIR_INIT_VAR(_26$$9);
				zephir_pow_function(_26$$9, base, pad_up);
				ZEPHIR_SUB_ASSIGN(out, _26$$9);
			}
		}
	} else {
		if (zephir_is_numeric(pad_up)) {
			ZEPHIR_SEPARATE(pad_up);
			zephir_decrement(pad_up);
			if (ZEPHIR_GT_LONG(pad_up, 0)) {
				ZEPHIR_INIT_VAR(_27$$12);
				zephir_pow_function(_27$$12, base, pad_up);
				ZEPHIR_ADD_ASSIGN(input, _27$$12);
			}
		}
		ZEPHIR_INIT_VAR(_28$$10);
		if (!ZEPHIR_IS_LONG(input, 0)) {
			ZEPHIR_CALL_FUNCTION(&_29$$10, "log", NULL, 37, input, base);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_28$$10);
			ZVAL_DOUBLE(_28$$10, zephir_floor(_29$$10 TSRMLS_CC));
		} else {
			ZEPHIR_INIT_NVAR(_28$$10);
			ZVAL_LONG(_28$$10, 0);
		}
		len = zephir_get_numberval(_28$$10);
		_32$$10 = len;
		_31$$10 = _32$$10;
		_30$$10 = 0;
		if (_31$$10 >= 0) {
			while (1) {
				if (_30$$10) {
					_31$$10--;
					if (!(_31$$10 >= 0)) {
						break;
					}
				} else {
					_30$$10 = 1;
				}
				t = _31$$10;
				ZEPHIR_SINIT_NVAR(_33$$13);
				ZVAL_LONG(&_33$$13, t);
				ZEPHIR_CALL_FUNCTION(&bcp, "bcpow", &_20, 36, base, &_33$$13);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_33$$13);
				div_function(&_33$$13, input, bcp TSRMLS_CC);
				a = (long) (zephir_safe_mod_double_zval(zephir_floor(&_33$$13 TSRMLS_CC), base TSRMLS_CC));
				ZEPHIR_SINIT_NVAR(_34$$13);
				ZVAL_LONG(&_34$$13, a);
				ZEPHIR_SINIT_NVAR(_35$$13);
				ZVAL_LONG(&_35$$13, 1);
				ZEPHIR_INIT_NVAR(_36$$13);
				zephir_substr(_36$$13, index, zephir_get_intval(&_34$$13), 1 , 0);
				ZEPHIR_INIT_LNVAR(_37$$13);
				ZEPHIR_CONCAT_VV(_37$$13, out, _36$$13);
				ZEPHIR_CPY_WRT(out, _37$$13);
				_38$$13 = (zephir_get_numberval(input) - ((a * zephir_get_numberval(bcp))));
				ZEPHIR_INIT_NVAR(input);
				ZVAL_LONG(input, _38$$13);
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

	zval *hyphen = NULL, *uuid = NULL;
	zval *charid = NULL, *_0, *_1 = NULL, *_2 = NULL, _3, _4, *_5, _6, _7, *_8, _9, _10, *_11, _12, _13, *_14, _15, _16, *_17, *_18;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "mt_rand", NULL, 38);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "uniqid", NULL, 39, _1, ZEPHIR_GLOBAL(global_true));
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

	zval *args = NULL, *size = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&size, "func_num_args", NULL, 30);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(size, 0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 29);
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

	long v = 0;
	zval *addr, *ips = NULL, *_0, *_1, *_2, *_3;

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
	zval *s_param = NULL, *secure_key_param = NULL, *td = NULL, *td_size = NULL, *iv = NULL, *key = NULL, *ret = NULL, _0 = zval_used_for_init, _1, _2, _3, *_4 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&td, "mcrypt_module_open", NULL, 40, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&td_size, "mcrypt_enc_get_iv_size", NULL, 41, td);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&iv, "mcrypt_create_iv", NULL, 42, td_size, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(key);
	zephir_substr(key, secure_key, 0 , zephir_get_intval(td_size), 0);
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_init", NULL, 43, td, key, iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "mcrypt_generic", NULL, 44, td, s);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ret, "base64_encode", NULL, 45, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_deinit", NULL, 46, td);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_module_close", NULL, 47, td);
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
	zval *s_param = NULL, *secure_key_param = NULL, *td = NULL, *td_size = NULL, *iv = NULL, *key = NULL, *ret = NULL, _0 = zval_used_for_init, _1, _2, _3, *_4 = NULL, *_5 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&td, "mcrypt_module_open", NULL, 40, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&td_size, "mcrypt_enc_get_iv_size", NULL, 41, td);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&iv, "mcrypt_create_iv", NULL, 42, td_size, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(key);
	zephir_substr(key, secure_key, 0 , zephir_get_intval(td_size), 0);
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_init", NULL, 43, td, key, iv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "base64_decode", NULL, 48, s);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "mdecrypt_generic", NULL, 49, td, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(ret);
	zephir_fast_trim(ret, _5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_deinit", NULL, 46, td);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_module_close", NULL, 47, td);
	zephir_check_call_status();
	RETURN_CCTOR(ret);

}

