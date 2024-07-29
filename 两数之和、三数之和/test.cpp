#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

struct numcom_TWO
{
	int a1;
	int a2;
};
struct numcom_THREE
{
	int a1;
	int a2;
	int a3;
};
class Solution
{
public:
	//两数之和
	void Two_add(vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		//stack<struct numcom> myStack;
		sort(nums.begin(), nums.end());
		int j = left;
		int k = right;
		while (j <= k)
		{
			if (j > left && nums[j] == nums[j - 1])
			{
				++j;
				continue;
			}
			if (k < right && nums[k] == nums[k + 1])
			{
				--k;
				continue;
			}
			int s = nums[j] + nums[k];
			if (s > target)
				--k;
			else if (s < target)
				++j;
			else
			{
				cout << nums[j] << " " << nums[k] << endl;
				++j;
				--k;
			}
		}
		return;
	}
	//两数之和,哈希表实现
	void Two_add_HASH(vector<int>& nums, int target)
	{
		int n = nums.size();
		sort(nums.begin(), nums.end());
		unordered_map<int, int> map;
		for (int i = 0;i < n;++i)
		{
			++map[nums[i]];
		}
		int flag = 0;
		int j = 0;
		while (j < n)
		{
			int complement = target - nums[j];
			if (map.count(complement))
			{
				flag = 1;
				// 确保只输出一次满足条件的索引对
				if (nums[j] <= complement)
					cout << "Indices: " << nums[j] << ", " << complement << endl;
			}
			++j;
			while (j > 0 && j < n && nums[j] == nums[j - 1])
			{
				++j;
			}
		}
		if (!flag)
			cout << "没有找到满足的两个数" << endl;
		return;
	}
	//三数之和
	void Three_add(vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		//vector<vector<int>> List(10, vector<int>(3, -1));

		sort(nums.begin(), nums.end());//greater<int>()为降序

		for (int i = left;i <= n - 3;++i)
		{
			int j = i + 1;
			int k = right;
			if (i > 0 && nums[i] == nums[i - 1])//第一个数选择过了，跳过
				continue;
			//优化：因为是升序，如果刚开始的3个数都大于target，后面就没有可能出现小于等于的组合了，后者同理
			if ((nums[i] + nums[i + 1] + nums[i + 2]) > target)
				return;
			if ((nums[i] + nums[n - 1] + nums[n - 2]) < target)
				continue;//因为这里可能还有更大的num[i]

			while (j <= k)
			{
				int s = nums[i] + nums[j] + nums[k];
				if (s > target)
					--k;
				else if (s < target)
					++j;
				else
				{
					cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;

					++j;
					while (j < k && nums[j] == nums[j - 1])
						++j;
					--k;
					while (j < k && nums[k] == nums[k + 1])
						--k;
				}
			}
		}
		return;
	}
};

int main()
{
	Solution test;
	int target;
	vector<int> nums = { 8 ,2 ,-1 ,1 ,3 ,-1 ,4 ,5 ,9 ,0 ,4 ,1 };// 0 -1 -1 1 1 2 3 4 4 5 8 9
	cout << "请输入和：";
	cin >> target;//8
	// -1 9
	//  0 8
	//  3 5
	//  4 4
	test.Two_add(nums, target);
	cout << endl;
	test.Two_add_HASH(nums, target);
	cout << endl;
	// -1 0 9
	// -1 1 8
	// -1 4 5
	//  0 3 5
	//  0 4 4
	//	1 2 5
	//	1 3 4
	 
	test.Three_add(nums, target);
	//cout << "三数之和等于" << target << "的组合是" << test.Three_add(nums, target) << endl;

	return 0;
}