PHP_ARG_ENABLE(dotphp, whether to enable dotphp, [ --enable-dotphp   Enable Dotphp])

if test "$PHP_DOTPHP" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, DOTPHP_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_DOTPHP, 1, [Whether you have Dotphp])
	dotphp_sources="dotphp.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c dotphp/baseexception.zep.c
	dotphp/base/dotbase.zep.c
	dotphp/abstractbootstrap.zep.c
	dotphp/interfaces/icontroller.zep.c
	dotphp/base/processbase.zep.c
	dotphp/bean/abstractresponsemessage.zep.c
	dotphp/interfaces/idb.zep.c
	dotphp/interfaces/iencoder.zep.c
	dotphp/interfaces/ilogger.zep.c
	dotphp/interfaces/iswooleeventdispatcher.zep.c
	dotphp/argumentexception.zep.c
	dotphp/base/multiprocessbase.zep.c
	dotphp/base/swoolebase.zep.c
	dotphp/base/webcontrollerbase.zep.c
	dotphp/bean/cacheparameter.zep.c
	dotphp/bean/dbparameter.zep.c
	dotphp/bean/responsemessage.zep.c
	dotphp/bean/routemessage.zep.c
	dotphp/clibootstrap.zep.c
	dotphp/configurationexception.zep.c
	dotphp/core/genericlogger.zep.c
	dotphp/core/socketclient.zep.c
	dotphp/core/swooleeventdispatcher.zep.c
	dotphp/dataexception.zep.c
	dotphp/db/dbpdo.zep.c
	dotphp/dbexception.zep.c
	dotphp/dot.zep.c
	dotphp/filenotfoundexception.zep.c
	dotphp/httpexception.zep.c
	dotphp/interfaces/iprocess.zep.c
	dotphp/interfaces/irouteparser.zep.c
	dotphp/interfaces/itemplate.zep.c
	dotphp/notimplementedexception.zep.c
	dotphp/parseexception.zep.c
	dotphp/permissionexception.zep.c
	dotphp/runtimeexception.zep.c
	dotphp/socketexception.zep.c
	dotphp/swoolebootstrap.zep.c
	dotphp/utils/arrayutil.zep.c
	dotphp/utils/encoder.zep.c
	dotphp/utils/number.zep.c
	dotphp/utils/path.zep.c
	dotphp/utils/probability.zep.c
	dotphp/utils/stringutil.zep.c
	dotphp/validateexception.zep.c
	dotphp/webbootstrap.zep.c "
	PHP_NEW_EXTENSION(dotphp, $dotphp_sources, $ext_shared,, )
	PHP_SUBST(DOTPHP_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([dotphp], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([dotphp], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/dotphp], [php_DOTPHP.h])

fi
