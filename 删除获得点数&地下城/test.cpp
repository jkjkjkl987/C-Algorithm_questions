#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
//ɾ������õ���
//����һ��
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m = nums[n - 1];//�ҵ�������
        vector<int>arr(100);
        for (int i = 0;i < n;++i)
        {
            arr[nums[i]] += nums[i];
        }
        //��һ�δ�ҽ���
        
        vector<int> f(m + 1, 0);
        f[0] = arr[0];
        f[1] = max(arr[0], arr[1]);
        for (int j = 2;j <= m;++j)
        {
            f[j] = max(f[j - 1], f[j - 2] + arr[j]);
        }
        return max(f[m - 1], f[m]);
    }
    //����Ŀ��Լ��ٶ���ռ�
    /*
    class Solution {
private:
    int rob(vector<int> &nums) {
        int size = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

public:
    int deleteAndEarn(vector<int> &nums) {
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }
};

���ߣ����۹ٷ����
���ӣ�https://leetcode.cn/problems/delete-and-earn/solutions/758416/shan-chu-bing-huo-de-dian-shu-by-leetcod-x1pu/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/

    //������������ + ��̬�滮
    class Solution {
    private:
        int rob(vector<int>& nums) {
            int size = nums.size();
            if (size == 1) {
                return nums[0];
            }
            int first = nums[0], second = max(nums[0], nums[1]);
            for (int i = 2; i < size; i++) {
                int temp = second;
                second = max(first + nums[i], second);
                first = temp;
            }
            return second;
        }

    public:
        int deleteAndEarn(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            sort(nums.begin(), nums.end());
            vector<int> sum = { nums[0] };
            for (int i = 1; i < n; ++i) {
                int val = nums[i];
                if (val == nums[i - 1]) {
                    sum.back() += val;
                }
                else if (val == nums[i - 1] + 1) {
                    sum.push_back(val);
            }
                else {
                    ans += rob(sum);
                    sum = { val };
                }
        }
            ans += rob(sum);
            return ans;
    }
};

    ���ߣ����۹ٷ����
        ���ӣ�https ://leetcode.cn/problems/delete-and-earn/solutions/758416/shan-chu-bing-huo-de-dian-shu-by-leetcod-x1pu/
    ��Դ�����ۣ�LeetCode��
        ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
};

int main()
{
    Solution test;
    vector<int> nums = { 2,2,3,3,3,4 };//3+3+3
    //vector<int> nums = { 3,4,2 };//2+4

    cout << test.deleteAndEarn(nums) << endl;
    return 0;
}
#endif


//���³���Ϸ
#if 0
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = sizeof(dungeon);
        int m = sizeof(dungeon[0]);
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>((m + 1), INT_MAX));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for (int i = n - 1;i >= 0;--i)
        {
            for (int j = m - 1;j >= 0;--j)
            {
                int minHP = min(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = max(minHP - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution test;
    vector<vector<int>> dungeon{ { -2, -3, 3}, { -5, -10, 1 }, { 10, 30, -5 } };
    cout << test.calculateMinimumHP(dungeon) << endl;

    return 0;
}
#endif