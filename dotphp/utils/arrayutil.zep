namespace DotPHP\Utils;

/**
 * DotPHP 数组工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class ArrayUtil {
    /**
     * 检查数组是否包含 Associative 键？
     *
     * @param array arr
     * @param bool  reusingKeys
     * @return bool
     */
    static public function isAssoc(array arr, boolean reusingKeys = false) -> boolean {
        var r;

        let r = range(0, count(arr) - 1);

        return reusingKeys ? arr !== r : array_keys(arr) !== r;
    }
}