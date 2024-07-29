#define _CRT_SECURE_NO_WARNINGS 1

//codeforces ���
#define debug1 1 //vector<vector<int>>�汾
//#define debug2 2 //vector<pair<int,int>>�汾
#ifdef debug1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
template<class T>
class myComparator
{
public:
	bool operator()(const T& a, const T& b) const
	{
		return a[0] < b[0];
	}
};
long long n = 2000000, r = 1000000000;
//vector<vector<int>> nums(2000000, vector<int>(2));
static bool g(long long t, vector<vector<int>>& nums)
{
	long long x = 0, y1 = 0, y2 = 0;
	for (int i = 0; i < n; ++i)
	{
		y1 = nums[i][0] - (t - nums[i][1]);
		y2 = nums[i][0] + (t - nums[i][1]);
		if (x >= y1)
			x = x > y2 ? x : y2;
	}
	/*for (auto& a:nums)
	{
		y1 = a[0] - (t - a[1]);
		y2 = a[0] + (t - a[1]);
		if (x >= y1)
			x = x > y2 ? x : y2;
	}*/
	if (x < r)
		return false;
	return true;
}
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//scanf("%lld%lld", &n, &r);
	//cin >> n >> r;
	FILE* pf = nullptr;
	pf = fopen("test.txt", "w");
	for (int i = 0; i < 2 * n; i++)
	{
		fprintf(pf, "%d ", 44 * (rand() / 53) + 32);
	}
	fclose(pf); pf = nullptr;
	int i1 = clock();
	vector<vector<int>> nums(n, vector<int>(2));
	int i2 = clock(); printf("����������ʱ��%d\n", i2 - i1);/////////////////////
	long long tmp = 0;
	long long maxt = 0, maxx = 0;
	pf = fopen("test.txt", "r");
	for (int i = 0; i < n; ++i)
	{
		fscanf(pf, "%lld", &tmp);
		//cin >> tmp;
		nums[i][0] = tmp;
		if (maxx < tmp)
			maxx = tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		fscanf(pf, "%lld", &tmp);
		//cin >> tmp;
		nums[i][1] = tmp;
		if (maxt < tmp)
			maxt = tmp;
	}
	int i3 = clock();  printf("��ȡ������ʱ��%d\n", i3 - i2);////////////////
	fclose(pf); pf = nullptr;
	sort(nums.begin(), nums.begin() + n, myComparator<vector<int>>());
	int i4 = clock();  printf("������ʱ��%d\n", i4 - i3);/////////////////
	long long l1 = 0, r1 = 2 * max(maxt, max(maxx, r)), mid = 0;
	while (l1 < r1)
	{
		mid = (l1 + r1) / 2;
		if (g(mid, nums))
			r1 = mid;
		else
			l1 = mid + 1;
	}
	//cout << r1;
	printf("�𰸣�%lld\n", r1);
	int i5 = clock();  printf("���ֲ�����ʱ��%d\n", i5 - i4);/////////////////////
	return 0;
}
#endif
#ifdef debug2
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
template<class T>
class myComparator
{
public:
	bool operator()(const T& a, const T& b) const
	{
		return a.first < b.first || (a.first == b.first && a.second > b.second);
	}
};
long long n = 2000000, r = 1000000000;
static bool g(long long t, vector<pair<long long, long long>>& nums)
{
	long long x = 0, y1 = 0, y2 = 0;
	for (int i = 0; i < n; ++i)
	{
		y1 = nums[i].first - (t - nums[i].second);
		y2 = nums[i].first + (t - nums[i].second);
		if (x >= y1)
			x = x > y2 ? x : y2;
	}
	if (x < r)
		return false;
	return true;
}
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long tmp = 0, maxt = 0, maxx = 0;
	//scanf("%d%d", &n, &r);
	FILE* pf = nullptr;
	pf = fopen("test.txt", "w");
	for (int i = 0; i < 2 * n; i++)
	{
		fprintf(pf, "%d ", rand());
	}
	fclose(pf); pf = nullptr;
	int i1 = clock();
	vector<pair<long long, long long>> nums1(n);
	int i2 = clock(); printf("����������ʱ��%d\n", i2 - i1);
	pf = fopen("test.txt", "r");
	for (int i = 0; i < n; ++i)
	{
		fscanf(pf, "%lld", &tmp);
		//cin >> tmp;
		nums1[i].first = tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		fscanf(pf, "%lld", &tmp);
		nums1[i].second = tmp;
	}
	int i3 = clock(); printf("��ȡ������ʱ��%d\n", i3 - i2);
	fclose(pf); pf = nullptr;
	//int t1 = clock();
	sort(nums1.begin(), nums1.begin() + n, myComparator<pair<long long, long long>>());
	int i4 = clock(); printf("������ʱ��%d\n", i4 - i3);
	long long l1 = 0, r1 = 2000000000, mid = 0;
	while (l1 < r1)
	{
		mid = (l1 + r1) / 2;
		if (g(mid, nums1))
			r1 = mid;
		else
			l1 = mid + 1;
	}
	printf("%d\n", r1);
	int i5 = clock(); printf("���ֲ�����ʱ��%d\n", i5 - i4);
	return 0;
}
#endif



//ʹ��ƽ���������vector<vector<int>>�Ĺ���

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// ����һ��2x3�Ķ�ά����
	vector<vector<int>> original_array = {
		{1, 2, 3},
		{4, 5, 6}
	};

	// ����ά����չ��Ϊһά����
	vector<int> flattened_array;
	for (const auto& row : original_array) {
		for (int element : row) {
			flattened_array.push_back(element);
		}
	}

	// ʹ��չ�����һά����������ԭʼ�Ķ�ά����
	int rows = original_array.size();
	int cols = original_array[0].size();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			// ������չ�����һά�����е�����
			int index = i * cols + j;
			// ����ԭʼ��ά�����е�Ԫ��
			cout << "ԭʼ[" << i << "][" << j << "]: " << original_array[i][j] << ", չ����[" << index << "]: " << flattened_array[index] << endl;
		}
	}

	return 0;
}
