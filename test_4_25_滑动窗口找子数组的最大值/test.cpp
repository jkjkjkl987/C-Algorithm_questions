#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q; // ˫�˶���
        for (int i = 0; i < nums.size(); i++) {
            // 1. ��
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back(); // ά�� q �ĵ�����,����Ұ�ڱ�num[i]С��Ԫ�ض��������Ϊû�п��ܳ�Ϊ�����
            }
            q.push_back(i); // ���
            // 2. ��
            if (i - q.front() >= k) { // �����Ѿ��뿪������
                q.pop_front();
            }
            // 3. ��¼��
            if (i >= k - 1) {
                // ���ڶ��׵���β�����ݼ������Դ������ֵ���Ƕ���
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};

ostream& operator<<(ostream& out, const vector<int> ans)
{
    for (int i : ans)
        cout << i << " ";
    return out;
}
int main()
{
    vector<int> nums = { 3,-1,2,4,2,0,1,-2 };
    Solution test;
    int k;
    cin >> k;
    vector<int> result = test.maxSlidingWindow(nums, k);
    cout << result << endl;
    return 0;
}

