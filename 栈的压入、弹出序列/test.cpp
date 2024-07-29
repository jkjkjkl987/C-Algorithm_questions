#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * �жϸ����ĳ�ջ�����Ƿ����ͨ����������ջ��������
     *
     * @param pushV int����vector - ��ջ����
     * @param popV int����vector - ��ջ����
     * @return bool������ - �����ջ��������Ч���򷵻�true�����򷵻�false
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

//��������ԭ��ջ
#if 0
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        //��ʾջ�ռ�Ĵ�С����ʼ��Ϊ0
        int n = 0;
        //��ջ���е��±�
        int j = 0;
        //����ÿ������ջ��Ԫ��
        for (int num : pushV) {
            //����ջ��
            pushV[n] = num;
            //��ջ��Ϊ����ջ�����ڵ�ǰ��ջ����
            while (n >= 0 && pushV[n] == popV[j]) {
                //��ջ����Сջ�ռ�
                j++;
                n--;
            }
            n++;
        }
        //����ջ�Ƿ�Ϊ��
        return n == 0;
    }
};
#endif

