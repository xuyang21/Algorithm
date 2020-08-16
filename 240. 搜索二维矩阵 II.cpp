编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
/* 初始化一个指向矩阵左下角的 (row，col)(row，col) 指针，我们执行以下操作：
    如果当前指向的值大于目标值，则可以 “向上” 移动一行。 
	否则，如果当前指向的值小于目标值，则可以移动一列。
	不难理解为什么这样做永远不会删减正确的答案；因为行是从左到右排序的，
	所以我们知道当前值右侧的每个值都较大。 因此，如果当前值已经大于目标值，
	我们知道它右边的每个值会比较大。也可以对列进行非常类似的论证，因此这种
	搜索方式将始终在矩阵中找到目标（如果存在）。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1;
        int n = 0;
        while(m >= 0 && n < matrix[0].size())
        {
            if(matrix[m][n] > target)
                --m;
            else if(matrix[m][n] < target)
                ++n;
            else
                return true;
        }
        return false;
    }
};