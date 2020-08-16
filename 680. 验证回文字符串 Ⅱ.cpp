给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。

/* 假设我们想知道 s[i],s[i+1],...,s[j] 是否形成回文。如果 i >= j，就结束判断。
   如果 s[i]=s[j]，那么我们可以取 i++;j--。否则，回文必须是 s[i+1], s[i+2], ..., s[j]
   或 s[i], s[i+1], ..., s[j-1] 这两种情况。*/
class Solution {
public:
    bool isPalindrome(string s, int left, int right)
    {
        while(left < right)
        {
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            if(s[left] == s[right])
            {
                ++left;
                --right;
            }
            else
                return isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right);
        }
        return true;
    }
};