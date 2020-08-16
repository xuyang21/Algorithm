给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。

 

示例 1:

输入: [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
示例 2:

输入: [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。

/* 使用一个变量 countcount ，用来保存遍历数组过程中到目前为止遇到的 0 和 1 的相对数量。 
   遇到 \text{1}1 的时候， countcount 变量加 1 ，遇到 0 的时候 countcount 变量减 1 。

   我们从头开始遍历数组，在任何时候，如果 countcount 变成了 0 ，这表示我们从开头到当前
   位置遇到的 0 和 1 的数目一样多。另一个需要注意的是，如果我们在遍历数组的过程汇中遇
   到了相同的 countcount 2 次，这意味着这两个位置之间 0 和 1 的数目一样多。*/

// 将0替换成-1求前缀和！前缀和相等说明这两个位置之间的区间0和1数量相等，是一个候选值   
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       map<int, int> int_map;
       int_map[0] = -1;
       int sum = 0;
       int res = 0;
       for(int i = 0; i < nums.size(); ++i)
       {
           sum += nums[i] == 0? -1 : 1;
           if(int_map.count(sum))
               res = max(res, i - int_map[sum]);
            else
               int_map[sum] = i;
       }
       return res;
    }
};