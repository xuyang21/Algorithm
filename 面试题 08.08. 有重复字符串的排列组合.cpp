有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

示例1:

 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。

class Solution {
public:
    vector<string> res;
    void _permutation(string s, int index)
    {
        if(index == s.size())
        {
            res.push_back(s);
            return;
        }
        set<char> myset;
        for(int i = index; i < s.size(); ++i)
        {
            if(myset.count(s[i])==0){
            swap(s[i], s[index]);
            _permutation(s, index+1);
            swap(s[i], s[index]);}
            myset.insert(s[i]);
        }
    }
    vector<string> permutation(string S) {
        _permutation(S, 0);
        return res;
    }
};
