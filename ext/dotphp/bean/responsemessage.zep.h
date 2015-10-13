
extern zend_class_entry *dotphp_bean_responsemessage_ce;

ZEPHIR_INIT_CLASS(DotPHP_Bean_ResponseMessage);

PHP_METHOD(DotPHP_Bean_ResponseMessage, encode);
PHP_METHOD(DotPHP_Bean_ResponseMessage, __toString);

ZEPHIR_INIT_FUNCS(dotphp_bean_responsemessage_method_entry) {
	PHP_ME(DotPHP_Bean_ResponseMessage, encode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(DotPHP_Bean_ResponseMessage, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
