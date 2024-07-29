#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//打家劫舍|
class Solution1 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }
        return f[n - 1];
    }
};

//打家劫舍||
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; ++i) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }

        vector<int> g(n, 0);
        //vector g 不选第一个,选后n-1个
        g[0] = 0;
        g[1] = nums[1];

        for (int i = 2; i < n; ++i) {
            g[i] = max(g[i - 1], g[i - 2] + nums[i]);
        }

        return max(f[n - 2], g[n - 1]);
    }
};

int main()
{   
    Solution1 test1;
    Solution2 test2;
    vector<int>nums = { 1,2,3,1,4,10 };
    cout << test1.rob(nums) << endl;
    cout << test2.rob(nums) << endl;
    return 0;
}