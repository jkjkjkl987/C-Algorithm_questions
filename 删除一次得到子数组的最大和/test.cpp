#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


//可删除一次的连续数组最大和
class Solution {
public:
    //递归
    int maximumSum(vector<int>& arr) {

        int ans = INT_MIN, n = arr.size();
        vector<vector<int>> memo(n + 1, vector<int>(2, INT_MIN));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0) 
                return INT_MIN / 2; // 除 2 防止负数相加溢出
            int& res = memo[i][j]; // 注意这里是引用
            if (res != INT_MIN) 
                return res; // 之前计算过
            if (j == 0) 
                return res = max(dfs(i - 1, 0), 0) + arr[i];
            return res = max(dfs(i - 1, 1) + arr[i], dfs(i - 1, 0));
            };
        for (int i = 0; i < n; i++)
            ans = max(ans, max(dfs(i, 0), dfs(i, 1)));
        return ans;
    };
    // 1:1翻译递推
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, INT_MIN / 2));
        // 0表示不能删除了，1表示可以删除一次
        // dp[0][0] = INT_MIN;
        // dp[0][1] = INT_MIN;
        for (int i = 1; i < n + 1; ++i) {
            // 状态转移：转化成子问题，求i和连续数组最大和转而求i-1个连续数组的最大和
            dp[i][0] = max(dp[i - 1][0], 0) +
                arr[i - 1]; // 已经删过的（也就是j==0）,其状态只能从0得到
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i - 1]);
        }
        // return max(dp[n - 1][0], dp[n -
        // 1][1]);//这样少了一种状态，没有ar[n]的选与不选
        int ans = INT_MIN;
        for (int k = 0; k < n + 1; ++k) {
            ans = max(ans, max(dp[k][0], dp[k][1]));
        }
        return ans;
    }
    //递推(空间优化)
    int maximumSum__(vector<int>& arr) {
        int dp0 = arr[0], dp1 = 0, res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            dp1 = max(dp0, dp1 + arr[i]);
            dp0 = max(dp0, 0) + arr[i];
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};

int main()
{
    vector<int> arr = { 1,-2,0,3 };
    Solution test;
    cout << test.maximumSum(arr) << endl;
    cout << test.maximumSum_(arr) << endl;
    cout << test.maximumSum__(arr) << endl;

    return 0;
}