/* 初始一个兔子，长到第五个月后每个月又生一对兔子， 生长周期四个月！！！ */

#include <iostream>       // std::cin, std::cout
using namespace std;

int main()
{
    int arr[4] = { 1, 0, 0, 0};
    int month;
    cin >> month;
    for (int i = 2; i <= month; i++)
    {
        int tmp = arr[3];
        arr[3] += arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = tmp;
    }
    int res = 0;
    for (int i = 0; i < 4; i++)
        res += arr[i];
    cout << res;
    return 0;
}
