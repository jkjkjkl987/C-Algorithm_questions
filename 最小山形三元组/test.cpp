#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n); // 后缀最小值
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 1; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        int ans = INT_MAX;
        int pre = nums[0]; // 前缀最小值
        for (int j = 1; j < n - 1; j++) {
            if (pre < nums[j] && nums[j] > suf[j + 1]) { // 山形
                ans = min(ans, pre + nums[j] + suf[j + 1]); // 更新答案
            }
            pre = min(pre, nums[j]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution test;
    vector<int> nums1 = { 8,6,1,5,3 };
    cout << test.minimumSum(nums1) << endl;
    vector<int> nums2 = { 1,3,2,5,4 };
    cout << test.minimumSum(nums2) << endl;
    vector<int> nums3 = { 40, 22, 37, 43, 6, 32, 30, 23 };
    cout << test.minimumSum(nums3) << endl;

    return 0;
}