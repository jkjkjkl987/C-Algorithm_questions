#define _CRT_SECURE_NO_WARNINGS 1
/*问题描述：
	N个赌徒一起决定玩一个游戏：
	游戏刚开始的时候，每个赌徒把赌注放在桌上并遮住，侍者要查看每个人的赌注并确保每个人的赌注都不一样。如果一个赌徒没钱了，则他要借一些筹码，因此他的赌注为负数。假定赌注都是整数。
	最后赌徒们揭开盖子，出示他们的赌注。如果谁下的赌注是其他赌徒中某3个人下的赌注之和，则他是胜利者。如果有多于一个胜利者，则下的赌注最大的赌徒才是最终的胜利者。
	例如，假定赌徒为：Tom、Bill、John、Roger和Bush，他们下的赌注分别为：$2、$3、$5、$7和$12 。因此最终获胜的是Bush（并且没有其他人是胜利者），因为他下的赌注为$12，而其他的人下的赌注之和也等于12：$2+$3+$7=$12。
输入：
输入文件中包含了多组赌徒下的赌注。每组赌注的数据第1行是一个整数n,1<=n<=1000,代表赌徒的个数，然后是他们下的赌注，每个人的赌注占一行，这些赌注各不相同，并且范围是[-536870912,+536870911]。输入文件的最后一行为0，代表输入结束。
输出：
对每组赌注，输出胜利者下的赌注，如果没有解，则输出“no solution”。
样例输入：
5
2 
3 
5 
7 
12

5
2 
16 
64 
256 
1024
0
样例输出：
12
no solution
解题分析：
	本题要求的是一个最大的赌注，满足：它是其他3个赌注的和。假设赌注存放在data数组中，先将n个人的赌注按从小到大的顺序排序。可以采用的思路是枚举，即从最大的赌注开始，看是否存在一个赌注是其他3个不同赌注之和。这个过程需要用四重循环实现。
（1）数据结构
int n;				//每组赌徒的数量，也就是数字的个数；
int data[1000];		//每个赌徒的赌注；
int winner;			//赢家的编号，其赌注是data[winner]
（2）将所有数字按从小到大的顺序排序
利用C语言库函数：
qsort(bet, n, sizeof(int), cmp);
其中cmp为比较因子，按升序排序：
int cmp(const void *a, const void *b)
{
		return (*(int *)a - *(int *)b);
}
（3）枚举，找出赢家的编号
在排序的序列中，从后往前取赢家的序号i，这样计算的结果自然是赌注最大的赢家。三个赌徒的编号，至少有一个编号在赢家的前面（j）。由于存在负数，另外两个赌徒的编号，就有可能在赢家编号的后面。先枚举两个赌徒（j,k），则第三个赌徒的赌注为M= data[i]-data[j]-data[k]，也就是data[i]=data[j]+data[k]+M，因此data[i]满足题目的要求。但同时要保证（data[i]-data[j]-data[k]）既不等于data[i]、data[j]，也不等于data[k]，因此以data[i]为例，如果data[i]-data[j]- data[k]=data[i]，则只要data[j]=-data[k]，所有的data[i]都满足条件。如果能找到，则序号i就是赢家；否则继续查找。直到所有的数字都查找完毕，都没有赢家的话，就是没有解答了。
注意：由于n的值最大可以取到1000，如果n的值取1000，则上述循环中if语句里的比较语句在最坏的情况下要执行1000×1000×1000×1000次，很显然这不是一种好方法。*/
//#include <stdio.h>
//#include <stdlib.h>
//
//const int MAXN = 1001;
//int data[MAXN], n;   //赌徒们下的赌注及赌徒的人数
//
////排序函数的比较因子，升序排序
//int cmp(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//
//int search(int x)  //在data数组中查找x，如果查找到，返回相应的下标，否则返回-1,采用二分搜索法
//{
//	int low = 0, high = n - 1, mid;			//计算左右边界
//	while (low <= high)
//	{
//		mid = (low + high) / 2;			//中间位置
//		if (data[mid] == x) return mid;//找到了，返回位置序号
//		if (data[mid] > x) high = mid - 1;
//		if (data[mid] < x) low = mid + 1;
//	}
//	return -1;						//没有找到
//}
//
////枚举算法，求解答案
//void work()
//{
//	qsort(data, n, sizeof(data[0]), cmp);//从小到大排序
//	int i, j, k, m;
//	//枚举查找
//	for (i = n - 1;i >= 0;i--)					//赢家从序列的后面取，确保是最大的
//	{
//		for (j = 0;j < n;j++);
//		{
//			if (i == j)  continue;
//			for (k = j + 1;k < n;k++)
//			{
//				if (i == k) continue;
//				m = search(data[i] - data[j] - data[k]);
//				//存在第4个人下的赌注为data[i]-data[j]-data[k]
//				//并且这个人不是i,j,也不是k，则i就是胜利者
//				if (m >= 0 && m != i && m != j && m != k)
//				{
//					printf("%d\n", data[i]);
//					return;
//				}
//			}
//		}
//	}
//	printf("no solution\n");
//}
//
//int main()
//{
//	//	freopen("in.txt","r",stdin);
//	while (scanf("%d", &n))
//	{
//		int i;
//		if (n == 0) break;
//		for (i = 0;i < n;i++)
//			scanf("%d", &data[i]);
//		work();
//	}
//	return 0;
//}


//半素数
/*问题描述：
	素数的定义：对于一个大于１的正整数，如果除了１和它本身没有其他的正约数了，那么这个数就称为素数。例如，2,11,67,89是素数，8,20,27不是素数。
	半素数的定义：对于一个大于1的正整数，如果它可以被分解成2个素数的乘积，则称该数为半素数，例如6是一个半素数，而12不是。
	你的任务是判断一个数是否是半素数。
输入：
输入文件中有多个测试数据，每个测试数据包含一个整数N，2<=N<=1,000,000。
输出：
对每个测试数据，如果N是半素数，则输出YES，否则输出NO。
样例输入：
3
4
6
12
样例输出：
No
Yes
Yes
No
解题分析：
本题的意思是输入一个整数N，2≤N≤1000000，判断N是不是半素数。先求出500000以内的素数（因为最小的素数为2），共41538个；对输入的每个整数N，从2开始找它的因子i，如果i和N/i都能在素数表中查找到，则N是半素数。*/
//#include <stdio.h>
//#include <math.h>
//#include <fstream>
//
//int p[500001]; //p[i]为1则表示i为素数
//int primes[41540]; //存储500000以内的每个素数（共41538个）
//int k; //1000000以内素数个数
//
//void compute_prime_table() //筛选法求出500000以内的所有素数
//{
//	int i, j;
//	p[0] = p[1] = 0;
//	for (i = 2;i <= 500000;i++)
//		p[i] = 1; //初始化
//	for (i = 2;i <= 1000;)//对所有小于1000的素数，删除他们的倍数
//	{
//		for (j = i + i;j <= 500000;j += i)
//			p[j] = 0;//删除i的所有倍数
//		for (i++;!p[i];i++);//找下一个素数
//	}
//	for (i = 0, k = 0;i <= 500000;i++)
//	{
//		if (p[i])
//		{
//			primes[k] = i;
//			k++;
//		}
//	}
//}
//
//bool BinSearch(int tab[], int n, int num)//二分查找
//{
//	int low = 0;
//	int high = n - 1;
//	int mid;
//	while (low < high)
//	{
//		mid = (low + high) / 2;
//		if (num <= tab[mid])
//			high = mid;
//		else
//			low = mid + 1;
//	}
//	return(tab[low] == num);
//}
//
//int main()
//{
//	//freopen("test.in", "r", stdin);
//	//freopen("test.out", "w", stdout);
//	int N, sqrtN, flag, i; //N为读入的每个整数
//	compute_prime_table();
//	while (scanf("%d", &N) != EOF)
//	{
//		sqrtN = sqrt(double(N));
//		flag = 0; //标志
//		for (i = 2;i <= sqrtN;i++)
//		{
//			if (N % i == 0)
//			{
//				//在素数表中查找i和N/i
//				if (BinSearch(primes, k, i) && BinSearch(primes, k, N / i))
//				{
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag)
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	return 0;
//}



/*问题描述：
将夜空抽象成二维平面，每个星星一个(X,Y)坐标。这些点可以形成多少正方形？
输入：
多组输入。对于每组数据，第一行是n（1<=n<=1000）表示已知星星数，然后是n行，每行一个坐标值。坐标绝对值小于20000。n=0表示结束。
输出：
对于每组数据输出形成正方形的个数。
样例输入：
4
1 0
0 1
1 1
0 0
9
0 0
1 0
2 0
0 2
1 2
2 2
0 1
1 1
2 1
4
-2 5
3 7
0 0
5 2
0
样例输出：
1
6
1
*/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

const int mod = 100007;
const int maxn = 120009;
struct node
{
    int  x, y, next;
}edge[maxn];
int cnt;
int ans, head[maxn];
int xi[1111], yi[1111];
inline int read()
{
    char ch = getchar(); int x = 0, f = 1;
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
void out(int a)  //代替printf，速度更快，俗称输出挂
{
    if (a > 9)
    {
        out(a / 10);
    }
    putchar(a % 10 + '0');
}
void ins(int x, int y, int h)
{
    h %= mod;
    edge[cnt].x = x;
    edge[cnt].y = y;
    edge[cnt].next = head[h];
    head[h] = cnt++;
}
inline bool cmp(node a, node b)
{
    if (a.x == b.x && a.y == b.y) return 1;
    return 0;
}
bool search(node a, int h)
{
    h %= mod;
    for (int i = head[h];i != -1;i = edge[i].next)
    {
        if (cmp(edge[i], a)) return 1;
    }
    return 0;
}
void init()
{
    mem(edge, 0);
    mem(head, -1);
    mem(xi, 0);
    mem(yi, 0);
    cnt = 0;
    ans = 0;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        init();
        for (int i = 1;i <= n;i++)
        {
            xi[i] = read();yi[i] = read();
            ins(xi[i], yi[i], abs(xi[i] * 1000 + yi[i]));
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                int dty = yi[j] - yi[i], dtx = xi[j] - xi[i];
                node a, b, c, d;
                a.x = xi[i] + dty;a.y = yi[i] - dtx;
                b.x = xi[j] + dty;b.y = yi[j] - dtx;
                c.x = xi[i] - dty;c.y = yi[i] + dtx;
                d.x = xi[j] - dty;d.y = yi[j] + dtx;
                int ha = abs(a.x * 1000 + a.y), hb = abs(b.x * 1000 + b.y),
                    hc = abs(c.x * 1000 + c.y), hd = abs(d.x * 1000 + d.y);
                if (search(a, ha) && search(b, hb)) { ans++; }
                if (search(c, hc) && search(d, hd)) { ans++; }
            }
        }
        out(ans / 4);putchar('\n');
    }
}