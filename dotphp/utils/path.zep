namespace DotPHP\Utils;

/**
 * DotPHP 路径工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class Path {
    /**
     * 合并一个或多个路径符。
     *
     * @return string
     */
    static public function combin() -> string {
        var args, size, path, s;

        let args = func_get_args();
        let size = func_num_args();

        if size <= 0 {
            return "";
        }

        let path = implode(DIRECTORY_SEPARATOR, args);
        let s = preg_replace("/[\\/]+/i", DIRECTORY_SEPARATOR, path);

        return s;
    }
}