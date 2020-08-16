一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？


/* 将第一行和第一列单独拿出来初始化，不要想着放在一个循环里 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])
            return 0;
        else
        {
            obstacleGrid[0][0] = 1;
        }
        for(int i = 0; i <obstacleGrid.size(); i++)
            for(int j = 0; j < obstacleGrid[0].size(); j ++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    if(i== 0 && j == 0)
                        obstacleGrid[i][j] = 1;
                    else
                        obstacleGrid[i][j] = 0;
                }
                else
                {
                    if(i >= 1)
                        obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if(j >= 1)
                        obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};