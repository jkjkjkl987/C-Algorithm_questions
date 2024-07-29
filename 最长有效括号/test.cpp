#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>	
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

class Solution1 {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) return 0; // 边界情况：空字符串

        int maxLen = 0;
        /*
        for (int i = 0; i < n - 1; ++i) { // 确保至少有两个字符可检查
            for (int j = i + 2; j <= n; j += 2) { // 仅检查偶数长度的子串
                if (isValid(s.substr(i, j - i))) {
                    maxLen = max(maxLen, j - i);
                }
            }
        }
        */
        int m = n;
        if (m % 2)
            --m;
        for (int i = m; i >-1; i-=2) {
            //从最大的偶数开始判断,i为长度，j为字符串起点
            for (int j = 0; j <= n - i + 1; ++j) 
            { 
                if (isValid(s.substr(j, i))) 
                {
                    return i;
                }
            }
        }

        return maxLen;
    }

    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push('(');
            }
            else if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            }
            else {
                return false;
            }
        }
        return stk.empty();
    }
};


class Solution2 {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		stk.push(-1);
		int maxLen = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				stk.pop();
				if (stk.empty()) {
					stk.push(i);
				}
				else {
					maxLen = max(maxLen, i - stk.top());
				}
			}
		}
		return maxLen;
	}
};

int main()
{
    Solution1 test1;
    Solution2 test2;
    string s = { ")()())" };
    cout << test1.longestValidParentheses(s) << endl;
    cout << test2.longestValidParentheses(s) << endl;
    return 0;
}