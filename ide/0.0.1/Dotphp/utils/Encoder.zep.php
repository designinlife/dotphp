<?php

namespace DotPHP\Utils;

/**
 * 数据对象编/解码器。
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 */
final class Encoder implements \DotPHP\Interfaces\IEncoder
{

    const JSON = 1;


    const MSGPACK = 2;


    const IGBINARY = 3;


    const AMF = 4;


    const XML = 5;


    /**
     * 数据编码。
     *
     * @param mixed $data 
     * @param int $enc_type 
     * @param int $options 
     * @return string 
     */
    static public function encode($data, $enc_type = 2, $options = 320) {}

    /**
     * 数据解码。
     *
     * @param string $data 
     * @param int $enc_type 
     * @return mixed 
     */
    static public function decode($data, $enc_type = 2) {}

}
