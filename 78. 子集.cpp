给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
// 回溯法
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void _subsets(vector<int> nums, int index)
    {
        if(index == nums.size())
             return;
        for(int i = index; i <nums.size(); ++i)
        {
            path.push_back(nums[i]);
            res.push_back(path);
            _subsets(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        _subsets(nums, 0);
        return res;
    }
};
// 生成法  初始集合 s 为空，依次从数组里取一个元素 e，用 e 和 s 生成新的集合，新的集合为 s + s*e.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(int i = 0; i < nums.size(); ++i)
        {
            int size = res.size();
            for(int j = 0; j < size; ++j)
            {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
