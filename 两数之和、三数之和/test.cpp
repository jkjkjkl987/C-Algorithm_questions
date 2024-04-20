#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stack>

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
	//����֮��
	void Two_add(vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		//vector<vector<int>> List(10, vector<int>(3, -1));
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
	//����֮��
	int Three_add(vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		//vector<vector<int>> List(10, vector<int>(3, -1));

		sort(nums.begin(), nums.end());//greater<int>()Ϊ����

		for (int i = left;i <= n - 3;++i)
		{
			int j = i + 1;
			int k = right;
			if (i > 0 && nums[i] == nums[i - 1])//��һ����ѡ����ˣ�����
				continue;
			//�Ż�����Ϊ����������տ�ʼ��3����������target�������û�п��ܳ���С�ڵ��ڵ�����ˣ�����ͬ��
			if ((nums[i] + nums[i + 1] + nums[i + 2]) > target)
				return -1;
			if ((nums[i] + nums[n - 1] + nums[n - 2]) < target)
				continue;//��Ϊ������ܻ��и����num[i]

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
		return {};
	}
};

int main()
{
	Solution test;
	int target;
	vector<int> nums = { 8 ,2 ,-1 ,1 ,3 ,-1 ,4 ,5 ,9 ,0 ,4 ,1 };// 0 -1 -1 1 1 2 3 4 4 5 8 9
	cout << "������ͣ�";
	cin >> target;//8
	// -1 9
	//  0 8
	//  3 5
	//  4 4
	//test.Two_add(nums, target);
	//cout << "����֮�͵���" << target << "�������" << test.Two_add(nums, target) << endl;

	
	//-1  1  8
	//-1  4  5
	// 0 -1  9
	// 0  3  5
	// 0  4  4
	// 1  2  5
	// 1  3  4
	 
	test.Three_add(nums, target);
	//cout << "����֮�͵���" << target << "�������" << test.Three_add(nums, target) << endl;

	return 0;
}