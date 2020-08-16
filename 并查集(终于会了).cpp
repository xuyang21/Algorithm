#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<list>
#include<set>
#include<ctime>
#include <cstdlib>
#include <fcntl.h>
#include<string>
using namespace std;

//链接https://blog.csdn.net/liujian20150808/article/details/50848646

//找到根节点，并进行路径压缩
int find(int* arr, int target)
{
	int tmp = target;
	if (arr[target] == 0)
	{
		arr[target] = target;
		return target;
	}
	while (arr[target] != target)
	{
		target = arr[target];
	}
	while (arr[tmp] != target)
	{
		int pre = arr[tmp];
		arr[tmp] = target;
		tmp = pre;
	}
	return target;
}

//union，先查找根节点，如果根节点不相同，则将将一个根节点变为另一个根节点的路径
//这个动作会增加树的层级，因此find中需要循环找到根节点，此处进行路径压缩也可以。
void merge(int* arr, int a, int b)
{
	int roota = find(arr, a);
	int rootb = find(arr, b);
	if (roota != rootb)
	{
		arr[roota] = rootb;
	}
}



int main()
{
	int n;
	cin >> n;
	int in, out;
	int pre[1000];
	memset(pre, 0, 1000*4);
	for (int i = 0; i < n; ++i)
	{
		cin >> in >> out;
		merge(pre, in, out);
	}
	//以上最终得到并不是每个点都直接连接到根节点，需要对每个点再进行路径压缩，从而直接连接到根节点。
	map<int, vector<int>> mymap;
	for (int i = 0; i < 1000; ++i)
	{
		if (pre[i])
		{
			//此处是路径压缩。
			find(pre, i);
			mymap[pre[i]].push_back(i);
		}
	}
	cout << mymap.size() << endl;
	for (auto& e : mymap)
	{
		for (auto i : e.second)
		{
			cout << i << " ";
		}
		cout << endl;
	}

}

