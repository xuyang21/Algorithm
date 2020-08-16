给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：

输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size() < 3) return false;
        int sum = 0;
        for(int num: A)
            sum += num;
        if(sum%3 != 0)
            return false;
        sum /= 3;
        int i = 0, j = A.size()-1;
        int part1 = 0, part3 = 0;
        while(i < A.size()-2)
        {
            part1 += A[i++];
            if(part1 == sum)
                break;
        }
        while(j > i)
        {
            part3 += A[j--];
            if(part3 == sum)
                break;
        }
        return (part1==sum) && (part3==sum);
    }
};