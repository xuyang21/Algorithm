给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k*k 个积分。
当你将所有盒子都去掉之后，求你能获得的最大积分和。

示例 1：
输入:

[1, 3, 2, 2, 2, 3, 4, 3, 1]
输出:

23
解释:

[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 分) 
----> [1, 3, 3, 3, 1] (1*1=1 分) 
----> [1, 1] (3*3=9 分) 
----> [] (2*2=4 分)

class Solution {
public:
    /**
     * 求移出盒子的最高得分
     * @param boxes int整型vector 初始盒子的整型数表示
     * @return int整型
     */
    //错误的解法！！！ 反例：[3,8, 8,3,8,8,8, 3]
    //此解法在最后一组dp时，出现错误。把中间那个3去掉后，388与888能连在一起，使问题变得更加复杂。
    int binsearch(vector<int>& arr, int target)
    {
        int lo = 0;
        int hi = arr.size();
        while(lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if(arr[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return --lo;
    }
    int removeBoxes(vector<int>& boxes) {
        // write code here
        map<int, vector<int>> scd;
        int size = boxes.size();
        for(int i = 0; i < size; ++i)
            scd[boxes[i]].push_back(i);
        vector<vector<int>> dp(size, vector<int>(size, 1));
        for(int j = 0; j < size; ++j)
        {
            for(int i = 0; i < j; ++i)
            {
                dp[i][j] = max(dp[i][j],1 + dp[i][j-1]);
                int sum = 0;
                int upindex = binsearch(scd[boxes[j]], j);
                int lowindex = boxes[i] == boxes[j]?binsearch(scd[boxes[j]], i): binsearch(scd[boxes[j]], i)+1;
                int hi = j-1;
                for(int n = 2; n <= upindex-lowindex+1; n++)
                {
                    int lo = scd[boxes[j]][upindex-n+1] +1;
                    if (lo <= hi)
                        sum += dp[lo][hi];
                    if(lo >= i+2)
                        dp[i][j] = max(dp[i][j], n * n + sum+dp[i][lo-2]);
                    else
                        dp[i][j] = max(dp[i][j], n * n + sum);
                    hi = lo-2;
                }
            }
        }
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                cout << dp[i][j]<<" ";
            }
            cout << endl;
        }
        return dp[0][boxes.size()-1];
        
    }
};