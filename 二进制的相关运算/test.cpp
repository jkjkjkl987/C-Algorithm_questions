#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <bitset>
#include <intrin.h>

using namespace std;

class Solution
{
public:
    void NumbersInSet(int num)/*统计集合中的每个元素（从大到小枚举集合的所有非空子集）
                                10101 -> 10100 -> 10001 -> 10000 -> 00101 -> 00100 -> 00001
    相当于缩减版的二进制减法    1 1 1    1 1 0    1 0 1    1 0 0    0 1 1    0 1 0    0 0 1
    */
    {
        int lowbit = num & (num - 1);
        while (lowbit)
        {
            cout << lowbit << " ";
            lowbit = num & (lowbit - 1);
        }
    }

    void NumbersInSetExtension(int num)/*扩展最大元素，包含着此时的子集的更大集合
                                       10101 -> 10111 -> 11101 -> 11111 ->110101 -> 110111 -> 111101 -> 111111    
                                       ( 21 )   ( 23 )   ( 29 )   ( 31 )  ( 53 )    ( 55 )    ( 61 )    ( 63 )
    相当于缩减版的二进制加法           _0_0_    _0_1_    _1_0_    _1_1_   1_0_0_    1_0_1_    1_1_0_    1_1_1_                                
    */
                                       
    {
        int n = 6;
        int j = 0;
        int lowbit;
        long long ans = num;
        int x = num;
        x = ~x;//此时的二进制的1就是之前的0，可以填入的位置
        int count = 0;
        while (++count <= n)//从 0 1 开始填入 直到为n
        {
            while (count >> j)
            {
                lowbit = x & (-x);//num集合中最小元素
                ans |= (long long)lowbit * ((count >> j) & 1);
                ++j;
                x ^= lowbit;//差
            }
            cout << ans << " ";
            j = 0;
            x = ~num;
            ans = num;//重新选择新的num填入count的二进制位
        }
    }
        
};

int main()
{
    int n;
    cin >> n;
    Solution test;
    test.NumbersInSet(n);
    cout << endl;
    test.NumbersInSetExtension(n);

#if 0
    unsigned long num;//13
    unsigned long index;//用于储存最高位索引的变量

    cin >> num;
    int nm1 = bitset<64>(num).count();//求二进制中有多少1
    int nm2 = bitset<32>(num).size();//求二进制的位数
    unsigned char result = _BitScanReverse64(&index, num);//求二进制的有效位数 ,如果找不到有效位，它会将 result 参数设置为 0
    //因为二进制从右往左是从0开始的，所以索引为0意味着第一位
    int nm3 = index + 1;
    /*
    unsigned char _BitScanReverse64(
        unsigned long* Index,
        unsigned __int64 Mask
    );
    */

    //这些函数是GCC 的内置函数
    //int nm4 = __builtin_popcount(num);
    //int nm5 = 32 - __builtin_clz(num);
    //int nm6 = __builtin_ctz(num);

    int nm4 = _mm_popcnt_u32(num);
    int nm4_ = _mm_popcnt_u64(num);
    unsigned long index1;
    unsigned long index2;
    int nm5 = _BitScanReverse(&index1, num);//index1为 最高位1的索引位置，
    int nm6 = _BitScanForward(&index2, num);//index2为 最低位1的索引位置

    cout << num << "有多少位1: " << nm1 << endl;
    cout << num << "有多少位: " << nm2 << endl;
    cout << num << "有多少有效位: " << nm3 << endl;

    cout << num << "有多少位1: " << nm4 << endl;
    cout << num << "有多少位1: " << nm4_ << endl;
    cout << num << "(二进制长度（减一得到集合中的最大元素，也就是索引位置）)有多少有效位: " << index1 + 1 << endl;//13( 1101 ) -> 4
    cout << num << "集合的最小元素，最低位为1的位置索引+1 : " << index2 + 1 << endl;//13( 1101 ) -> 1
    cout << num << "判断是否有1: " << nm6 << endl;//13( 1101 ) -> 1   0( 0 ) -> 0

#endif
    return 0;
}