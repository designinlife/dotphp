<?php

namespace DotPHP\Utils;

/**
 * DotPHP 概率相关工具类。
 * -------------------------------------------------
 *
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class Probability
{

    /**
     * 概率计算函数。检测传入的概率值是否命中？
     *
     * @throws ArgumentException
     * @param double $rate 
     * @param float $$rate 指定概率值。(此值必须是 0~1 之间的浮点数。包含0,1两个整数.)
     * @return boolean True 时，表示已命中。
     */
    static public function hit($rate) {}

    /**
     * 抽奖计算。
     *
     * @param array ratios
     * 指定概率列表。
     * @return int string
     * 返回中奖的元素 key 值。
     * @param array $ratios 
     * @return int|string|bool 
     */
    static public function lottery($ratios) {}

}
