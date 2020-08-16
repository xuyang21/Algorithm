
为了不断优化推荐效果，今日头条每天要存储和处理海量数据。假设有这样一
种场景：我们对用户按照它们的注册时间先后来标号，对于一类文章，每个用户
都有不同的喜好值，我们会想知道某一段时间内注册的用户（标号相连的一批用户
）中，有多少用户对这类文章喜好值为k。因为一些特殊的原因，不会出现一个查
询的用户区间完全覆盖另一个查询的用户区间(不存在L1<=L2<=R2<=R1)。


/* 建立map<int, vector<int>>, int 值当前喜好值， vector<int> 存放喜好值为k的用户的位置 */

/* 二分法，将输入输入数据先按照喜好值排序，每个喜好值再按照用户的id号码排序， 要用到数据类型pair<int, int>
   详情见链接https://blog.csdn.net/flushhip/article/details/79416715 */
   
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int binserach(vector<int>& nums, int target)
{
	int l = 0, h = nums.size();
	while (l < h)
	{
		int mid = (l + h) >> 1;
		if (nums[mid] > target)
			h = mid;
		else
			l = mid + 1;
	}
	return --l;
}
int main()
{
	int users;
	cin >> users;
	// vector<int> 中的数据已经有序
	map<int, vector<int>> mymap;
	int value;
	for (int i = 1; i <= users; ++i)
	{
		cin >> value;
		mymap[value].push_back(i);
	}
	int groups;
	cin >> groups;
	while (groups--)
	{
		int left, right, k;
		cin >> left >> right >> k;
		int h = binserach(mymap[k], right);
		int l = binserach(mymap[k], left);
		if (l != -1 && mymap[k][l] == left)
			--l;
		int res = h - l;
		cout << res << endl;
	}
}