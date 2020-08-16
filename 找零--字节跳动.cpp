Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。现在小Y使用1024元的纸币购买了一件价值为的商品，请问最少他会收到多少硬币？

输入描述:
一行，包含一个数N。

输出描述:
一行，包含一个数，表示最少收到的硬币数。

输入例子1:
200

输出例子1:
17

例子说明1:
花200，需要找零824块，找12个64元硬币，3个16元硬币，2个4元硬币即可。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int money;
    cin >> money;
    money = 1024 - money;
    vector<int> dp(money+1, money);
    dp[0] = 0;
    for (int i = 1; i <= money; ++i)
    {
        if (i - 1 >= 0)
            dp[i] = min(dp[i], dp[i - 1]);
        if (i - 4 >= 0)
            dp[i] = min(dp[i], dp[i - 4]);
        if (i - 16 >= 0)
            dp[i] = min(dp[i], dp[i - 16]);
        if (i - 64 >= 0)
            dp[i] = min(dp[i], dp[i - 64]);
        dp[i]++;
    }
    cout << dp[money];
}

/* 比较简洁的方法 */
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        // 输入
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()){
            // 计算需要组成多少钱
            int num = 1024 - scan.nextInt();
            // dp[i] 状态定义为找i元钱，需要的最少张数，从 0 - num 总共 num + 1种
            int[] dp = new int[num + 1];
            // 初始化dp数组，因为要找最小值，这里给每个位置赋最大值，即都是由1元组成的，即num/1
            for (int i = 0; i < dp.length; i++) {
                dp[i] = i;
            }
            // 定义钱的集合，方便遍历
            int[] money = {1, 4, 16, 64};
 
            // 状态转移方程 从 1 ~ num
            for (int i = 1; i <= num ; i++) {
                // dp[num]的最小值就是能组成它的前一步 + 1 和 本身进行比较
                for (int j = 0; j < money.length; j++) {
                    if (i - money[j] >= 0){
                        dp[i] = Math.min(dp[i - money[j]] + 1, dp[i]);
                    }
                }
            }
 
            System.out.println(dp[num]);
        }
    }
}
