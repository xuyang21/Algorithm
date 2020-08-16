给定 x, k ，求满足 x + y = x | y 的第 k 小的正整数 y 。 | 是二进制的或(or)运算，例如 3 | 5 = 7。

比如当 x=5，k=1时返回 2，因为5+1=6 不等于 5|1=5，而 5+2=7 等于 5 | 2 = 7。

#include<iostream>

using namespace std;
int main()
{
    long long x, k;
    cin >> x >> k;
    int bit = 0;
    long long res = 0;
    while (k || x)
    {
        if ((x & 1) == 0)
        {
            res |= (k & 1) << bit;
            k = k >> 1;
        }
        bit++;
        x = x >> 1;
    }
    cout << res;
}