#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int minpath = INT_MAX;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        function <int(int, int)> dfs = [&](int cur, int pathtime)->int
            {
                /*
                if (cur > n - 1)
                {
                    return INT_MAX;
                }*/
                if (nums[cur] == 0)
                    return INT_MAX;
                if (cur == n-1)
                {
                    return pathtime;
                }
                //���������nums[i]+j
                int limit = min(nums[cur], n - cur - 1);
                for (int j = 1; j <= limit; ++j) {
                    int next_pos = cur + j;
                    if (dp[next_pos][j]) continue; // ����Ѿ����ʹ���λ�ã�������
                    dp[next_pos][j] = 1; // ��Ǹ�λ��Ϊ�ѷ���
                    minpath = min(minpath, dfs(next_pos, pathtime + 1));
                }
                return minpath;
            };
        return dfs(0, 0);
    }
    
    //����Ϊ���ƣ�
#if 1
    int jump_(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) 
        {
            if (dp[i] == INT_MAX) continue; // �����ǰλ�ò��ɴ������

            int limit = min(nums[i], n - i - 1); // ���Ʋ���, ���ܳ�������ĩβ
            for (int j = 1; j <= limit; ++j) 
            {
                int next_pos = i + j;
                dp[next_pos] = min(dp[next_pos], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
#endif
};

int main()
{
    //vector<int> nums = { 2,3,1,1,4 };//2
    vector<int> nums = { 1,2,3 };//2
    Solution test;
    cout << test.jump(nums) << endl;
    cout << test.jump_(nums) << endl;
    return 0;
}