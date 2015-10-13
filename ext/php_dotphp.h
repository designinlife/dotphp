
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_DOTPHP_H
#define PHP_DOTPHP_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_DOTPHP_NAME        "DotPHP"
#define PHP_DOTPHP_VERSION     "0.1.2 alpha"
#define PHP_DOTPHP_EXTNAME     "dotphp"
#define PHP_DOTPHP_AUTHOR      "Lei Lee"
#define PHP_DOTPHP_ZEPVERSION  "0.9a-dev"
#define PHP_DOTPHP_DESCRIPTION "A simple PHP framework for TCP Socket / Web / CLI environment for rapid development."



ZEND_BEGIN_MODULE_GLOBALS(dotphp)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
	zend_bool debug;


ZEND_END_MODULE_GLOBALS(dotphp)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(dotphp)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(dotphp_globals_id, zend_dotphp_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (dotphp_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_dotphp_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(dotphp_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(dotphp_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def dotphp_globals
#define zend_zephir_globals_def zend_dotphp_globals

extern zend_module_entry dotphp_module_entry;
#define phpext_dotphp_ptr &dotphp_module_entry

#endif
