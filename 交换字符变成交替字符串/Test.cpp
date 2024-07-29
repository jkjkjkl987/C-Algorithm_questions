#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if (n == 1)
            return 0;
        int zero = 0, one = 0;
        for (auto e : s) {
            e == '0' ? ++zero : ++one;
        }
        if ((zero - one > 1) || (one - zero > 1))
            return -1;

        char maxchar = '0';
        if (n % 2 == 1)
            maxchar = zero > one ? '0' : '1';
        // 计算奇数位的字符最多的，对应偶数位就是最少的（或者都相等）
        // 需要满足交换后奇偶位都各为唯一的字符
        // 计算奇数位的字符
        zero = 0;
        one = 0;
        for (int i = 0; i < n; i += 2) {
            s[i] == '0' ? ++zero : ++one;
        }
        //偶数位
        if ((zero == 0 || one == 0) && n % 2 == 0)
        {
            return 0;
        }
        if (n % 2 == 0)
            return min(zero, one);
        char flag = zero > one ? '0' : '1';//找出奇数位最多的字符
        
        //奇数
        if (maxchar == flag)
            return min(zero, one);
        else
            return max(zero, one);
    }
};


int main()
{
    Solution test;
    string s1 = "111000";
    string s2 = "010";
    string s3 = "1110";
    string s4 = "100";
    string s5 = "1001";
    string s6 = "00011110110110000000000110110101011101111011111101010010010000000000000001101101010010001011110000001101111111110000110101101101001011000011111011101101100110011111110001100110001110000000001100010111110100111001001111100001000110101111010011001";
    string s7 = "0111010";

    cout << test.minSwaps(s1) << endl;
    cout << test.minSwaps(s2) << endl;
    cout << test.minSwaps(s3) << endl;
    cout << test.minSwaps(s4) << endl;
    cout << test.minSwaps(s5) << endl;
    cout << test.minSwaps(s6) << endl;
    cout << test.minSwaps(s7) << endl;

    return 0;
}