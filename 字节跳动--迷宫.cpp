/*4 3
1 0 -1 1
-2 0 -1 -3
2 2 0 0*/
// BFS, 遍历起点周围点，如果点值为1或2，则将所有的1或2加入队列中，并记得将其标记成已遍历（置为1）
// 记录路径长度通过  每次层序遍历前记录该层的长度，然后遍历该长度个节点 实现。
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<set>
#include<stdio.h>
#include<queue>
using namespace std;

int bfs(vector<vector<int>>& matrix, pair<int, int> start);
vector<pair<int, int>> direction({ {0, 1}, {0, -1}, {-1, 0}, {1, 0} });
int row, col;
vector<pair<int, int>> ones, twos;
int main()
{

	cin >> col >> row;
	int startx = 0, starty = 0;
	vector<vector<int>> matrix(row, vector<int>(col));
	for(int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 1)
				ones.push_back(make_pair(i, j));
			else if (matrix[i][j] == 2)
				twos.push_back(make_pair(i, j));
			else if (matrix[i][j] == -2)
			{
				startx = i;
				starty = j;
			}
		}
	cout << bfs(matrix, make_pair(startx, starty));
}

int bfs(vector<vector<int>>& matrix, pair<int, int> start)
{
	int res = 0;
	queue<pair<int, int>> pair_queue;
	pair_queue.push(start);
	while (!pair_queue.empty())
	{
		int size = pair_queue.size();
		++res;
		while (size--)
		{
			pair<int, int> head_ele = pair_queue.front();
			pair_queue.pop();
			for (int i = 0; i < 4; ++i)
			{
				int x = head_ele.first + direction[i].first;
				int y = head_ele.second + direction[i].second;
				if (x > 0 && x < row && y > 0 && y < col)
				{
					if (matrix[x][y] == 0)
					{
						matrix[x][y] = -1;
						pair_queue.push(make_pair(x, y));
					}
					else if (matrix[x][y] == 1)
					{
						for (auto tmp : ones)
						{
							matrix[tmp.first][tmp.second] = -1;
							pair_queue.push(tmp);
						}
					}
					else if (matrix[x][y] == 2)
					{
						for (auto tmp : twos)
						{
							matrix[tmp.first][tmp.second] = -1;
							pair_queue.push(tmp);
						}
					}
					else if (matrix[x][y] == -3)
						return res;
				}
			}
		}
	}
	return -1;

}