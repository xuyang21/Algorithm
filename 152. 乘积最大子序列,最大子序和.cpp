给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

class Solution {
    public int maxProduct(int[] nums) {
        int max, min, res;
        max = min = 1;
        res = Integer.MIN_VALUE;
        for(int i:nums)
        {
            int tmp = max;
            max = Math.max(Math.max(max*i, i), min * i);
            min = Math.min(Math.min(tmp*i, i), min * i);
            res = Math.max(max, res);
        }
        return res;
    }
}