/*5 5
 ..A.C
 .BAB.
 BBAB.
 .C...
 ....C

 8
 2 2 2 4
 1 3 3 3
 1 3 2 3
 2 2 2 4
 2 2 3 1
 3 1 3 4
 3 2 3 4
 1 5 5 5*/
//不考虑三条线限制的bfs.
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<set>
#include<stdio.h>
#include<queue>
using namespace std;
int n, m;
int targetx, targety;
bool bfs(vector<vector<char>> matrix, int xx1, int yy1)
{
	queue<pair<int, int>> myqueue;
	myqueue.push(make_pair(xx1, yy1));
	set<pair<int, int>> myset;
	myset.insert(myqueue.front());
	while (!myqueue.empty())
	{
		pair<int, int>  mypair = myqueue.front();
		int x1 = mypair.first, y1 = mypair.second;
		myqueue.pop();
		if (((x1 - targetx == 1) || (x1 - targetx == -1)) && y1 == targety)
			return true;
		if (((y1 - targety == 1) || (y1 - targety == -1)) && x1 == targetx)
			return true;
		if (x1 > 0 && myset.count(make_pair(x1 - 1, y1)) == 0 && matrix[x1 - 1][y1] == '.')
		{
			myqueue.push(make_pair(x1 - 1, y1));
			myset.insert(myqueue.back());
		}
		if (x1 < n - 1 && myset.count(make_pair(x1 + 1, y1)) == 0 && matrix[x1 + 1][y1] == '.')
		{
			myqueue.push(make_pair(x1 + 1, y1));
			myset.insert(myqueue.back());
		}
		if (y1 > 0 && myset.count(make_pair(x1, y1 - 1)) == 0 && matrix[x1][y1 - 1] == '.')
		{
			myqueue.push(make_pair(x1, y1 - 1));
			myset.insert(myqueue.back());
		}
		if (y1 < m - 1 && myset.count(make_pair(x1, y1+1)) == 0 && matrix[x1][y1 + 1] == '.')
		{
			myqueue.push(make_pair(x1, y1 + 1));
			myset.insert(myqueue.back());
		}
	}
	return false;
}
int main()
{
	cin >> n>> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char tmp;
			cin >> tmp;
			matrix[i][j] = tmp;
		}
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		targetx = x2 - 1;
		targety = y2 - 1;
		bool res = bfs(matrix, x1-1, y1-1);
		if (res == true)
		{
			matrix[x1-1][y1-1] = '.';
			matrix[x2-1][y2-1] = '.';
			cout << "YES" << endl;
		}
			
		else
			cout << "NO" << endl;
	}

}

//DFS+记录祖父位置和拐弯数；

#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<set>
#include<stdio.h>
#include<queue>
using namespace std;
int n, m;
int targetx, targety;
set<pair<int, int>> find_dulplicate;
bool dfs(vector<vector<char>>& matrix, int x1, int y1, pair<int, int> grandfather, int thisturn)
{
	if (x1 == targetx && y1 == targety)
		return true;
	find_dulplicate.insert(make_pair(x1, y1));
	bool result1, result2, result3, result4;
	int turn1, turn2, turn3, turn4;
	turn1 = turn2 = turn3 = turn4 = thisturn;
	result1 = result2 = result3 = result4 = false;
	if ((x1-1 == targetx && y1 == targety) ||  (x1 - 1 > 0 && find_dulplicate.count(make_pair(x1 - 1, y1)) == 0 && matrix[x1-1][y1] == '.'))
	{
		if ((y1 != grandfather.second && turn1++ < 2) || y1 == grandfather.second)
			result1 = dfs(matrix, x1 - 1, y1, make_pair(x1, y1), turn1);
	}
	if ((x1+1 == targetx && y1== targety) || (x1 < n -1 && find_dulplicate.count(make_pair(x1 + 1, y1)) == 0 && matrix[x1 + 1][y1] == '.'))
	{
		if ((y1 != grandfather.second && turn2++ < 2) || y1 == grandfather.second)
			result2 = dfs(matrix, x1 + 1, y1, make_pair(x1, y1), turn2);
	}
	if ((x1 == targetx && y1 -1== targety) || (y1 - 1 > 0 && find_dulplicate.count(make_pair(x1, y1-1)) == 0 && matrix[x1][y1-1] == '.'))
	{
		if ((x1 != grandfather.first && turn3++ < 2) || x1 == grandfather.first)
			result3 = dfs(matrix, x1, y1-1, make_pair(x1, y1), turn3);
	}
	if ((x1== targetx && y1+1 == targety) || (y1 < n-1 && find_dulplicate.count(make_pair(x1, y1 + 1)) == 0 && matrix[x1][y1 + 1] == '.'))
	{
		if ((x1 != grandfather.first && turn4++ < 2) || x1 == grandfather.first)
			result4 = dfs(matrix, x1, y1 + 1, make_pair(x1, y1), turn4);
	}
	find_dulplicate.erase(make_pair(x1, y1));
	return result1 || result2 || result3 || result4;
}

int main()
{
	cin >> n>> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char tmp;
			cin >> tmp;
			matrix[i][j] = tmp;
		}
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		targetx = x2 - 1;
		targety = y2 - 1;
		if (matrix[x1 - 1][y1 - 1] == matrix[targetx][targety])
		{
			bool res = dfs(matrix, x1 - 1, y1 - 1, make_pair(x1 - 1, y1 - 1), 0);
			if (res == true)
			{
				matrix[x1 - 1][y1 - 1] = '.';
				matrix[x2 - 1][y2 - 1] = '.';
				cout << "YES" << endl;
			}
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
		
	}
}

// 改进版
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<set>
#include<stdio.h>
#include<queue>
using namespace std;
int n, m;
int targetx, targety;
set<pair<int, int>> find_dulplicate;
map<int, vector<int>> direction({ {0,{-1, 0}}, {1, {1, 0}}, {2, {0, -1}}, {3, {0, 1}} });
bool dfs(vector<vector<char>>& matrix, int x1, int y1, pair<int, int> grandfather, int thisturn)
{
	if (x1 == targetx && y1 == targety)
		return true;
	find_dulplicate.insert(make_pair(x1, y1));
	bool result = false;
	for (int i = 0; i < 4; ++i)
	{
		int nextx = x1 + direction[i][0];
		int nexty = y1 + direction[i][1];
		if (find_dulplicate.count(make_pair(nextx, nexty)) == 0 && nextx >= 0 && nextx < n && nexty >= 0 && nexty < m)
		{
			if (matrix[nextx][nexty] == '.' || (nextx == targetx && nexty == targety))
			{
				if ((nextx == x1 && x1 == grandfather.first) || (nexty == y1 && y1 == grandfather.second))
					result = dfs(matrix, nextx, nexty, make_pair(x1, y1), thisturn);
				else if (thisturn < 2)
					result = dfs(matrix, nextx, nexty, make_pair(x1, y1), thisturn + 1);
				if (result)
					return true;
			}
		}
	}
	find_dulplicate.erase(make_pair(x1, y1));
	return false;
}

int main()
{
	cin >> n>> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char tmp;
			cin >> tmp;
			matrix[i][j] = tmp;
		}
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		targetx = x2 - 1;
		targety = y2 - 1;
		if (matrix[x1 - 1][y1 - 1] == matrix[targetx][targety])
		{
			bool res = dfs(matrix, x1 - 1, y1 - 1, make_pair(x1 - 1, y1 - 1), 0);
			if (res == true)
			{
				matrix[x1 - 1][y1 - 1] = '.';
				matrix[x2 - 1][y2 - 1] = '.';
				cout << "YES" << endl;
			}
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
		
	}
}


// 改进版，每次传入方向gf_dir,而不是之前的祖父节点的坐标， 添加路径时，矩阵原地乘以-1， 不使用set判断当前点是否已在路径上
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<set>
#include<stdio.h>
#include<queue>
using namespace std;
int n, m;
int targetx, targety;
set<pair<int, int>> find_dulplicate;
vector<pair<int, int>> direction({make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)});
bool dfs(vector<vector<char>>& matrix, int x1, int y1, int gf_dir, int thisturn)
{
	if (x1 == targetx && y1 == targety)
		return true;

	matrix[x1][y1] *= -1;
	bool result = false;
	for (int i = 0; i < 4; ++i)
	{
		int nextx = x1 + direction[i].first;
		int nexty = y1 + direction[i].second;
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m)
		{
			if (matrix[nextx][nexty] == '.' || (nextx == targetx && nexty == targety))
			{
				if (i == gf_dir)
					result = dfs(matrix, nextx, nexty, i, thisturn);
				else if (thisturn < 3)
					result = dfs(matrix, nextx, nexty, i, thisturn + 1);
				if (result)
					return true;
			}
		}
	}
	matrix[x1][y1] *= -1;
	return false;
}

int main()
{
	cin >> n >> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char tmp;
			cin >> tmp;
			matrix[i][j] = tmp;
		}
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		targetx = x2 - 1;
		targety = y2 - 1;
		if (matrix[x1 - 1][y1 - 1] == matrix[targetx][targety])
		{
			bool res = dfs(matrix, x1 - 1, y1 - 1, -1, 0);
			if (res == true)
			{
				matrix[x1 - 1][y1 - 1] = '.';
				matrix[x2 - 1][y2 - 1] = '.';
				cout << "YES" << endl;
			}
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;

	}
}


//大佬写法
#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<set>
#include<stdio.h>
#include<queue>
using namespace std;
bool dfs(vector<vector<char>>& matrix, vector<pair<char,char>>& d, pair<char,char> src, pair<char,char> des, int direction, int cnt)
{
    if(cnt == 4) return false;
    bool flag = false;
    matrix[src.first][src.second] *= -1;
    for(int i = 0; i < 4 && !flag; ++i) {
        int m = src.first+d[i].first;
        int n = src.second+d[i].second;
        if(m>=0&&n>=0&&m<matrix.size()&&n<matrix[0].size()) 
            if(m == des.first && n == des.second) flag = true;
            else if(matrix[m][n] == '.') flag |= dfs(matrix,d,{m,n},des,i,direction!=i?cnt+1:cnt);  
    }
    matrix[src.first][src.second] *= -1;
    return flag;
}
int main()
{
    int n, m;
    vector<pair<char,char>> d{{1,0},{-1,0},{0,1},{0,-1}};
    cin >> n>> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            char tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(matrix[x1-1][y1-1]!='.' && matrix[x2-1][y2-1]!='.') {
            //-1就开始用一下，代表通配
            if (dfs(matrix, d, {x1-1,y1-1}, {x2-1,y2-1}, -1, 0)) {
                matrix[x1-1][y1-1] = '.';
                matrix[x2-1][y2-1] = '.';
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
}