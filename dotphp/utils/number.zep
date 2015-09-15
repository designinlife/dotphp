namespace DotPHP\Utils;

/**
 * DotPHP 数字工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class Number {
    /**
     * 检查 num 数值是否为素数？
     *
     * @param int num
     * @return boolean
     */
    static public function isPrime(int num) -> boolean {
        if num == 1 {
            return false;
        }

        if num == 2 {
            return true;
        }

        if 0 == (num % 2) {
            return false;
        }

        int i;
        var end;

        let end = ceil(sqrt(num));

        for i in range(3, end, 2) {
            if 0 == (num % i) {
                return false;
            }
        }

        return true;
    }
}