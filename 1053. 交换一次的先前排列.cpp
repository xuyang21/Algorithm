给你一个正整数的数组 A（其中的元素不一定完全不同），请你返回可在 一次交换（交换两数字 A[i] 和 A[j] 的位置）后得到的、按字典序排列小于 A 的最大可能排列。

如果无法这么操作，就请返回原数组。

示例 1：

输入：[3,2,1]
输出：[3,1,2]
解释：
交换 2 和 1
 
示例 2：

输入：[1,1,5]
输出：[1,1,5]
解释： 
这已经是最小排列

/* 二分查找还是用熟悉的版本 */
class Solution {
public:
    int binsearch(vector<int>& A, int lo, int hi, int target)
    {
        while(lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if(A[mid] > target)
                hi = mid;
            else 
                lo = mid + 1;
        }
        return --lo;
    }
    
    vector<int> prevPermOpt1(vector<int>& A) {
        for(int i = A.size() - 1; i > 0; i--)
        {
            if(A[i] < A[i - 1])
            {
                int tmp = binsearch(A, i, A.size(), A[i-1]);
                while(A[tmp] == A[i-1] || A[tmp] == A[tmp-1])
                    tmp--;
                swap(A[i-1], A[tmp]);
                break;
            }
        }
        return A;
    }
};