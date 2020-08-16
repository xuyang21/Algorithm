统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/
class Solution {
    public int countPrimes(int n) {
        if(n <= 2)
            return 0;
        int cnt = 0;
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
		
		// 由于n = 根号n的平方， 所以i<n时， i=axb，其中a,b其中一个必小于根号n，所以第二层循环必能找出非质数i
        for(int i = 2; i*i < n; ++i)
        {
            if(isPrime[i])
            {
                for(int j = i*i; j < n; j+=i)
                    isPrime[j] = false;
            }
        }
        for(int i = 2; i < n; ++i)
        {
            if(isPrime[i])
                cnt++;
        }
        return cnt;
    }
}

如何判断一个数是否为质数呢，如下：
    public boolean isPrime(int n) {
    if (n <= 3) {
        return n > 1;
    }
    //一个非2偶数必然不是质数
    if(n % 2 == 0) return false;
	//只需判断一个数能否被小于sqrt(n)的奇数整除
    int sqrt = (int)Math.sqrt(n);
    for (int i = 3; i <= sqrt; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
    }
}
