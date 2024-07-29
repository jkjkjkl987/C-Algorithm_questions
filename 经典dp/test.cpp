#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

#if 0
//爬楼梯的爬法总数
class Solution1 {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        /*
        function<int(int)> dfs = [&](int pos) -> int {
            if (pos == 0)
                return 1;
            else if (pos < 0)
                return 0;
            return dfs(pos - 1) + dfs(pos - 2);
            };
        return dfs(n);
        */
        vector<int> f(n + 3, 0);
        f[2] = 1;
        for (int i = 3;i < n + 3;++i)
            f[i] = f[i - 1] + f[i - 2];
        return f[n + 2];
    }
};


int main()
{
    Solution1 test;
    int n;
    //cin >> n;
    n = 3;
    cout << test.climbStairs(n) << endl;
    return 0;
}

#endif

#if 0
//使用最小花费爬楼梯
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        function<int(int)> dfs = [&](int i) -> int
            {
                if (i <= 1)
                    return 0;
                return min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2]);

            };
        return dfs(n);
    }
};


int main()
{
    Solution2 test;
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    cout << test.minCostClimbingStairs(cost) << endl;
    return 0;
}
#endif 


#if 0
//组合总和 Ⅳ（组合个数）,本质是爬楼梯 

class Solution3_ {
    int dfs(int i, vector<int>& nums, vector<int>& memo) {
        if ( i == 0) { // 爬完了
            return 1;
        }
        int& res = memo[i]; // 注意这里是引用
        if (res != -1) { // 之前计算过
            return res;
        }
        res = 0;
        for (int x : nums) {
            if (x <= i) {
                res += dfs(i - x, nums, memo);
            }
        }
        return res;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1); // -1 表示没有计算过
        return dfs(target, nums, memo);
    }
};
class Solution3__ {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 使用 unsigned 可以让溢出不报错
        // 对于溢出的数据，不会影响答案的正确性（题目保证）
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int x : nums) {
                if (x <= i) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
};

int main()
{
    vector<int> nums = { 1,2,3 };
    Solution3 test;
    Solution3_ test_;
    int target;
    cin >> target;
    cout << test.combinationSum4(nums, target) << endl;
    cout << test_.combinationSum4(nums, target) << endl;
    return 0;
}

#endif

#if 0
//统计打字方案数https://leetcode.cn/problems/count-number-of-texts/description/

const static int MOD = 1e9 + 7, MX = 1e5 + 1;
int f[MX], g[MX];
int init = []() {
    f[0] = g[0] = 1;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = g[3] = 4;
    for (int i = 4; i < MX; ++i) {
        f[i] = (int)(((long)f[i - 1] + f[i - 2] + f[i - 3]) % MOD);
        g[i] = (int)(((long)g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD);
    }
    return 0;
    }();

    class Solution {
    public:
        int countTexts(string& s) {
            int ans = 1, cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                ++cnt;
                char c = s[i];
                if (i == s.length() - 1 || c != s[i + 1]) {
                    ans = (int)((long)ans * (c != '7' && c != '9' ? f[cnt] : g[cnt]) % MOD);
                    cnt = 0;
                }
            }
            return ans;
        }
    };

#endif
