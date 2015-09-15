namespace DotPHP\Utils;

/**
 * DotPHP 字符串工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class StringUtil {
    /**
     * 在查询中使用一个字符串。
     * 
     * @param var data
     * @return var
     */
    static public function quote(var data) -> var {
        if (typeof data == "int") || (typeof data == "long") || (typeof data == "float") || (typeof data == "double") {
            return data;
        } else {
            return "'" . str_replace("'", "\\'", data) . "'";
        }
    }

    /**
     * 替换字符串变量。
     *
     * @param string message 指定消息文本内容。
     * @param array  vars    指定 HashMap 键值对列表。
     * @param string prefix  指定变量命名规范前缀字符。(可选 | 默认: % 百分号)
     * @return string
     */
    static public function translate(string message, array vars, prefix = "%") -> string {
        var key, value;
        string ss;

        for key, value in vars {
            let ss = str_replace(prefix . "{" . key . "}", value, message);
        }

        return ss;
    }

    /**
     * 字符串变量替换。(支持可变参数)
     *
     * @return string
     * @example
     *            [Call]:   Util::substitute('My name is {1}, an alias, also called {0}! {2}-year-old.', 'Lei', 'Li Lei', 30);
     *            [Output]: My name is Li Lei, an alias, also called Lei! 30-year-old.
     */
    static public function substitute() -> string {
        var args, size, str;
        int i;

        let args = func_get_args();
        let size = func_num_args();
        let str  = args[0];

        for i in range(1, size) {
            let str = str_replace("{" . (i - 1) . "}", args[i], str);
        }

        return str;
    }

    /**
     * 获取字符串真实长度。(注: 中文以 2 个字节计算)
     *
     * @param string str      指定测试字符串。
     * @param string encoding 指定字符串编码。(默认值: UTF-8)
     * @return int
     */
    static public function length(string str, string encoding = "UTF-8") -> int {
        int v;
        let v = (strlen(str) + mb_strlen(str, encoding)) / 2;

        return v;
    }

    /**
     * 生成 alpha ID 编码。
     *
     * @param int|string  in       String or long input to translate
     * @param boolean     to_num   Reverses translation when true
     * @param int|boolean pad_up   Number or boolean padds the result up to a specified length
     * @param string      pass_key Supplying a password makes it harder to calculate the original ID
     * @return string
     */
    static public function alphaID(var input, boolean to_num = false, var pad_up = false, string pass_key = null) -> var {
        var out, index, base, pass_hash, bcp;
        int n, t, a, len;
        array i = [], p = [];

        let out   = "";
        let index = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        let base  = strlen(index);

        if (pass_key !== null) {
            let len = strlen(index);

            for n in range(0, len - 1) {
                let i[] = substr(index, n, 1);
            }

            let pass_hash = hash("sha256", pass_key);
            let pass_hash = (strlen(pass_hash) < strlen(index) ? hash("sha512", pass_key) : pass_hash);

            let len = strlen(index);
            for n in range(0, len - 1) {
                let p[] = substr(pass_hash, n, 1);
            }

            array_multisort(p, SORT_DESC, i);
            let index = implode("", i);
        }

        if to_num {
            let len = strlen(input) - 1;
            
            for t in reverse range(0, len) {
                let bcp = bcpow(base, len - t);
                let out = out + strpos(index, substr(input, t, 1)) * bcp;
            }

            if (is_numeric(pad_up)) {
                let pad_up--;

                if (pad_up > 0) {
                    let out -= pow(base, pad_up);
                }
            }
        } else {
            if (is_numeric(pad_up)) {
                let pad_up--;

                if (pad_up > 0) {
                    let input += pow(base, pad_up);
                }
            }

            let len = input != 0 ? floor(log(input, base)) : 0;

            for t in reverse range(0, len) {
                let bcp = bcpow(base, t);
                let a   = floor(input / bcp) % base;
                let out = out . substr(index, a, 1);
                let input  = input - (a * bcp);
            }
        }

        return out;
    }

    /**
     * 生成 GUID 全球唯一标识。
     *
     * @return string
     */
    static public function guid() -> string {
        var charid;
        string hyphen, uuid;

        let charid = strtoupper(md5(uniqid(mt_rand(), true)));
        let hyphen = "-";
        let uuid   = substr(charid,  0,  8) . hyphen
                   . substr(charid,  8,  4) . hyphen
                   . substr(charid, 12,  4) . hyphen
                   . substr(charid, 16,  4) . hyphen
                   . substr(charid, 20, 12);

        return uuid;
    }

    /**
     * 生成完全限定类名。
     *
     * @return string
     */
    static public function ns() -> string {
        var args, size;

        let size = func_num_args();

        if size <= 0 {
            return "";
        }

        let args = func_get_args();

        return implode("\\", args);
    }

    /**
     * IP 地址转换为整数。
     *
     * @param string $ip_addr 指定 IP 地址。
     * @return int
     */
    static public function ip(addr) -> int {
        var ips;
        long v;

        let ips = explode(".", addr);

        let v  = ( int ) ips[0] * 16777216;
        let v += ( int ) ips[1] * 65536;
        let v += ( int ) ips[2] * 256;
        let v += ( int ) ips[3];

        return v;
    }

    /**
     * 对称加密算法 - (加密)。
     *
     * @param string s
     * @param string secure_key
     * @return string
     * @throws TypeException
     */
    static public function encrypt(string s, string secure_key) -> string {
        if empty s {
            throw new \DotPHP\ArgumentException("加密源字符串不能为空。");
        }

        var td, td_size, iv, key, ret;

        let td      = mcrypt_module_open("tripledes", "", "ecb", "");
        let td_size = mcrypt_enc_get_iv_size(td);
        let iv      = mcrypt_create_iv(td_size, MCRYPT_RAND);
        let key     = substr(secure_key, 0, td_size);
        
        mcrypt_generic_init(td, key, iv);
        
        let ret = base64_encode(mcrypt_generic(td, s));
        
        mcrypt_generic_deinit(td);
        mcrypt_module_close(td);

        return ret;
    }

    /**
     * 对称加密算法 - (解密)。
     *
     * @param string s
     * @param string secure_key
     * @return string
     * @throws <\DotPHP\ArgumentException>
     */
    static public function decrypt(string s, string secure_key) -> string {
        if empty s {
            throw new \DotPHP\ArgumentException("解密源字符串不能为空。");
        }

        var td, td_size, iv, key, ret;

        let td      = mcrypt_module_open("tripledes", "", "ecb", "");
        let td_size = mcrypt_enc_get_iv_size(td);
        let iv      = mcrypt_create_iv(td_size, MCRYPT_RAND);
        let key     = substr(secure_key, 0, td_size);
        
        mcrypt_generic_init(td, key, iv);
        
        let ret = trim(mdecrypt_generic(td, base64_decode(s)));
        
        mcrypt_generic_deinit(td);
        mcrypt_module_close(td);

        return ret;
    }
}