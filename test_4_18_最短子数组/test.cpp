#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//����ö��
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
				++len;//Ҳ������ j-i+1
				if (count > target)
				{
					continue;//��Ϊ��������������������϶�Ҳ���󣬲���Ҫ�Ƚ���
				}
				if (count == target)
				{
					if (minlen == 0)
					{
						minlen = len;
					}
					else
					{
						minlen = min(minlen, len);//������С�ĳ���
						if (minlen == 1)
							return 1;
						else
						continue;//�����Ҹ������ˣ�������һ��ö��
					}
				}
			}
		}
		return minlen;
	}
	//������Ϊÿһ����˵��Ǵ�������չ�ģ������ڲ�ѭ���Ҷ˵�ĵ�����ƶ�Ϊn-i,ʱ�临�Ӷ�ΪO(n^2)
	//�޴��Ż�������˵�����count>targetͣ�£��ҵ��Ҷ˵㣬��ʱ���Ҷ˵�֮��ĺͣ�
	int minsubArrayLen_(vector<int> nums, int target)
	{
		int n = nums.size();
		int count = 0;
		int left = 0;
		int right = 0;
		int minlen = n + 1;//len���ֵΪn
		for (int x : nums)
		{
			++right;
			count += x;//��չ�Ҷ˵�
			while (count - nums[left] >= target)//������˵�
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

	cout << "�����Ϊ" << target1 << "�����������ĳ���Ϊ" << test.minsubArrayLen(nums1, target1) << endl;
	cout << "�����Ϊ" << target2 << "�����������ĳ���Ϊ" << test.minsubArrayLen(nums2, target2) << endl;
	cout << "�����Ϊ" << target3 << "�����������ĳ���Ϊ" << test.minsubArrayLen(nums3, target3) << endl;
	cout << endl;
	cout << "�����Ϊ" << target1 << "�����������ĳ���Ϊ" << test.minsubArrayLen_(nums1, target1) << endl;
	cout << "�����Ϊ" << target2 << "�����������ĳ���Ϊ" << test.minsubArrayLen_(nums2, target2) << endl;
	cout << "�����Ϊ" << target3 << "�����������ĳ���Ϊ" << test.minsubArrayLen_(nums3, target3) << endl;

	return 0;
}