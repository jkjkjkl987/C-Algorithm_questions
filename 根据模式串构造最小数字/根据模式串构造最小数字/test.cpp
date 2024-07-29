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
        vector<bool> used(10, false); // 用于跟踪数字是否已使用

        // 初始化结果数组
        for (int i = 0; i <= n; ++i) {
            result[i] = '1' + i;
        }

        // 根据模式进行调整
        for (int i = 0; i < n; ++i) {
            if (pattern[i] == 'D') {
                int j = i;
                // 找到连续的 'D' 的末尾
                while (i < n && pattern[i] == 'D') {
                    ++i;
                }
                // 反转从 j 到 i 的部分
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
