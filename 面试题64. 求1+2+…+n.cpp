求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45

//利用&&的特性，即使不是判断语句也可以使用。
class Solution {
public:
    int sumNums(int n) {
        int res = n;
        n && (res += sumNums(n-1));
        return res;
    }
};