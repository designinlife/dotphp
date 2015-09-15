namespace DotPHP\Interfaces;

/**
 * DotPHP - 编/解码器接口。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
interface IEncoder {
    /**
     * 数据编码。
     * 
     * @param mixed data
     * @param int enc_type
     * @param int options
     * @return string
     */
    static function encode(data, int enc_type = 1, int options = 0);

    /**
     * 数据解码。
     * 
     * @param string data
     * @param int enc_type
     * @return mixed
     */
    static function decode(data, int enc_type = 2);
}