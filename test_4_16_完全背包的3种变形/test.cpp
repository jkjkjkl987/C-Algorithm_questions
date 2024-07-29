#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;


class Solution
{
public:
	//Ŀ��ͣ�����Ϊtarget
	//���ڵݹ��еķ�������Ϊi<0,c<=0,��
	int Findleastnum(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//�����������Ҫ�����p����������
		target /= 2;
		vector<int> f(target + 1, 0);
		f[0] = 1;//��ʼֵ��ʾ�ݹ�ı߽�����Ϊc<=0ʱ������1
		for (int x : nums)
		{
			for (int c = target;c >= 0;--c)
			{
				f[c] = f[c] + f[max(c - x, 0)];//���򣬽�����c<x�ķ����ۼӵ�f[0]
				//����target =0;�����㣺��һ�� f[target] = 1 + 1 = 2; 
				// �ڶ��� f[target] = 2 + 2; 
				// ������ f[target] = 4 + 4;
				//		  f[0] = 16 ���� ����> f[0] = 2^n; 
				// Ҳ���ö�Ӧ�� n������target=0ʱû��Լ����������ѡ���߲�ѡ����2^n��ѡ��
			}
		}
		return f[target];//��ʾ �����е�x��ѡ����ʹ������c������Ϊ0��Ҳ���ǿ���ѡ��������ֵ����c<=0
	}
	//�ݹ�
	int Findleastnum_(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//�����������Ҫ�����p����������
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
	//Ŀ��ͣ�����Ϊtarget
	//���ڵݹ��еķ�������Ϊi<0��c>=0,��ӵݹ鵽���ƹ�ʽ��һά����ʱ
	int Findmostnum(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//�����������Ҫ�����p����������
		target /= 2;
		vector<int> f(target + 1, 1);
		//��ʼֵ��ʾ�ݹ�ı߽�����Ϊc>=0ʱ������1,0<=����,��ζ��ѡ��������û����������c
		for (int x : nums)
		{
			for (int c = target;c >= x;--c)
			{
				f[c] = f[c] + f[c - x];//����
			}
		}
		return f[target];
	}
	
	//�ݹ�
	int Findmostnum_(vector<int>& nums, int target)
	{
		int n = nums.size();
		int s = accumulate(nums.begin(), nums.end(), 0);
		target += s;
		//�����������Ҫ�����p����������
		target /= 2;

		function<int(int, int)>dfs = [&](int i, int c) -> int
			{
				if (i < 0)
				{
					if (c >= 0)return 1;else return 0;
				}
				if (c < nums[i])
					return dfs(i - 1, c);
				return dfs(i - 1, c) + dfs(i - 1, c - nums[i]);//��ѡ��ѡ
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
	cout << "Ŀ���������" << target << "���������Ϊ��" << test.Findleastnum(nums, target) << endl;
	cout << "Ŀ���������" << target << "���������Ϊ��" << test.Findleastnum_(nums, target) << endl;

	cout << "Ŀ���������" << target << "���������Ϊ��" << test.Findmostnum(nums, target) << endl;
	cout << "Ŀ���������" << target << "���������Ϊ��" << test.Findmostnum_(nums, target) << endl;

	return 0;
}