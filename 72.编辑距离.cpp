给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(n+1);
        for(int i = 0; i <= n; ++i)
            dp[i] = i;

        for(int i = 1; i <= m; ++i)
        {
            int oldj_1 = dp[0];
            dp[0] = i;
            for(int j = 1; j <= n; ++j)
            {
                int tmp = dp[j];
                if(word1[i-1] == word2[j-1])
                    dp[j] = oldj_1;
                else
                {
                    dp[j] = 1 + min(oldj_1, min(dp[j], dp[j-1]));
                }
                oldj_1 = tmp;
            }
            
        }
        return dp[n];
    }
};