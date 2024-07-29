#define _CRT_SECURE_NO_WARNINGS 1
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <iostream>
/*
class Solution
{
public:
	//��һ��д�������α���
	int maxFrequencyElements(std::vector<int>& nums)
	{
		std::unordered_map<int, int> count;//��һ�������Ǽ�ֵ�����ͣ��Ƕ�̬�����ڴ��
		int maxCount = 0;
		for (int num : nums)//������������б� nums �е�ÿһ��Ԫ�أ�������ǰԪ�ظ�ֵ������ num
		{
			maxCount = std::max(maxCount, ++count[num]);
		}
		int ans = 0;
		for (const auto& pair : count)//����������Ż���˫ָ�롣����
		{
			if (pair.second == maxCount)//����������
			{
				ans += pair.second;//���Ƶ��
			}
		}
		return ans;
	}
	
	//�ڶ���д�����Թ�ϣ������и���ans �� maxCount�����α���
	// (�������ڱ���һ�ι�ϣ��Ϳ����ҵ����Ƶ�ʣ���������д�����Զ���)
	
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
			else if (pair.second == maxCount)//����������
			{
				ans += pair.second;//���Ƶ��
			}
		}
		return ans;
	}
	
	//������д����һ�α���
	
	int maxFrequencyElements(std::vector<int>& nums)
	{
		std::unordered_map<int, int> count;
		int maxCount, ans;
		maxCount = ans = 0;
		for (int x : nums)
		{
			int c = ++count[x];//�ؼ���һ�������ƹ�ϣ����
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
	// ���� Solution ����
	Solution solution;

	// ׼����Ҫͳ�Ƶ������б�
	std::vector<int> nums = { 1, 2, 2, 3, 3, 3 ,4 ,4 ,4 };

	// ���� maxFrequencyElements ��������ӡ���
	int result = solution.maxFrequencyElements(nums);
	std::cout << "Sum of most frequent elements: " << result << std::endl;

	return 0;
}
*/

