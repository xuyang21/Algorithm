两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

/* 距离总和等于所有数字同一位1的数目与0的数目积的和 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        for(int bit = 0; bit < 30; ++bit)
        {
            int ones = 0, tmp = 0;
            for(int i = 0; i < size; ++i)
            {
                ones += nums[i]&1;
                nums[i] >>= 1;
                tmp += nums[i] == 0? 1: 0;
            }
            res += ones*(size-ones);
            if(tmp == size)
                break;
        }
        return res;
    }
};