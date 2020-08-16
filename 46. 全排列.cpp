给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
public:
    vector<vector<int>> res;
    void _permute(vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); ++i)
        {
            swap(nums[i], nums[index]);
            _permute(nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        _permute(nums, 0);
        return res;
    }
};