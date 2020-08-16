对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

 

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""

/* 两个字符串正反相加，如果相等则说明有最大公因子 
   辗转相除法*/
class Solution {
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1)
            return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};



/* 求出两个字符串长度的公约数，再判断该长度的字符串是否能被整除 */
class Solution {
public:
    bool isdivisor(string s1, string s2, int divisor)
    {
        for(int i = 0; i < divisor; ++i)
        {
            if(s1[i] != s2[i])
                return false;
        }
        for(int i = 0; i < divisor; ++i)
        {
            for(int j = 1; j < s1.size()/divisor; ++j)
            {
                if(s1[i] != s1[i+j*divisor])
                    return false;
            }
        }
        for(int i = 0; i < divisor; ++i)
        {
            for(int j = 1; j < s2.size()/divisor; ++j)
            {
                if(s2[i] != s2[i+j*divisor])
                    return false;
            }
        }
        
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int size1 = str1.size(), size2 = str2.size();
        for(int i = min(size1, size2); i >= 1; --i)
        {
            cout << i;
            if(size1%i == 0 && size2%i == 0 && isdivisor(str1,str2, i))
            return str1.substr(0, i);
        }
        return "";
    }
};