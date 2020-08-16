实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
/* 1. 从后向前找到第一个nums[i] > nums[i-1]的位置，如果存在则说明排列有下一个排列，否则就将数字重新拍成最小的排列 */
/* 2. 将i到nums.size()这段的元素进行非降序排列 */
/* 3. 从i到nums.size()这段元素中找到大于nums[i-1]的最小数，并与其交换 */
class Solution {
public:
    int binsearch(vector<int>& nums, int left, int right, int target)
    {
        while(left < right)
        {
            int mid = (left+right)>>1;
            if(nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        for(int i = size - 1; i >= 1; i--)
        {
            if(nums[i] > nums[i-1])
            {
                sort(nums.begin()+ i, nums.end());
                int index = binsearch(nums, i, size, nums[i-1]);
                swap(nums[index], nums[i-1]);
                return;
            }    
        }
        int head = 0, tail = size - 1;
        while(tail > head)
            swap(nums[tail--], nums[head++]);
        
    }
};