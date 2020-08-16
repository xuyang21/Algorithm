堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。

输入使用数组[wi, di, hi]表示每个箱子。

示例1:

 输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
 输出：6
示例2:

 输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
 输出：10
提示:

箱子的数目不大于3000个。

// 动态规划：先将数组按某一维度进行排序，以第i个箱子为底时能堆的最大高度为i前 三维小于i的箱子为底的最大高度 加上i的高度。
class Solution {
    public int pileBox(int[][] box) {
        Arrays.sort(box, (int[] a,int[] b)->{return a[0]-b[0];});
        int[] dp = new int[box.length];
        int res = 0;
        for(int i = 0; i < box.length; ++i)
        {
            int curmax = 0;
            for(int j = 0; j < i; ++j)
            {
                if(box[j][0]<box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2])
                {
                    curmax = Math.max(curmax, dp[j]);
                }
            }
            dp[i] = curmax + box[i][2];
            res = Math.max(dp[i], res);
        }
        return  res;
    }
}