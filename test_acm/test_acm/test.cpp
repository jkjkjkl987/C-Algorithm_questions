#define _CRT_SECURE_NO_WARNINGS 1

/*

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define MAXS 1000000

#include <iostream>
#include <functional>



class SolutionA
{
public:
    bool find_eight(char s[])
    {
        // 获取字符数组长度
        int n = strlen(s);
        unordered_map<int, int>hash;

        //存放字符串信息
        int ch;
        for (int i = 0;i < n;++i)
        {
            ch = s[i] - '0';
            ++hash[ch];
        }
        int start;
        int x1, y1, z1;
        if (n > 4 || n == 3)
        {
            start = 304;
            while (start < 1000)//寻找后 3位
            {
                x1 = start / 100;//百
                y1 = (start / 10) % 10;//十
                z1 = start % 10;//个
                if (hash.count(x1))
                {
                    --hash[x1];
                }
                else
                {
                    start += 8;
                    continue;
                }

                if (hash.count(y1))
                {    
                    --hash[y1];
                }
                else
                {
                    start += 8;
                    ++hash[x1];
                    continue;
                }

                if (hash.count(z1))
                {        
                    return true;
                }
                else
                {
                    start += 8;
                    ++hash[y1];
                    continue;
                }

            }
        }
        else if(n==2)//寻找后2位 是否能组合成8的倍数
        {
            start = 16;
            while (start < 104)
            {

                x1 = start / 100;
                y1 = (start / 10) % 10;
                if (hash.count(x1))
                {
                    --hash[x1];
                }
                else
                {
                    start += 8;
                    continue;
                }

                if (hash.count(y1))
                {
                    --hash[y1];
                    return true;
                }
                else
                {
                    start += 8;
                    ++hash[x1];
                    continue;
                }
            }
        }
        else//1位
        {
            if (hash.count(8))
                return true;
            return false;
        }
        return false;
    }
};

int main()
{
    SolutionA test;
    char A[MAXS];
    std::cout << "请输入字符数组：" << std::endl;
    // 从标准输入读取字符数组
    fgets(A, MAXS, stdin);
    cout << (test.find_eight(A) ? "Yes" : "No") << endl;
    return 0;
}

*/

// #define rowmax 20
// #define colmax 20

//class SolutionD
//{
//public:
//	int judgetrible(int N, int num[][colmax])
//	{
//		int count = 0;
//		//hang
//		for (int i = 0;i < N;++i)
//		{
//			count = 0;
//			for (int j = 0;j < colmax;++j)
//			{
//				if (num[i][j] == 1)
//					++count;
//				if (count == 3)
//					return 1;
//			}
//		}
//		//lie
//		for (int j = 0;j < colmax;++j)
//		{
//			int count = 1;
//			for (int i = 0;i < N;++i)
//			{
//				if (num[i][j] == 1)
//					++count;
//					if (count == 3)
//						return 1;
//			}
//		}
//		for (int i = 0;i < 20;++i)
//		{
//			for (int j = 0;j < colmax;++j)
//			{
//				int n = colmax - j - 1;
//				int m = rowmax - i - 1;
//				int t = min(n, m);
//				if (num[n][m] == 1)
//					count++;
//				--n;
//				--m;
//				if (count == 3)
//					return 1;
//			}
//		}
//		return -1;
//	}
//};
//
//
//class Solutionj
//{
//public:
//
//};
//string str;
//
//int main()
//{
//	Solutiond test;
//	int N = 0;
//	cin >> N;
//	int x, y;
//	int num[][colmax] = { -1 };
//	int res = 0;
//	int n = N;
//	while (n-- > 0)
//	{
//		cin >> x >> y;
//		num[x][y] = 1;
//	}
//	res = test.judgetrible(N, num);
//	if (res == 1)
//		cout << "Yes" << endl;
//	else
//	cout << "No" << endl;
//
//	getchar();
//	getchar();
//	return 0;
//}
//
//class Solution
//{
//public:
//	unsigned long long count(unsigned long long x, unsigned long long y)
//	{
//		// 使用数学公式直接计算 x 和 y 之间整数的和
//		unsigned long long n = y - x + 1;
//		unsigned long long res = (n * (x + y)) / 2;
//		return res;
//	}
//};
////
////
//int main()
//{
//	int N;
//	cin >> N;
//	Solution test;
//	unsigned long long x, y;
//	unsigned long long COUNT = 0;
//	while (N--)
//	{
//		cin >> x >> y;
//		COUNT += test.count(x, y);
//	}
//	cout << COUNT << endl;
//	return 0;
//}


#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <algorithm>
#include <unordered_map>
using namespace std;

class SolutionI
{
public:
    unsigned long long count(unsigned long long psa)
    {
        unsigned long long counttime = 0;

        if (psa % 6 == 0)
            return (psa / 6) * 15;
        if (psa % 8 == 0)
            return (psa / 8) * 20;
        if ((psa % 10) == 0)
        {
            return (psa / 10) * (25);
        }

        if (psa / 10 > 0)
        {
            counttime += 25 * (psa / 10);
            psa %= 10;
        }

        if ((psa % 8) == 0)
        {
            return  counttime += (psa / 8) * (20);
        }

        if ((psa / 8) > 0)
        {
            counttime += 20 * (psa / 8);
            psa %= 8;
        }


        if (psa < 6)
            return counttime += 15;
        else
            return 30;
		return counttime;
	}
};

int main()
{
    int N;
    cin >> N;
    unsigned long long psa = 0;  // 将 psa 的类型修改为 long int
    SolutionI test;
    unsigned long long arr[100] = { 0 };
    int start = 0;
    int n = N;
    while (N--)
    {
        scanf("%llu", &psa);
        arr[start] = test.count(psa);
        start++;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }
    return 0;
}



//class Solution
//{
//public:
//	int find(int num[][10], int n)
//	{
//		for (int i = 0;i < 10;++i)
//		{	
//			for (int j = 0;j < n;++j)
//			{
//
//			}
//
//		}
//	}
//
//};