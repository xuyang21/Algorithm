给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.


/* 统计逆序对首选归并排序,由于要统计每个位置的逆序对数目，所以设置index数组，
   每次merge交换index数组中的元素，从而知道该元素在原始数组中的位置，
   如果计算的不是每个位置逆序对的个数，就不需要index数组                     */
   
 https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/gui-bing-pai-xu-suo-yin-shu-zu-python-dai-ma-java-/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> index;
    // 把 temp 设计成方法参数传递下去也可以，这里为了与 index 统一，设计成全局变量
    vector<int> temp;

    vector<int> countSmaller(vector<int> &nums) {
        if (!nums.size()) {
            // 即使只有一行语句，都建议加上大括号和换行
            return {};
        }
        vector<int> res(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(0);
            index.push_back(i);
        }

        merge(nums, 0, nums.size() - 1, res);
        return res;
    }

    void merge(vector<int> &nums, int l, int r, vector<int> &res) {
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        merge(nums, l, mid, res);
        merge(nums, mid + 1, r, res);

        // 如果数组本身有序，没有必要往下执行，提前终止也可以节约一些时间
        if (nums[index[mid]] <= nums[index[mid + 1]]) {
            return;
        }

        // 【主要问题在这里】只需要赋值 index 数组 [l, r] 这个子区间里的值
        // 原来的写法复制了整个数组，消耗了大量时间
        for (int i = l; i <= r; ++i) {
            temp[i] = index[i];
        }

        // 类型相同的变量，一行值声明一个
        int li = l;
        int ri = mid + 1;
        int j = l;

        while (li <= mid || ri <= r) {
            if (li > mid || (ri <= r && nums[temp[li]] > nums[temp[ri]])) {
                // 特别不建议这样写，所有的类似 j++ 的写法都应该独占一行
                index[j] = temp[ri];
                j++;
                ri++;
            } else {
                index[j] = temp[li];
                j++;

                if (li <= mid) {
                    res[temp[li]] += ri - mid - 1;
                }
                li++;
            }
        }
    }
};