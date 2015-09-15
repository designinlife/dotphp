
extern zend_class_entry *dotphp_dbexception_ce;

ZEPHIR_INIT_CLASS(DotPHP_DbException);

PHP_METHOD(DotPHP_DbException, __construct);
PHP_METHOD(DotPHP_DbException, getSql);
PHP_METHOD(DotPHP_DbException, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_dotphp_dbexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_OBJ_INFO(0, previous, Exception, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(dotphp_dbexception_method_entry) {
	PHP_ME(DotPHP_DbException, __construct, arginfo_dotphp_dbexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(DotPHP_DbException, getSql, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_DbException, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
