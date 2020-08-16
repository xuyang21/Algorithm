一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21


/* 每次求完值取余，不会影响最终结果 */
class Solution {
public:
    int numWays(int n) {
        int p = 1, q = 1, res = 0;
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        for(int i = 1; i < n; i++)
        {
            res = (q + p)%1000000007;
            p = q;
            q = res;
        }
        return res;
    }
};