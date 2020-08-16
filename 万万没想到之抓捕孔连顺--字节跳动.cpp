链接：https://www.nowcoder.com/questionTerminal/c0803540c94848baac03096745b55b9b
来源：牛客网

我叫王大锤，是一名特工。我刚刚接到任务：在字节跳动大街进行埋伏，抓捕恐怖分子孔连顺。和我一起行动的还有另外两名特工，我提议

1. 我们在字节跳动大街的N个建筑中选定3个埋伏地点。
2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过D。

我特喵是个天才! 经过精密的计算，我们从X种可行的埋伏方案中选择了一种。这个方案万无一失，颤抖吧，孔连顺！
……
万万没想到，计划还是失败了，孔连顺化妆成小龙女，混在cosplay的队伍中逃出了字节跳动大街。只怪他的伪装太成功了，就是杨过本人来了也发现不了的！

请听题：给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
注意：
1. 两个特工不能埋伏在同一地点
2. 三个特工是等价的：即同样的位置组合(A, B, C) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用


链接：https://www.nowcoder.com/questionTerminal/c0803540c94848baac03096745b55b9b
来源：牛客网

#include <iostream> 
#include <vector>
using namespace std;
 
long long C(long long n){
    return (n-1) * n / 2;
}
 
int main()
{
    long long n, d, count = 0;
    cin>> n>> d;
    vector<long long> v(n);
    for (int i = 0, j = 0; i < n; i++) {
        cin>> v[i];
        while (i >= 2 && (v[i] - v[j]) > d) {
            j++;
        }
        count += C(i - j);
    }
    cout << count % 99997867; 
    return 0;
}
