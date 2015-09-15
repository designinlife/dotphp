namespace DotPHP\Utils;

/**
 * DotPHP 概率相关工具类。
 * 
 * -------------------------------------------------
 * @author Lei Lee <web.developer.network@gmail.com>
 * @version 0.1a
 * @copyright (c) 2015-2016, Lei Lee
 * -------------------------------------------------
 */
class Probability {
    /**
     * 概率计算函数。检测传入的概率值是否命中？
     *
     * @param float $rate 指定概率值。(此值必须是 0~1 之间的浮点数。包含0,1两个整数.)
     * @return boolean 返回 True 时，表示已命中。
     * @throws ArgumentException
     */
    static public function hit(float rate) -> boolean {
        if rate > 1 || rate < 0 {
            throw new \DotPHP\ArgumentException("传入的概率值 $rate 必须是 0~1 之间的浮点数或整数(0|1)。");
        }
        
        int r, v;

        let r = 100 * rate;
        let v = mt_rand(1, 100);

        if v <= r {
            return true;
        }

        return false;
    }

    /**
     * 抽奖计算。
     *
     * @param array ratios
     *            指定概率列表。
     * @return int string
     *            返回中奖的元素 key 值。
     */
    static public function lottery(array ratios) -> int | string | boolean {
        var result, key, proCur, proSum, randNum;

        let result = false;

        // 概率数组的总概率精度
        let proSum = array_sum(ratios);

        // 概率数组循环
        for key, proCur in ratios {
            let randNum = mt_rand(1, proSum);
            if (randNum <= proCur) {
                let result = key;
                break;
            } else {
                let proSum -= proCur;
            }
        }

        return result;
    }
}