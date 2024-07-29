#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//�������һ��Ԫ�ص���Сֵ
class Solution {
public:
    long long minEnd(int n, int x) {

        //�����㷨�����μ�һ
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
        // λ���� ��ʱ�临�Ӷ�Ϊ logx + logn
        long long end = x;
        n -= 1; // x�ǵ�һ����������n-1�����������Ӽ���x�������Ǵ�
        int i = 0;
        int j = 0;
        int bit = 0;
        while (n >> j) {
            // Ѱ��x�п�����ӵĿ�λ
            if ((x >> i & 1) == 0) {
                // n��������ĵ�iλ��
                bit = n >> j & 1;
                x |= bit << i;
                ++j;
            }
            ++i; // ��û�п�λ������һ������λ����Ѱ�ҿ�λ
        }
        return x;
        */

        // �Ż�
       // �Ż�����Ϊ��������x��λ���ܲ���0��������ù�������������Ż���ֱ�Ӷ�x��������Ϊ0�����j�ϵ�λ
       //  ʱ�临�Ӷȣ�longn
        n -= 1;
        int bit;
        int j = 0;
        long long t = ~x; // x = 100 100,t = 011 011
        long long lowbit;
        long long ans = x;//��long long ���ر��ⷵ���Ǹ���
        while (n >> j) {
            lowbit = t & -t; /* ��ȡ�����λ��1: 011 011 & 100 101 ->000 001
                                                011 010 & 100 110 ->000 010
                                                 ������������       ->001 000
                                                 ������������       ->010 000
                                                 */
            bit = n >> j & 1;
            ans |= (long long)bit * lowbit; // �൱�������if else
            // ��bitΪ0���Ϊ0��bitΪ1ʱ���Ϊ1��
            ++j; // n����һλ
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