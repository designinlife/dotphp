namespace DotPHP\Utils;

/**
 * 数据编码/解码工具类。
 * 
 * 注: 目前仅支持 JSON/MessagePack/igbinary 三种数据格式。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
final class Encoder implements \DotPHP\Interfaces\IEncoder {
	const JSON = 1;
	const MSGPACK = 2;
	const IGBINARY = 3;
	const AMF = 4;
	const XML = 5;

    /**
     * 数据编码。
     * 
     * @param mixed data
     * @param int enc_type
     * @param int options
     * @return string
     */
	static public function encode(data, int enc_type = 2, int options = 320) {
		switch (enc_type) {
			case 1:
                return json_encode(data, options);
            case 2:
                return msgpack_serialize(data);
            case 3:
                return igbinary_serialize(data);
            // case 4:
            //     return amf3_encode(data);
            default:
                throw new \DotPHP\NotImplementedException("接口尚未实现。");
		}
	}

    /**
     * 数据解码。
     * 
     * @param string data
     * @param int enc_type
     * @return mixed
     */
    static public function decode(data, int enc_type = 2) {
		switch (enc_type) {
			case 1:
                return json_decode(data, true);
            case 2:
                return msgpack_unserialize(data);
            case 3:
                return igbinary_unserialize(data);
            // case 4:
            //     return amf3_decode(data);
            default:
                throw new \DotPHP\NotImplementedException("接口尚未实现。");
		}
	}
}