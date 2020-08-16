给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

class Solution {
public:
    vector<vector<int>> res;
    void _permuteUnique(vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        set<int> myset;
        for(int i = index; i < nums.size(); i++)
        {
            if(myset.count(nums[i]) == 0)
            {
                swap(nums[index], nums[i]);
                _permuteUnique(nums, index+1);
                swap(nums[index], nums[i]);
            }
            myset.insert(nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        _permuteUnique(nums, 0);
        return res;
    }
};