#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <numeric>//accumulate
#include <functional>
#include <time.h>

using namespace std;

//从非负整形数组中的元素中，添加“+” “-”使得他们的和等于target,求有多少种组合
//这种题归为 0 - 1背包问题
class Solution1
{
public:
	//递归
	int findTargetSumWays_One(vector<int>& nums, int target)
	{
		target += accumulate(nums.begin(), nums.end(), 0);//s+t
		if (target < 0 || target % 2) return 0;
		target /= 2;
		int numsSize = nums.size();

		function<int(int, int)> dfs = [&](int i, int c) -> int
			{
				if (i < 0)
				{
					if (c == 0)
						return 1;
					return 0;
				}
				if (nums[i] > c)
					return dfs(i - 1, c);
				return dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
			};
		return dfs(numsSize - 1, target);
	}
	//优化：记忆化搜索
	int findTargetSumWays_Two(vector<int>& nums, int target)
	{

		target += accumulate(nums.begin(), nums.end(), 0);//s+t
		if (target < 0 || target % 2) return 0;
		target /= 2;
		int numsSize = nums.size();
		vector<vector<int>> memo(numsSize, vector<int>(target + 1, -1));

		function<int(int, int)> dfs = [&](int i, int c) -> int
			{
				if (i < 0)
				{
					if (c == 0)
						return 1;
					return 0;
				}
				int& res = memo[i][c];
				if (nums[i] > c)
				{
					if (res != -1)
						return res;
				}
				if (res != -1)
				{
					return res;
				}
				return res = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);

			};
		return dfs(numsSize - 1, target);
	}
	//1:1 翻译成递推
	int findTargetSumWays_Three(vector<int>& nums, int target)
	{
		// p 为"+"元素的和 
		// s-p为要添加"-"元素的和
		//那么， p-s(s-p)就是target
		//化简得，p = (s+t)/2 ,且因为p非负，s+t不能为负数和奇数
		target += accumulate(nums.begin(), nums.end(), 0);//s+t
		if (target < 0 || target % 2) return 0;
		target /= 2;
		int i, c;
		int numsSize = nums.size();
		vector<vector<int>> f(numsSize + 1, vector<int>(target + 1, 0));//记录状态
		//定义一个大小为 (target + 1) x target 的二维数组，并初始化为0

		f[0][0] = 1;//因为对递公式i+1所以之前(i < 0 && c == 0)对应f[0][0]
		for (i = 0;i < numsSize;++i)
		{
			for (c = 0;c <= target;++c)
			{
				if (c < nums[i])
					f[i + 1][c] = f[i][c];//意味着现在的i的值“体积”超过了限制，不可取，转移到下一个数据
				else
					f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
			}
		}
		return f[numsSize][target];//这里原本的f[n-1][c]的状态对应到了f[n][c],因为下标+1了;
		//原本需要计算的状态是从f[0] - f[n-1],其中对应着nums[0]~nums[n-1],
		//经过+1，nums[0]~nums[n-1]对应的状态转移到了f[1]~f[n]
	}
		//空间优化：因为每一次计算i+1的状态只用到了 i,并且后面没有用到 i
		// 所以仅仅需要两个数组来相互替换
		//滚动数组：
	int findTargetSumWays_Four(vector<int>& nums, int target)
	{
		target += accumulate(nums.begin(), nums.end(), 0);//s+t
		if (target < 0 || target % 2) return 0;
		target /= 2;

		int numsSize = nums.size();
		vector<vector<int>> f(2, vector<int>(target + 1, 0)); // 使用动态内存分配来创建二维数组
		f[0][0] = 1;
		for (int i = 0; i < numsSize; ++i)
			for (int c = 0; c <= target; ++c)
				if (c < nums[i]) f[(i + 1) % 2][c] = f[i % 2][c];
				else f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]];
		return f[numsSize % 2][target];
	};
	//空间优化：一个数组
	int findTargetSumWays_Five(vector<int>& nums, int target) {
		target += accumulate(nums.begin(), nums.end(), 0);
		if (target < 0 || target % 2) return 0;
		target /= 2;

		vector<int> f(target + 1, 0);

		f[0] = 1;
		for (int x : nums)
			for (int c = target; c >= x; --c)//这里要注意的是需要从后向前枚举，否则会造成提前覆盖掉要计算的值
				//由于c<x的情况为：f[c] =f[c]，故可以省略
				//所以只需要考虑c>=x 的情况：
				f[c] += f[c - x];//递推公式简化，第一个维度可以省略
		return f[target];
	};
};

//给出一些硬币的数组，从中挑出硬币使得面值和等于amount（可以重复取相同的硬币），找出需要最小的coin数量
//完全背包问题: 
class Solution2
{
public:   
	int coinChange_One(vector<int>& coin, int amount)
	{	
		//返回值是硬币个数，只有选择了才会+1
		int n = coin.size();
		function<int(int, int)> dfs = [&](int i, int c) -> int
			{
				if (i < 0)
				{
					if (c == 0)return 0;//没有硬币可以选了，不能是返回1
					else return INT_MAX;
				}
				if (coin[i] > c)
					return dfs(i - 1, c);
				return min(dfs(i - 1, c), dfs(i, c - coin[i]) + 1);
			};
		int res = dfs(n - 1, amount);
		if (res == INT_MAX)//没有合法的方案
			return 0;
		else
		return res;
	}

	//翻译成递推：
	int coinChange_Two(vector<int>& coin, int amount)
	{
		//返回值是硬币个数，只有选择了才会+1
		int n = coin.size();
		vector<vector<int>> f(n + 1, vector<int>(amount + 1, INT_MAX));
		f[0][0] = 0;//递推的初始值就是递归的边界
		for (int i = 0;i < n;++i)
		{
			for (int c = 0;c <= amount;++c)
			{
				if (c < coin[i])//不能选择
					f[i + 1][c] = f[i][c];
				else//可以选择
					f[i + 1][c] = min(f[i][c], f[i + 1][c - coin[i]] + 1);
			}
		}
		if (f[n][amount] == INT_MAX)//没有合法的方案
			return -1;
		else
			return f[n][amount];
	}

	//空间优化：滚动数组
	int coinChange_Three(vector<int>& coins, int amount)
	{
		//返回值是硬币个数，只有选择了才会+1
		int n = coins.size();
		vector<vector<int>> f(2, vector<int>(amount + 1, INT_MAX));
		f[0][0] = 0;//递推的初始值就是递归的边界
		for (int i = 0;i < n;++i)
		{
			for (int c = 0;c <= amount;++c)
			{
				if (c < coins[i])//不能选择
					f[(i + 1) % 2][c] = f[i % 2][c];
				else//可以选择
					f[(i + 1) % 2][c] = min(f[i % 2][c], f[(i + 1) % 2][c - coins[i]] + 1);
			}
		}
		if (f[n % 2][amount] == INT_MAX)//没有合法的方案
			return -1;
		else
			return f[n % 2][amount];
	}
	//空间优化：一维数组
	int coinChange_Four(vector<int>& coins, int amount)
	{
		//返回值是硬币个数，只有选择了才会+1
		int n = coins.size();
		vector<int> f(amount + 1, INT_MAX);
		f[0] = 0;//递推的初始值就是递归的边界
		for (int i = 0;i < n;++i)
		{
			for (int c = coins[i];c <= amount;++c)
			{
				if (c >= coins[i])
					f[c] = min(f[c], f[c - coins[i]] + 1);
			}
		}
		if (f[amount] == INT_MAX)//没有合法的方案
			return -1;
		else
			return f[amount];
	}
};


int main()
{	
	/*
	Solution1 test;
	int space1 = 200;
	vector<int> nums(space1, 1);
	int target;
	cin >> target;

	//递归
	int time1 = clock();
	cout << "使得数据的组合表达式=" << target << "的组合数量为：" << test.findTargetSumWays_One(nums, target) << endl;
	int time2 = clock();
	cout << time2 - time1 << endl;
	//递归->记忆化搜索
	time1 = clock();
	cout << "使得数据的组合表达式=" << target << "的组合数量为：" << test.findTargetSumWays_Two(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	//递推（二维数组）
	time1 = clock();
	cout << "使得数据的组合表达式=" << target << "的组合数量为：" << test.findTargetSumWays_Three(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	//递推->空间优化：滚动数组
	time1 = clock();
	cout << "使得数据的组合表达式=" << target << "的组合数量为：" << test.findTargetSumWays_Four(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	//递推->空间优化：一维数组
	time1 = clock();
	cout << "使得数据的组合表达式=" << target << "的组合数量为：" << test.findTargetSumWays_Five(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	*/

	Solution2 test_;
	int amount;
	vector<int> coin = { 1,2,5 };
	cin >> amount;
	//递归
	cout << "构成价值为" << amount << "的最少硬币数量为：" << test_.coinChange_One(coin, amount) << endl;
	//递推
	cout << "构成价值为" << amount << "的最少硬币数量为：" << test_.coinChange_Two(coin, amount) << endl;
	//滚动数组
	cout << "构成价值为" << amount << "的最少硬币数量为：" << test_.coinChange_Three(coin, amount) << endl;
	//一维数组
	cout << "构成价值为" << amount << "的最少硬币数量为：" << test_.coinChange_Four(coin, amount) << endl;

	return 0;
}