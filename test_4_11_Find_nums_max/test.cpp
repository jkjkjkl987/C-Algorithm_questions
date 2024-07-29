#define _CRT_SECURE_NO_WARNINGS 1
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <iostream>
/*
class Solution
{
public:
	//第一种写法，两次遍历
	int maxFrequencyElements(std::vector<int>& nums)
	{
		std::unordered_map<int, int> count;//第一个参数是键值的类型，是动态分配内存的
		int maxCount = 0;
		for (int num : nums)//它会遍历整数列表 nums 中的每一个元素，并将当前元素赋值给变量 num
		{
			maxCount = std::max(maxCount, ++count[num]);
		}
		int ans = 0;
		for (const auto& pair : count)//这里可以做优化，双指针。。。
		{
			if (pair.second == maxCount)//等于最大次数
			{
				ans += pair.second;//最大频率
			}
		}
		return ans;
	}
	
	//第二种写法，对哈希表遍历中更新ans 和 maxCount，两次遍历
	// (但可以在遍历一次哈希表就可以找到最大频率，所以这种写法明显多余)
	
	int maxFrequencyElements(std::vector<int>& nums)
	{
		std::unordered_map<int, int> count;
		for (int num : nums)
		{
			++count[num];
		}
		// (1) 1 (2) 2 (3) 3 (4) 3
		int maxCount = 0;
		int ans = 0;
		for (const auto& pair : count)
		{	
			if (pair.second > maxCount)
			{
				maxCount = pair.second;
				ans = maxCount;
			}
			else if (pair.second == maxCount)//等于最大次数
			{
				ans += pair.second;//最大频率
			}
		}
		return ans;
	}
	
	//第三种写法，一次遍历
	
	int maxFrequencyElements(std::vector<int>& nums)
	{
		std::unordered_map<int, int> count;
		int maxCount, ans;
		maxCount = ans = 0;
		for (int x : nums)
		{
			int c = ++count[x];//关键的一步，类似哈希表了
			if (c > maxCount)
			{
				maxCount = c;
			}
			else if(c==maxCount)
			{
				ans += c;
			}
		}
		return ans;
	}
	
};

int main() {
	// 创建 Solution 对象
	Solution solution;

	// 准备需要统计的整数列表
	std::vector<int> nums = { 1, 2, 2, 3, 3, 3 ,4 ,4 ,4 };

	// 调用 maxFrequencyElements 方法并打印结果
	int result = solution.maxFrequencyElements(nums);
	std::cout << "Sum of most frequent elements: " << result << std::endl;

	return 0;
}
*/

