#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>nums)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		int ans = 0;
		int tmp = 0;
		while (left < right)
		{
			tmp = (right - left) * min(nums[left], nums[right]);
			ans = max(ans, tmp);
			if (nums[left] < nums[right])
				++left;
			else
				--right;
		}
		return ans;
	}
	//额外空间复杂度为 O(n),
	int trap(vector<int>height)
	{	
		int n = height.size();
		vector<int> pre_max(n, 0);
		vector<int> suf_max(n, 0);
		//求前缀
		int ans = 0;
		pre_max[0] = height[0];
		for (int i = 1;i < n;++i)
		{	
			pre_max[i] = max(pre_max[i - 1], height[i]);
		}
		//前缀数组打印
		for (int p : pre_max)
		{
			cout << p << " ";
		}
		cout << endl;
		//求后缀
		suf_max[n - 1] = height[n - 1];
		for (int j = n - 2;j >= 0;--j)
		{
			suf_max[j] = max(suf_max[j + 1], height[j]);
		}
		//后缀数组打印
		for (int q : suf_max)
		{
			cout << q << " ";
		}
		cout << endl;
		//枚举每一个位置0~n-1 , 宽度为1
		int count = 0;
		for (int l = 1;l < n-1;++l)
		{
			if ((height[l] > pre_max[l - 1]) || height[l] > suf_max[l + 1])//没有洼地
				continue;
			if (height[l] < pre_max[l - 1] && height[l] < suf_max[l + 1])
				count += (min(pre_max[l - 1], suf_max[l + 1]) - height[l]);
		}
		return count;
	}
	//空间优化：用两个变量记录前缀、后缀的最大值 O(1)
	int trap_(vector<int>height)
	{
		int n = height.size();
		int left = 0;
		int right = n - 1;
		int premax = 0;
		int sufmax = 0;
		int count = 0;
		//这道题的性质是：若前缀的最大值小于后缀的最大值，则该处（left）前缀的最大值-该处高度，至少也是0，反之right处计算方法相同
		while (left <= right)//因为重合点也要计算存水量
		{
			premax = max(premax, height[left]);
			sufmax = max(sufmax, height[right]);
			if (premax < sufmax)
			{
				count += premax - height[left];
				++left;
			}
			else
			{
				count += sufmax - height[right];
				--right;
			}
		}
		return count;
	}
};

int main()
{
	vector<int>nums = { 1,8,6,2,5,4,8,3,7 };
	Solution test;
	vector<int>height = { 0 ,1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	cout << test.maxArea(nums) << endl;//49
	cout << test.trap(height) << endl;//6
	cout << test.trap_(height) << endl;//6
}