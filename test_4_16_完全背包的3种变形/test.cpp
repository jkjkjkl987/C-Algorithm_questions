#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;


class Solution
{
public:
	//目标和：至少为target
	//由于递归中的返回条件为i<0,c<=0,则
	int Findleastnum(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//对于这道题需要计算出p，当作容量
		target /= 2;
		vector<int> f(target + 1, 0);
		f[0] = 1;//初始值表示递归的边界条件为c<=0时，返回1
		for (int x : nums)
		{
			for (int c = target;c >= 0;--c)
			{
				f[c] = f[c] + f[max(c - x, 0)];//逆序，将满足c<x的方案累加到f[0]
				//例如target =0;经计算：第一步 f[target] = 1 + 1 = 2; 
				// 第二步 f[target] = 2 + 2; 
				// 第三步 f[target] = 4 + 4;
				//		  f[0] = 16 …… ——> f[0] = 2^n; 
				// 也正好对应着 n个数，target=0时没有约束，都可以选或者不选，有2^n种选法
			}
		}
		return f[target];//表示 从所有的x中选数，使得至多c的容量为0，也就是可以选择更多的正值，即c<=0
	}
	//递归
	int Findleastnum_(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//对于这道题需要计算出p，当作容量
		target /= 2;
		function<int(int, int)> dfs = [&](int i, int c)->int
			{
				if (i < 0)
				{
					if (c <= 0)
						return 1;
					return 0;
				}
				return dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
			};
		return dfs(n - 1, target);
	}
	//目标和：至多为target
	//由于递归中的返回条件为i<0，c>=0,则从递归到递推公式的一维数组时
	int Findmostnum(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//对于这道题需要计算出p，当作容量
		target /= 2;
		vector<int> f(target + 1, 1);
		//初始值表示递归的边界条件为c>=0时，返回1,0<=容量,意味着选择完的组合没有填满容量c
		for (int x : nums)
		{
			for (int c = target;c >= x;--c)
			{
				f[c] = f[c] + f[c - x];//倒序
			}
		}
		return f[target];
	}
	
	//递归
	int Findmostnum_(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//对于这道题需要计算出p，当作容量
		target /= 2;

		function<int(int, int)>dfs = [&](int i, int c) -> int
			{
				if (i < 0)
				{
					if (c >= 0)return 1;else return 0;
				}
				if (c < nums[i])
					return dfs(i - 1, c);
				return dfs(i - 1, c) + dfs(i - 1, c - nums[i]);//不选和选
			};
		return	dfs(n - 1, target);
	}
};

int main()
{
	int target;
	Solution test;
	vector<int> nums = { 1, 1, 1, 1  };
	cin >> target;//0 -> 11 -> 11 -> 11 -> 11
	cout << "目标和至少是" << target << "的组合数量为：" << test.Findleastnum(nums, target) << endl;
	cout << "目标和至少是" << target << "的组合数量为：" << test.Findleastnum_(nums, target) << endl;

	cout << "目标和至多是" << target << "的组合数量为：" << test.Findmostnum(nums, target) << endl;
	cout << "目标和至多是" << target << "的组合数量为：" << test.Findmostnum_(nums, target) << endl;

	return 0;
}