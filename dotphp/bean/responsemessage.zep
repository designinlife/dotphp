namespace DotPHP\Bean;

/**
 * ResponseMessage 消息协议类。
 *
 * --------------------------------------------------------
 * @author        Lei Lee <web.developer.network@gmail.com>
 * @version       0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * @package       Application\Entity
 * --------------------------------------------------------
 */
class ResponseMessage extends AbstractResponseMessage {
    /**
     * 数据编码输出。
     *
     * @return string
     */
    public function encode() -> string {
        array d;
        var s, es;
        int len;

        let d = [
            "o": this->_op_code,
            "c": this->_module,
            "m": this->_method,
            "d": this->_data,
            "t": time(),
            "r": this->_errno,
            "e": this->_errstr
        ];

        let s   = \DotPHP\Utils\Encoder::encode(d, \DotPHP\Utils\Encoder::MSGPACK);
        let len = strlen(s);
        let es  = pack("cNa*", false, len, s);
        // let es  = pack("Na*", len, s);

        return es;
    }

    /**
     * 字符串转换输出。
     * 
     * @return string
     */
    public function __toString() -> string {
        return this->encode();
    }
}