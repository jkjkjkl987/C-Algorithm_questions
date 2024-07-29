#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

	vector<int>& DOUQIAO(vector<int>& nums)
	{
		int n = nums.size();
		int min_i = 1e9;
		int max_i= -1;
		//找落差最小的位置：该位置的数*2
		for (int j = 1;j < n;++j)
		{
			min_i = min_i <= abs(nums[j] - nums[j - 1]) ? min_i : min(j, j - 1);
		}
		nums[min_i] *= 2;
		// 找落差大的位置： 该位置的数/2
		for (int z = 1;z < n;++z)
		{
			max_i = max_i >= abs(nums[z] - nums[z - 1]) ? max_i : max(z, z - 1);
		}
		nums[max_i] *= 2;

		return nums;
	}
};
int main()
{
	Solution test;
	vector<int> nums1 = { 2,3,2 };
	vector<int> nums2 = { 1,2,3,4 };
	vector<int> ans1 = test.DOUQIAO(nums1);
	vector<int> ans2 = test.DOUQIAO(nums2);
	for (auto e : ans1)
		cout << e << " ";
	for (auto e : ans2)
		cout << e << " ";

	return 0;
}