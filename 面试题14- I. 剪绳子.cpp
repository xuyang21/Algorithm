给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
提示：

2 <= n <= 58

// 使用递归   超时
class Solution {
    int res = 0;
    int path = 1;
public:
    void _cuttingRope(int n, int m)
    {
        if(n == 0)
        {
            if(m !=1)
                res = max(res, path);
            return;
        }
        for(int i = 1; i <= n; ++i)
        {
            path *= i;
            _cuttingRope(n-i, m+1);
            path /= i;
        }
    }
    int cuttingRope(int n) {
        _cuttingRope(n, 0);
        return res;
    }
};