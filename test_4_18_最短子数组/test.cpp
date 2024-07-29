#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//暴力枚举
	int minsubArrayLen(vector<int> nums, int target)
	{
		int n = nums.size();
		int minlen = 0;

		for (int i = 0;i < n;++i)
		{
			int count = nums[i];
			int len = 0;
			for (int j = i;j < n;++j)
			{
				if (i != j)
					count += nums[j];
				++len;//也可以用 j-i+1
				if (count > target)
				{
					continue;//因为是正数，更长的子数组肯定也更大，不需要比较了
				}
				if (count == target)
				{
					if (minlen == 0)
					{
						minlen = len;
					}
					else
					{
						minlen = min(minlen, len);//更新最小的长度
						if (minlen == 1)
							return 1;
						else
						continue;//不用找更长的了，跳到下一个枚举
					}
				}
			}
		}
		return minlen;
	}
	//但是因为每一个左端点是从左到右扩展的，并且内部循环右端点的的最大移动为n-i,时间复杂度为O(n^2)
	//巨大优化：（左端点遇到count>target停下，找到右端点，此时左右端点之间的和）
	int minsubArrayLen_(vector<int> nums, int target)
	{
		int n = nums.size();
		int count = 0;
		int left = 0;
		int right = 0;
		int minlen = n + 1;//len最大值为n
		for (int x : nums)
		{
			++right;
			count += x;//扩展右端点
			while (count - nums[left] >= target)//缩短左端点
			{
				count -= nums[left];
				++left;
			}
			if (count == target)
			minlen = min(minlen, right - left + 1);
		}
		return minlen < n + 1 ? minlen : -1;
	}
};

int main()
{
	Solution test;
	vector<int> nums1 = { 2,3,1,2,4,3 };
	vector<int> nums2 = { 1,4,4 };
	vector<int> nums3 = { 1,1,1,1,1,1,1,1 };
	int target1;// 7  2
	int target2;// 4  1
	int target3;//11  0
	cin >> target1;
	cin >> target2;
	cin >> target3;

	cout << "满足和为" << target1 << "的最短子数组的长度为" << test.minsubArrayLen(nums1, target1) << endl;
	cout << "满足和为" << target2 << "的最短子数组的长度为" << test.minsubArrayLen(nums2, target2) << endl;
	cout << "满足和为" << target3 << "的最短子数组的长度为" << test.minsubArrayLen(nums3, target3) << endl;
	cout << endl;
	cout << "满足和为" << target1 << "的最短子数组的长度为" << test.minsubArrayLen_(nums1, target1) << endl;
	cout << "满足和为" << target2 << "的最短子数组的长度为" << test.minsubArrayLen_(nums2, target2) << endl;
	cout << "满足和为" << target3 << "的最短子数组的长度为" << test.minsubArrayLen_(nums3, target3) << endl;

	return 0;
}