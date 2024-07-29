#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
class Solution {
public:
    int magicTower(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> pre(n);
        bool ad = true;
        int times = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (i == 0)
                pre[0] = nums[0];
            else
                pre[i] = pre[i - 1] + nums[i];
            // 开始判断
            if (pre[i] < 0) 
            {
                ad = adjust(nums, pre, i, n); // 需要调整
                if (ad == false)
                    return -1;
                else
                    ++times;
            }
        }
        return times;
    }
    bool adjust(vector<int>& nums, vector<int>& pre, int left, int right) 
    {
        if (left < right)   //还有可能的数据可以拿
        {
            if (left == 0)  //第一位
            {
                swap(nums[left], nums[right-1]);// 调整
                pre[left] = nums[left];
            }
            else
            {
                swap(nums[left], nums[right-1]);// 调整
                pre[left] = pre[left - 1] + nums[left];// 更新前缀
            }
        }
        if (left == right - 1)//最后一位
            return false;
        return(pre[left] >= 0);
    }
};
*/
class Solution {
public:
    int magicTower(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;//greater小堆
        long long sum = 1, negative = 0;int count = 0;
        for (int i = 0;i < nums.size();i++)
        {
            if (nums[i] < 0)
                pq.push(nums[i]);
            sum += nums[i];
            while (sum <= 0 && !pq.empty()) {
                int x = pq.top();
                pq.pop();
                negative += x;
                count++;
                sum -= x;
            }
            if (sum <= 0)
                return -1;
        }
        sum += negative;
        if (sum <= 0)
            return -1;
        return count;
    }
};
int main()
{
    Solution test;
    vector<int> nums = { 100,100,100,-250,-60,-140,-50,-50,100,150 };
    cout << test.magicTower(nums);

    return 0;
}

