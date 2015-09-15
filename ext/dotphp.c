
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "dotphp.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *dotphp_interfaces_icontroller_ce;
zend_class_entry *dotphp_interfaces_idb_ce;
zend_class_entry *dotphp_interfaces_iencoder_ce;
zend_class_entry *dotphp_interfaces_ilogger_ce;
zend_class_entry *dotphp_interfaces_iswooleeventdispatcher_ce;
zend_class_entry *dotphp_interfaces_itemplate_ce;
zend_class_entry *dotphp_baseexception_ce;
zend_class_entry *dotphp_base_dotbase_ce;
zend_class_entry *dotphp_abstractbootstrap_ce;
zend_class_entry *dotphp_argumentexception_ce;
zend_class_entry *dotphp_base_swoolebase_ce;
zend_class_entry *dotphp_base_webcontrollerbase_ce;
zend_class_entry *dotphp_bean_abstractresponsemessage_ce;
zend_class_entry *dotphp_bean_dbparameter_ce;
zend_class_entry *dotphp_bean_routemessage_ce;
zend_class_entry *dotphp_configurationexception_ce;
zend_class_entry *dotphp_core_genericlogger_ce;
zend_class_entry *dotphp_core_socketclient_ce;
zend_class_entry *dotphp_core_swooleeventdispatcher_ce;
zend_class_entry *dotphp_dataexception_ce;
zend_class_entry *dotphp_db_dbpdo_ce;
zend_class_entry *dotphp_dbexception_ce;
zend_class_entry *dotphp_dot_ce;
zend_class_entry *dotphp_httpexception_ce;
zend_class_entry *dotphp_notimplementedexception_ce;
zend_class_entry *dotphp_parseexception_ce;
zend_class_entry *dotphp_permissionexception_ce;
zend_class_entry *dotphp_runtimeexception_ce;
zend_class_entry *dotphp_socketexception_ce;
zend_class_entry *dotphp_swoolebootstrap_ce;
zend_class_entry *dotphp_utils_arrayutil_ce;
zend_class_entry *dotphp_utils_encoder_ce;
zend_class_entry *dotphp_utils_number_ce;
zend_class_entry *dotphp_utils_path_ce;
zend_class_entry *dotphp_utils_probability_ce;
zend_class_entry *dotphp_utils_stringutil_ce;
zend_class_entry *dotphp_validateexception_ce;
zend_class_entry *dotphp_webbootstrap_ce;

ZEND_DECLARE_MODULE_GLOBALS(dotphp)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(dotphp)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(DotPHP_Interfaces_IController);
	ZEPHIR_INIT(DotPHP_Interfaces_IDb);
	ZEPHIR_INIT(DotPHP_Interfaces_IEncoder);
	ZEPHIR_INIT(DotPHP_Interfaces_ILogger);
	ZEPHIR_INIT(DotPHP_Interfaces_ISwooleEventDispatcher);
	ZEPHIR_INIT(DotPHP_Interfaces_ITemplate);
	ZEPHIR_INIT(DotPHP_BaseException);
	ZEPHIR_INIT(DotPHP_Base_DotBase);
	ZEPHIR_INIT(DotPHP_AbstractBootstrap);
	ZEPHIR_INIT(DotPHP_ArgumentException);
	ZEPHIR_INIT(DotPHP_Base_SwooleBase);
	ZEPHIR_INIT(DotPHP_Base_WebControllerBase);
	ZEPHIR_INIT(DotPHP_Bean_AbstractResponseMessage);
	ZEPHIR_INIT(DotPHP_Bean_DbParameter);
	ZEPHIR_INIT(DotPHP_Bean_RouteMessage);
	ZEPHIR_INIT(DotPHP_ConfigurationException);
	ZEPHIR_INIT(DotPHP_Core_GenericLogger);
	ZEPHIR_INIT(DotPHP_Core_SocketClient);
	ZEPHIR_INIT(DotPHP_Core_SwooleEventDispatcher);
	ZEPHIR_INIT(DotPHP_DB_DbPdo);
	ZEPHIR_INIT(DotPHP_DataException);
	ZEPHIR_INIT(DotPHP_DbException);
	ZEPHIR_INIT(DotPHP_Dot);
	ZEPHIR_INIT(DotPHP_HttpException);
	ZEPHIR_INIT(DotPHP_NotImplementedException);
	ZEPHIR_INIT(DotPHP_ParseException);
	ZEPHIR_INIT(DotPHP_PermissionException);
	ZEPHIR_INIT(DotPHP_RuntimeException);
	ZEPHIR_INIT(DotPHP_SocketException);
	ZEPHIR_INIT(DotPHP_SwooleBootstrap);
	ZEPHIR_INIT(DotPHP_Utils_ArrayUtil);
	ZEPHIR_INIT(DotPHP_Utils_Encoder);
	ZEPHIR_INIT(DotPHP_Utils_Number);
	ZEPHIR_INIT(DotPHP_Utils_Path);
	ZEPHIR_INIT(DotPHP_Utils_Probability);
	ZEPHIR_INIT(DotPHP_Utils_StringUtil);
	ZEPHIR_INIT(DotPHP_ValidateException);
	ZEPHIR_INIT(DotPHP_WebBootstrap);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(dotphp)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_dotphp_globals *dotphp_globals TSRMLS_DC)
{
	dotphp_globals->initialized = 0;

	/* Memory options */
	dotphp_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	dotphp_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	dotphp_globals->cache_enabled = 1;

	/* Recursive Lock */
	dotphp_globals->recursive_lock = 0;

	/* Static cache */
	memset(dotphp_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(dotphp)
{

	zend_dotphp_globals *dotphp_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(dotphp_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(dotphp_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(dotphp)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(dotphp)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_DOTPHP_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_DOTPHP_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_DOTPHP_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_DOTPHP_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_DOTPHP_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(dotphp)
{
	php_zephir_init_globals(dotphp_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(dotphp)
{

}


zend_function_entry php_dotphp_functions[] = {
ZEND_FE_END

};

zend_module_entry dotphp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_DOTPHP_EXTNAME,
	php_dotphp_functions,
	PHP_MINIT(dotphp),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(dotphp),
#else
	NULL,
#endif
	PHP_RINIT(dotphp),
	PHP_RSHUTDOWN(dotphp),
	PHP_MINFO(dotphp),
	PHP_DOTPHP_VERSION,
	ZEND_MODULE_GLOBALS(dotphp),
	PHP_GINIT(dotphp),
	PHP_GSHUTDOWN(dotphp),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_DOTPHP
ZEND_GET_MODULE(dotphp)
#endif
