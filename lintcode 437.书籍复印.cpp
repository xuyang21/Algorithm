给定 n 本书, 第 i 本书的页数为 pages[i]. 现在有 k 个人来复印这些书籍, 而每个人只能复印编号连续的一段的书, 比如一个人可以复印 pages[0], pages[1], pages[2], 但是不可以只复印 pages[0], pages[2], pages[3] 而不复印 pages[1].

所有人复印的速度是一样的, 复印一页需要花费一分钟, 并且所有人同时开始复印. 怎样分配这 k 个人的任务, 使得这 n 本书能够被尽快复印完?

返回完成复印任务最少需要的分钟数.

//dp解法
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if(pages.size() == 0)
            return 0;
        if(k > pages.size())
            k = pages.size();
        vector<int> prefix_sum(pages.size());
        vector<vector<int>> dp(k, vector<int>(pages.size()));
        prefix_sum[0] = pages[0];
        dp[0][0] = pages[0];
        for(int i = 1; i < pages.size(); ++i)
        {
            prefix_sum[i] = prefix_sum[i-1] + pages[i];
            dp[0][i] = prefix_sum[i];
        }
        
        for(int i = 1; i < k; ++i)
        {
            for(int j = i; j < pages.size(); ++j)
            {
                dp[i][j] = INT_MAX;
                for(int m = i-1; m < j; ++m)
                {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][m], prefix_sum[j] - prefix_sum[m]));
                }
            }
        }
        return dp[k-1][pages.size()-1];
    }
};

//二分法（和我常用的二分类似）+贪心算法
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if(pages.size() == 0)
            return 0;
        int max = 0;
        for(int i = 0; i < pages.size(); ++i)
            max += pages[i];
        int lo = 0;
        int hi = max + 1;
        while(lo < hi)
        {
            int mid = (lo + hi)>>1;
            if(canCopyBooks(pages, k, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
    bool canCopyBooks(vector<int> &pages, int k, int T)
    {
        int num = 0;
        for(int i = 0; i < pages.size(); ++i)
        {
            if(pages[i] > T)
                return false;
            if(pages[i] > num)
            {
                num = T;
                --k;
            }
            num -= pages[i];
        }
        return k >= 0;
    }
};