给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。


/* compare定义在类内时，必须用static修饰！某些情况（数据结构地址的第一个数可以比较时），可以不传compare */
class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        return (v1[0] < v2[0]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size()-1; i++)
        {
            if(intervals[i][1]>=intervals[i+1][1])
            {
                --len;
                intervals[i+1][1] = intervals[i][1];
            }    
        }
        return len;
    }
};