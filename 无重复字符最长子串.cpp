给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

输入描述:
输入字符串(长度<=100000)

输出描述:
不含有重复字符的最长子串长度

输入例子1:
abcabcbb

输出例子1:
3

例子说明1:
因为无重复字符的最长子串是"abc"，所以其长度为 3。


// 双指针
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    map<char, int> mymap;
    int res = 0;
    int i = 0, j = 0;
    while (j < len)
    {
        if (mymap.count(s[j]) == 0)
            mymap[s[j]] = j;
        else
        {
            res = max(res, j - i);
            int pos = mymap[s[j]];
            for (int k = i; k < pos; ++k)
                mymap.erase(s[k]);
            mymap[s[j]] = j;
            i = pos+1;
        }
        j++;
    }
    res = max(res, j - i);
    cout << res;
}