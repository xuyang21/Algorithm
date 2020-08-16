给定一组字符，使用原地算法将其压缩。
压缩后的长度必须始终小于或等于原数组长度。
数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
在完成原地修改输入数组后，返回数组的新长度。
进阶：
你能否仅使用O(1) 空间解决问题？
 
示例 1：
输入：
["a","a","b","b","c","c","c"]
输出：
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]

说明：
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。


/* 利用双指针，实现一次遍历，to_string */
class Solution {
public:
    int compress(vector<char>& chars) {
        int anchor = 0;
        for(int m = 0, count = 1; m < chars.size(); ++m, ++count){
            if(m == chars.size()-1 || chars[m] != chars[m+1]){
                chars[anchor++] = chars[m];
                if(count > 1){
                    for(char ch : to_string(count))
                        chars[anchor++] = ch;
                }
                count = 0;
            }
        }
        chars.resize(anchor);
        return anchor;
    }
};