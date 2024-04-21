#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        if (n == 1 && s[0] == '0')
            return -1;
        int pre_ = '0'; // ��һ��ֵһ����1�������ڴ���ֵ��0
        int i = 1;
        int ans = 0;
        int count = 1;
        int count_1 = 0;
        while (i < n) {
            if (s[i] == pre_) {
                if (pre_ == '1')//01
                {
                    count++;
                    pre_ = '0'; // �����ڴ�ֵ
                }
                else//10
                {
                    ans += count_1;
                    count_1 = 0;
                    pre_ = '1';
                }
            }
            else if (pre_ == '1') // ��0���:00,�����۵�1010101����������
            {
                if (count >= 1) 
                {
                    ans += 1;
                }
                ans += count_1;
                count_1 = 0;
                count = 0; // ����
                pre_ = '1';
            }
            else // ��1���:11,�����۵�1010101����������
            {
                if (count >= 1) {
                    ans += 1;
                }
                count = 0; //
                ++count_1;
                pre_ = '0';
            }
            ++i;
        }
        if (count >= 1)
        ans += 1;
        return ans;
    }
};

int main()
{
    Solution test;
    string nums1 = "100111000110111";
    string nums2 = "100111";//4
    string nums3 = "101";//1
    string nums4 = "10001101";//3
    string nums5 = "1101";//2
    cout << test.minimumBeautifulSubstrings(nums1) << endl;
    cout << test.minimumBeautifulSubstrings(nums2) << endl;
    cout << test.minimumBeautifulSubstrings(nums3) << endl;
    cout << test.minimumBeautifulSubstrings(nums4) << endl;
    cout << test.minimumBeautifulSubstrings(nums5) << endl;
    return 0;
}