#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q; // 双端队列
        for (int i = 0; i < nums.size(); i++) {
            // 1. 入
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back(); // 维护 q 的单调性,把视野内比num[i]小的元素都清除，因为没有可能成为最高了
            }
            q.push_back(i); // 入队
            // 2. 出
            if (i - q.front() >= k) { // 队首已经离开窗口了
                q.pop_front();
            }
            // 3. 记录答案
            if (i >= k - 1) {
                // 由于队首到队尾单调递减，所以窗口最大值就是队首
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

