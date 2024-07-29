#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 判断给定的出栈序列是否可以通过给定的入栈序列生成
     *
     * @param pushV int整型vector - 入栈序列
     * @param popV int整型vector - 出栈序列
     * @return bool布尔型 - 如果出栈序列是有效的则返回true，否则返回false
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        if (pushV.size() != popV.size()) return false;

        stack<int> stk;
        int popIndex = 0;

        for (int i = 0; i < pushV.size(); ++i) {
            stk.push(pushV[i]);

            while (!stk.empty() && stk.top() == popV[popIndex]) {
                stk.pop();
                ++popIndex;
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution test;
    vector<int> pushV = { 1, 2, 3, 4, 5 };
    vector<int> popV = { 4, 5, 3, 2, 1 };
    cout << (test.IsPopOrder(pushV, popV) ? "true" : "false") << endl;
    return 0;
}

//方法二：原地栈
#if 0
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        //表示栈空间的大小，初始化为0
        int n = 0;
        //出栈序列的下标
        int j = 0;
        //对于每个待入栈的元素
        for (int num : pushV) {
            //加入栈顶
            pushV[n] = num;
            //当栈不为空且栈顶等于当前出栈序列
            while (n >= 0 && pushV[n] == popV[j]) {
                //出栈，缩小栈空间
                j++;
                n--;
            }
            n++;
        }
        //最后的栈是否为空
        return n == 0;
    }
};
#endif

