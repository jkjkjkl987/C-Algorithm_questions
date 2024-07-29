#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <numeric>//accumulate
#include <functional>
#include <time.h>

using namespace std;

//�ӷǸ����������е�Ԫ���У���ӡ�+�� ��-��ʹ�����ǵĺ͵���target,���ж��������
//�������Ϊ 0 - 1��������
class Solution1
{
public:
	//�ݹ�
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
	//�Ż������仯����
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
	//1:1 ����ɵ���
	int findTargetSumWays_Three(vector<int>& nums, int target)
	{
		// p Ϊ"+"Ԫ�صĺ� 
		// s-pΪҪ���"-"Ԫ�صĺ�
		//��ô�� p-s(s-p)����target
		//����ã�p = (s+t)/2 ,����Ϊp�Ǹ���s+t����Ϊ����������
		target += accumulate(nums.begin(), nums.end(), 0);//s+t
		if (target < 0 || target % 2) return 0;
		target /= 2;
		int i, c;
		int numsSize = nums.size();
		vector<vector<int>> f(numsSize + 1, vector<int>(target + 1, 0));//��¼״̬
		//����һ����СΪ (target + 1) x target �Ķ�ά���飬����ʼ��Ϊ0

		f[0][0] = 1;//��Ϊ�Եݹ�ʽi+1����֮ǰ(i < 0 && c == 0)��Ӧf[0][0]
		for (i = 0;i < numsSize;++i)
		{
			for (c = 0;c <= target;++c)
			{
				if (c < nums[i])
					f[i + 1][c] = f[i][c];//��ζ�����ڵ�i��ֵ����������������ƣ�����ȡ��ת�Ƶ���һ������
				else
					f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
			}
		}
		return f[numsSize][target];//����ԭ����f[n-1][c]��״̬��Ӧ����f[n][c],��Ϊ�±�+1��;
		//ԭ����Ҫ�����״̬�Ǵ�f[0] - f[n-1],���ж�Ӧ��nums[0]~nums[n-1],
		//����+1��nums[0]~nums[n-1]��Ӧ��״̬ת�Ƶ���f[1]~f[n]
	}
		//�ռ��Ż�����Ϊÿһ�μ���i+1��״ֻ̬�õ��� i,���Һ���û���õ� i
		// ���Խ�����Ҫ�����������໥�滻
		//�������飺
	int findTargetSumWays_Four(vector<int>& nums, int target)
	{
		target += accumulate(nums.begin(), nums.end(), 0);//s+t
		if (target < 0 || target % 2) return 0;
		target /= 2;

		int numsSize = nums.size();
		vector<vector<int>> f(2, vector<int>(target + 1, 0)); // ʹ�ö�̬�ڴ������������ά����
		f[0][0] = 1;
		for (int i = 0; i < numsSize; ++i)
			for (int c = 0; c <= target; ++c)
				if (c < nums[i]) f[(i + 1) % 2][c] = f[i % 2][c];
				else f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]];
		return f[numsSize % 2][target];
	};
	//�ռ��Ż���һ������
	int findTargetSumWays_Five(vector<int>& nums, int target) {
		target += accumulate(nums.begin(), nums.end(), 0);
		if (target < 0 || target % 2) return 0;
		target /= 2;

		vector<int> f(target + 1, 0);

		f[0] = 1;
		for (int x : nums)
			for (int c = target; c >= x; --c)//����Ҫע�������Ҫ�Ӻ���ǰö�٣�����������ǰ���ǵ�Ҫ�����ֵ
				//����c<x�����Ϊ��f[c] =f[c]���ʿ���ʡ��
				//����ֻ��Ҫ����c>=x �������
				f[c] += f[c - x];//���ƹ�ʽ�򻯣���һ��ά�ȿ���ʡ��
		return f[target];
	};
};

//����һЩӲ�ҵ����飬��������Ӳ��ʹ����ֵ�͵���amount�������ظ�ȡ��ͬ��Ӳ�ң����ҳ���Ҫ��С��coin����
//��ȫ��������: 
class Solution2
{
public:   
	int coinChange_One(vector<int>& coin, int amount)
	{	
		//����ֵ��Ӳ�Ҹ�����ֻ��ѡ���˲Ż�+1
		int n = coin.size();
		function<int(int, int)> dfs = [&](int i, int c) -> int
			{
				if (i < 0)
				{
					if (c == 0)return 0;//û��Ӳ�ҿ���ѡ�ˣ������Ƿ���1
					else return INT_MAX;
				}
				if (coin[i] > c)
					return dfs(i - 1, c);
				return min(dfs(i - 1, c), dfs(i, c - coin[i]) + 1);
			};
		int res = dfs(n - 1, amount);
		if (res == INT_MAX)//û�кϷ��ķ���
			return 0;
		else
		return res;
	}

	//����ɵ��ƣ�
	int coinChange_Two(vector<int>& coin, int amount)
	{
		//����ֵ��Ӳ�Ҹ�����ֻ��ѡ���˲Ż�+1
		int n = coin.size();
		vector<vector<int>> f(n + 1, vector<int>(amount + 1, INT_MAX));
		f[0][0] = 0;//���Ƶĳ�ʼֵ���ǵݹ�ı߽�
		for (int i = 0;i < n;++i)
		{
			for (int c = 0;c <= amount;++c)
			{
				if (c < coin[i])//����ѡ��
					f[i + 1][c] = f[i][c];
				else//����ѡ��
					f[i + 1][c] = min(f[i][c], f[i + 1][c - coin[i]] + 1);
			}
		}
		if (f[n][amount] == INT_MAX)//û�кϷ��ķ���
			return -1;
		else
			return f[n][amount];
	}

	//�ռ��Ż�����������
	int coinChange_Three(vector<int>& coins, int amount)
	{
		//����ֵ��Ӳ�Ҹ�����ֻ��ѡ���˲Ż�+1
		int n = coins.size();
		vector<vector<int>> f(2, vector<int>(amount + 1, INT_MAX));
		f[0][0] = 0;//���Ƶĳ�ʼֵ���ǵݹ�ı߽�
		for (int i = 0;i < n;++i)
		{
			for (int c = 0;c <= amount;++c)
			{
				if (c < coins[i])//����ѡ��
					f[(i + 1) % 2][c] = f[i % 2][c];
				else//����ѡ��
					f[(i + 1) % 2][c] = min(f[i % 2][c], f[(i + 1) % 2][c - coins[i]] + 1);
			}
		}
		if (f[n % 2][amount] == INT_MAX)//û�кϷ��ķ���
			return -1;
		else
			return f[n % 2][amount];
	}
	//�ռ��Ż���һά����
	int coinChange_Four(vector<int>& coins, int amount)
	{
		//����ֵ��Ӳ�Ҹ�����ֻ��ѡ���˲Ż�+1
		int n = coins.size();
		vector<int> f(amount + 1, INT_MAX);
		f[0] = 0;//���Ƶĳ�ʼֵ���ǵݹ�ı߽�
		for (int i = 0;i < n;++i)
		{
			for (int c = coins[i];c <= amount;++c)
			{
				if (c >= coins[i])
					f[c] = min(f[c], f[c - coins[i]] + 1);
			}
		}
		if (f[amount] == INT_MAX)//û�кϷ��ķ���
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

	//�ݹ�
	int time1 = clock();
	cout << "ʹ�����ݵ���ϱ��ʽ=" << target << "���������Ϊ��" << test.findTargetSumWays_One(nums, target) << endl;
	int time2 = clock();
	cout << time2 - time1 << endl;
	//�ݹ�->���仯����
	time1 = clock();
	cout << "ʹ�����ݵ���ϱ��ʽ=" << target << "���������Ϊ��" << test.findTargetSumWays_Two(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	//���ƣ���ά���飩
	time1 = clock();
	cout << "ʹ�����ݵ���ϱ��ʽ=" << target << "���������Ϊ��" << test.findTargetSumWays_Three(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	//����->�ռ��Ż�����������
	time1 = clock();
	cout << "ʹ�����ݵ���ϱ��ʽ=" << target << "���������Ϊ��" << test.findTargetSumWays_Four(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	//����->�ռ��Ż���һά����
	time1 = clock();
	cout << "ʹ�����ݵ���ϱ��ʽ=" << target << "���������Ϊ��" << test.findTargetSumWays_Five(nums, target) << endl;
	time2 = clock();
	cout << time2 - time1 << endl;
	*/

	Solution2 test_;
	int amount;
	vector<int> coin = { 1,2,5 };
	cin >> amount;
	//�ݹ�
	cout << "���ɼ�ֵΪ" << amount << "������Ӳ������Ϊ��" << test_.coinChange_One(coin, amount) << endl;
	//����
	cout << "���ɼ�ֵΪ" << amount << "������Ӳ������Ϊ��" << test_.coinChange_Two(coin, amount) << endl;
	//��������
	cout << "���ɼ�ֵΪ" << amount << "������Ӳ������Ϊ��" << test_.coinChange_Three(coin, amount) << endl;
	//һά����
	cout << "���ɼ�ֵΪ" << amount << "������Ӳ������Ϊ��" << test_.coinChange_Four(coin, amount) << endl;

	return 0;
}