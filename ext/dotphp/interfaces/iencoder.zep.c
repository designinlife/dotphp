
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * DotPHP - 编/解码器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
ZEPHIR_INIT_CLASS(DotPHP_Interfaces_IEncoder) {

	ZEPHIR_REGISTER_INTERFACE(DotPHP\\Interfaces, IEncoder, dotphp, interfaces_iencoder, dotphp_interfaces_iencoder_method_entry);

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
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IEncoder, encode);

/**
 * 数据解码。
 * 
 * @param string data
 * @param int enc_type
 * @return mixed
 */
ZEPHIR_DOC_METHOD(DotPHP_Interfaces_IEncoder, decode);

