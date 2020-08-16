给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。翻转后，单元格的值从 0 变成 1，或者从 1 变为 0 。

返回经过一些翻转后，行上所有值都相等的最大行数。

示例 1：

输入：[[0,1],[1,1]]
输出：1
解释：不进行翻转，有 1 行所有值都相等。
示例 2：

输入：[[0,1],[1,0]]
输出：2
解释：翻转第一列的值之后，这两行都由相等的值组成。

/* 如果两行能够通过列翻转而相等，则两行相等或互补 */
/* 将每行转换成首字符为 1 的字符串，然后通过map计数 */
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string , int> mymap;
        int res = 0;
        for(vector<int> arr : matrix)
        {
            int d = arr[0]^1;
            string s;  //每次自动情况?不用手动，真神奇
            for(int i = 0; i < arr.size(); ++i)
            {
                arr[i] ^= d;
                s += arr[i];
            }
            mymap[s]++;
            res = max(res, mymap[s]);
        }
        return res;
    }
};