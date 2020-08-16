给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
要求:

该字符串只包含小写的英文字母。
给定字符串的长度和 k 在[1, 10000]范围内。

/* 判断k的倍数的奇偶 */
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        for(int i = 0; i < size/k; ++i)
        {
            if(i % 2 == 0)
            {
                int l = k*i, h = l+k-1;
                while(l < h)
                    swap(s[l++], s[h--]);
            }
        }
        if((size/k)%2 == 0)
        {
            int h = size-1, l = h - size%k +1;
            while(l < h)
                swap(s[l++], s[h--]);
        }
        return s;
    }
};