#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result(n + 1, ' ');
        vector<bool> used(10, false); // ���ڸ��������Ƿ���ʹ��

        // ��ʼ���������
        for (int i = 0; i <= n; ++i) {
            result[i] = '1' + i;
        }

        // ����ģʽ���е���
        for (int i = 0; i < n; ++i) {
            if (pattern[i] == 'D') {
                int j = i;
                // �ҵ������� 'D' ��ĩβ
                while (i < n && pattern[i] == 'D') {
                    ++i;
                }
                // ��ת�� j �� i �Ĳ���
                reverse(result.begin() + j, result.begin() + i + 1);
            }
        }

        return result;
    }
};

int main() {
    Solution test;
    string s = "IIIDIDDD";// 123549876
    cout << test.smallestNumber(s) << endl;

    return 0;
}
