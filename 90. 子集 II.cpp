给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void _subsetsWithDup(vector<int>& nums, int index)
    {
        if(index == nums.size())
            return;
        set<int> myset;
        for(int i = index; i < nums.size(); ++i)
        {
            if(myset.count(nums[i]) == 0)
            {
                path.push_back(nums[i]);
                res.push_back(path);
                _subsetsWithDup(nums, i+1);
                path.pop_back();
            }
            myset.insert(nums[i]);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.push_back({});
        sort(nums.begin(), nums.end());
        _subsetsWithDup(nums, 0);
        return res;
    }
};