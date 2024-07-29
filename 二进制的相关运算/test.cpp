#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <bitset>
#include <intrin.h>

using namespace std;

class Solution
{
public:
    void NumbersInSet(int num)/*ͳ�Ƽ����е�ÿ��Ԫ�أ��Ӵ�Сö�ټ��ϵ����зǿ��Ӽ���
                                10101 -> 10100 -> 10001 -> 10000 -> 00101 -> 00100 -> 00001
    �൱��������Ķ����Ƽ���    1 1 1    1 1 0    1 0 1    1 0 0    0 1 1    0 1 0    0 0 1
    */
    {
        int lowbit = num & (num - 1);
        while (lowbit)
        {
            cout << lowbit << " ";
            lowbit = num & (lowbit - 1);
        }
    }

    void NumbersInSetExtension(int num)/*��չ���Ԫ�أ������Ŵ�ʱ���Ӽ��ĸ��󼯺�
                                       10101 -> 10111 -> 11101 -> 11111 ->110101 -> 110111 -> 111101 -> 111111    
                                       ( 21 )   ( 23 )   ( 29 )   ( 31 )  ( 53 )    ( 55 )    ( 61 )    ( 63 )
    �൱��������Ķ����Ƽӷ�           _0_0_    _0_1_    _1_0_    _1_1_   1_0_0_    1_0_1_    1_1_0_    1_1_1_                                
    */
                                       
    {
        int n = 6;
        int j = 0;
        int lowbit;
        long long ans = num;
        int x = num;
        x = ~x;//��ʱ�Ķ����Ƶ�1����֮ǰ��0�����������λ��
        int count = 0;
        while (++count <= n)//�� 0 1 ��ʼ���� ֱ��Ϊn
        {
            while (count >> j)
            {
                lowbit = x & (-x);//num��������СԪ��
                ans |= (long long)lowbit * ((count >> j) & 1);
                ++j;
                x ^= lowbit;//��
            }
            cout << ans << " ";
            j = 0;
            x = ~num;
            ans = num;//����ѡ���µ�num����count�Ķ�����λ
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
    unsigned long index;//���ڴ������λ�����ı���

    cin >> num;
    int nm1 = bitset<64>(num).count();//����������ж���1
    int nm2 = bitset<32>(num).size();//������Ƶ�λ��
    unsigned char result = _BitScanReverse64(&index, num);//������Ƶ���Чλ�� ,����Ҳ�����Чλ�����Ὣ result ��������Ϊ 0
    //��Ϊ�����ƴ��������Ǵ�0��ʼ�ģ���������Ϊ0��ζ�ŵ�һλ
    int nm3 = index + 1;
    /*
    unsigned char _BitScanReverse64(
        unsigned long* Index,
        unsigned __int64 Mask
    );
    */

    //��Щ������GCC �����ú���
    //int nm4 = __builtin_popcount(num);
    //int nm5 = 32 - __builtin_clz(num);
    //int nm6 = __builtin_ctz(num);

    int nm4 = _mm_popcnt_u32(num);
    int nm4_ = _mm_popcnt_u64(num);
    unsigned long index1;
    unsigned long index2;
    int nm5 = _BitScanReverse(&index1, num);//index1Ϊ ���λ1������λ�ã�
    int nm6 = _BitScanForward(&index2, num);//index2Ϊ ���λ1������λ��

    cout << num << "�ж���λ1: " << nm1 << endl;
    cout << num << "�ж���λ: " << nm2 << endl;
    cout << num << "�ж�����Чλ: " << nm3 << endl;

    cout << num << "�ж���λ1: " << nm4 << endl;
    cout << num << "�ж���λ1: " << nm4_ << endl;
    cout << num << "(�����Ƴ��ȣ���һ�õ������е����Ԫ�أ�Ҳ��������λ�ã�)�ж�����Чλ: " << index1 + 1 << endl;//13( 1101 ) -> 4
    cout << num << "���ϵ���СԪ�أ����λΪ1��λ������+1 : " << index2 + 1 << endl;//13( 1101 ) -> 1
    cout << num << "�ж��Ƿ���1: " << nm6 << endl;//13( 1101 ) -> 1   0( 0 ) -> 0

#endif
    return 0;
}