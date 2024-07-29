#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//数组最后一个元素的最小值
class Solution {
public:
    long long minEnd(int n, int x) {

        //暴力算法，依次加一
        /*long long end = x;
        for (int i = 0; i <= n; ++i) {
            if (i == n-1)
                return end;
            while (1) {
                ++end;
                if ((end & x) == x)
                    break;
            }
        }
        return x;
        */

        /*
        // 位运算 ：时间复杂度为 logx + logn
        long long end = x;
        n -= 1; // x是第一个数，所以n-1个满足它的子集是x的数就是答案
        int i = 0;
        int j = 0;
        int bit = 0;
        while (n >> j) {
            // 寻找x中可以添加的空位
            if ((x >> i & 1) == 0) {
                // n从右往左的第i位置
                bit = n >> j & 1;
                x |= bit << i;
                ++j;
            }
            ++i; // 有没有空位都到下一个比特位继续寻找空位
        }
        return x;
        */

        // 优化
       // 优化：因为遍历到的x的位可能不是0，造成无用功，下面给出的优化：直接对x二进制上为0的添加j上的位
       //  时间复杂度：longn
        n -= 1;
        int bit;
        int j = 0;
        long long t = ~x; // x = 100 100,t = 011 011
        long long lowbit;
        long long ans = x;//用long long 返回避免返回是负数
        while (n >> j) {
            lowbit = t & -t; /* 获取的最低位的1: 011 011 & 100 101 ->000 001
                                                011 010 & 100 110 ->000 010
                                                 、、、、、、       ->001 000
                                                 、、、、、、       ->010 000
                                                 */
            bit = n >> j & 1;
            ans |= (long long)bit * lowbit; // 相当于上面的if else
            // 当bit为0添加为0，bit为1时添加为1；
            ++j; // n的下一位
            t ^= lowbit;
        }
        return ans;
    }
};

int main()
{
    Solution test;
    int n, x;
    cin >> n >> x;
    cout << test.minEnd(n, x) << endl;
    return 0;
}