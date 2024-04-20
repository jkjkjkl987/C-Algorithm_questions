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
	//����ռ临�Ӷ�Ϊ O(n),
	int trap(vector<int>height)
	{	
		int n = height.size();
		vector<int> pre_max(n, 0);
		vector<int> suf_max(n, 0);
		//��ǰ׺
		int ans = 0;
		pre_max[0] = height[0];
		for (int i = 1;i < n;++i)
		{	
			pre_max[i] = max(pre_max[i - 1], height[i]);
		}
		//ǰ׺�����ӡ
		for (int p : pre_max)
		{
			cout << p << " ";
		}
		cout << endl;
		//���׺
		suf_max[n - 1] = height[n - 1];
		for (int j = n - 2;j >= 0;--j)
		{
			suf_max[j] = max(suf_max[j + 1], height[j]);
		}
		//��׺�����ӡ
		for (int q : suf_max)
		{
			cout << q << " ";
		}
		cout << endl;
		//ö��ÿһ��λ��0~n-1 , ���Ϊ1
		int count = 0;
		for (int l = 1;l < n-1;++l)
		{
			if ((height[l] > pre_max[l - 1]) || height[l] > suf_max[l + 1])//û���ݵ�
				continue;
			if (height[l] < pre_max[l - 1] && height[l] < suf_max[l + 1])
				count += (min(pre_max[l - 1], suf_max[l + 1]) - height[l]);
		}
		return count;
	}
	//�ռ��Ż���������������¼ǰ׺����׺�����ֵ O(1)
	int trap_(vector<int>height)
	{
		int n = height.size();
		int left = 0;
		int right = n - 1;
		int premax = 0;
		int sufmax = 0;
		int count = 0;
		//�����������ǣ���ǰ׺�����ֵС�ں�׺�����ֵ����ô���left��ǰ׺�����ֵ-�ô��߶ȣ�����Ҳ��0����֮right�����㷽����ͬ
		while (left <= right)//��Ϊ�غϵ�ҲҪ�����ˮ��
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