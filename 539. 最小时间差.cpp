给定一个 24 小时制（小时:分钟）的时间列表，找出列表中任意两个时间的最小时间差并已分钟数表示。


示例 1：

输入: ["23:59","00:00"]
输出: 1

备注:

列表中时间数在 2~20000 之间。
每个时间取值在 00:00~23:59 之间。

/* 装时间转成分钟，进行排序，再添加MIN+24*60作为末尾元素，然后比较相邻两个元素的差值即可 */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        istringstream instream;
        vector<int> minites;
        for(string tmp : timePoints)
        {
            instream.str(tmp);
            int h,m;
            char dot;
            instream >> h >> dot >> m;
            minites.push_back(h*60+m);
            instream.clear(); 
        }
        sort(minites.begin(), minites.end());
        minites.push_back(minites[0] + 24*60);
        int res = 23*60 + 59;
        for(int i = 1; i < minites.size(); ++i)
            res = min(res, minites[i]-minites[i-1]);
        return res;
    }
};