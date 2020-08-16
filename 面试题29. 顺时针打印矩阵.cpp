输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

/* 遵照打印顺序，设置行和列的边界，每打印一次，相应边界改变 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        vector<int> res;
        int rowup = 0, rowdown = matrix.size() - 1;
        int colleft = 0, colright = matrix[0].size() - 1;
        while(rowup < rowdown && colleft < colright)
        {
            for(int i = colleft; i <= colright; i++)
            {
                res.push_back(matrix[rowup][i]);
            }
            rowup++;
            for(int i = rowup; i <= rowdown; i++)
            {
                res.push_back(matrix[i][colright]);
            }
            colright--;
            for(int i = colright; i >= colleft; i--)
            {
                res.push_back(matrix[rowdown][i]);
            }
            rowdown--;
            for(int i = rowdown; i >= rowup; i--)
            {
                res.push_back(matrix[i][colleft]);
            }
            colleft++;    
        }
        if(rowup == rowdown && colleft == colright)
            res.push_back(matrix[rowup][colleft]);
        else if(rowup == rowdown)
        {
            for(int i = colleft; i <= colright; i++)
                res.push_back(matrix[rowup][i]);
        }
        else if(colleft == colright)
        {
            for(int i = rowup; i <= rowdown; i++)
                res.push_back(matrix[i][colleft]);
        }
        return res;
    }
};