
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
#include "kernel/exception.h"
#include "kernel/math.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


/**
 * DotPHP 概率相关工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Utils_Probability) {

	ZEPHIR_REGISTER_CLASS(DotPHP\\Utils, Probability, dotphp, utils_probability, dotphp_utils_probability_method_entry, 0);

	return SUCCESS;

}

/**
 * 概率计算函数。检测传入的概率值是否命中？
 *
 * @param float $rate 指定概率值。(此值必须是 0~1 之间的浮点数。包含0,1两个整数.)
 * @return boolean 返回 True 时，表示已命中。
 * @throws ArgumentException
 */
PHP_METHOD(DotPHP_Utils_Probability, hit) {

	int r = 0, v = 0;
	zend_bool _0;
	zval *rate_param = NULL, _1, _2;
	double rate;

	zephir_fetch_params(0, 1, 0, &rate_param);

	rate = zephir_get_doubleval(rate_param);


	_0 = rate > 1;
	if (!(_0)) {
		_0 = rate < 0;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(dotphp_argumentexception_ce, "传入的概率值 $rate 必须是 0~1 之间的浮点数或整数(0|1)。", "dotphp/utils/probability.zep", 22);
		return;
	}
	r = (long) ((double) (100 * rate));
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 100);
	v = zephir_mt_rand(zephir_get_intval(&_1), zephir_get_intval(&_2) TSRMLS_CC);
	if (v <= r) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

/**
 * 抽奖计算。
 *
 * @param array ratios
 *            指定概率列表。
 * @return int string
 *            返回中奖的元素 key 值。
 */
PHP_METHOD(DotPHP_Utils_Probability, lottery) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ratios_param = NULL, *result = NULL, *key = NULL, *proCur = NULL, *proSum = NULL, *randNum = NULL, **_2, _3$$3 = zval_used_for_init;
	zval *ratios = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ratios_param);

	zephir_get_arrval(ratios, ratios_param);


	ZEPHIR_INIT_VAR(result);
	ZVAL_BOOL(result, 0);
	ZEPHIR_CALL_FUNCTION(&proSum, "array_sum", NULL, 32, ratios);
	zephir_check_call_status();
	zephir_is_iterable(ratios, &_1, &_0, 0, 0, "dotphp/utils/probability.zep", 64);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(proCur, _2);
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_INIT_NVAR(randNum);
		ZVAL_LONG(randNum, zephir_mt_rand(zephir_get_intval(&_3$$3), zephir_get_intval(proSum) TSRMLS_CC));
		if (ZEPHIR_LE(randNum, proCur)) {
			ZEPHIR_CPY_WRT(result, key);
			break;
		} else {
			ZEPHIR_SUB_ASSIGN(proSum, proCur);
		}
	}
	RETURN_CCTOR(result);

}

