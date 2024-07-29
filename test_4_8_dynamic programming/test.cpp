#define _CRT_SECURE_NO_WARNINGS 1
/*问题描述：
7
3   8
8   1   0
2   7   4   4
4   5   2   6   5
上图给出了一个数字三角形。从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。
注意：路径上的每一步只能从一个数走到下一层上和它最近的左边的那个数或者右边的那个数。

输入：
输入的第一行是一个整数N (1 < N <= 100)，给出三角形的行数。下面的N行给出数字三角形。数字三角形上的数的范围都在0和100之间。
输出：
输出最大的和。
样例输入：
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
样例输出：
30
解题分析：
这道题目可以用递归的方法解决。基本思路是：
以D(r, j) 表示第r行第j个数字(r，j都从1开始算)，以MaxSum(r, j) 代表从第r 行的第j个数字到底边的最佳路径的数字之和，则本题是要求MaxSum(1,1)。
从某个D(r,j)出发，显然下一步只能走D(r+1,j)或者D(r+1,j+1) 。如果走D(r+1,j)，那么得到的MaxSum(r,j) 就是MaxSum(r+1,j) + D(r,j) ；如果走D(r+1,j+1) ，那么得到的MaxSum(r,j) 就是MaxSum(r+1,j+1) + D(r,j) 。所以，选择往哪里走，就看MaxSum(r+1, j)和MaxSum(r+1,j+1)哪个更大了。*/
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#define MAX_NUM 100
//int D[MAX_NUM + 10][MAX_NUM + 10];
//int N;
//int Max_D[MAX_NUM + 10][MAX_NUM + 10];
//
//int MaxSum(int r, int j)
//{
//	/*if (r == N)
//		return D[r][j];
//	int nSum1 = MaxSum(r + 1, j);
//	int nSum2 = MaxSum(r + 1, j + 1);
//	if (nSum1 > nSum2)
//		return nSum1 + D[r][j];
//	return nSum2 + D[r][j];*/
//
//	if (r == N)
//		return D[r][j];
//	if (Max_D[r + 1][j] = -1)
//		Max_D[r + 1][j] = MaxSum(r + 1, j);
//	if (Max_D[r + 1][j] = -1)
//		Max_D[r + 1][j + 1] = MaxSum(r + 1, j + 1);
//	if (Max_D[r + 1][j] > Max_D[r + 1][j + 1])
//		return Max_D[r + 1][j] + D[r][j];
//	return Max_D[r + 1][j + 1] + D[r][j];
//	//现在不会重复计算已经计算过的值了
//}
////可以进行优化，将已经被计算过的位置跳过
//int main()
//{
//	int m, i, j;
//	while (scanf("%d", &N) != EOF)
//	{	
//		memset(Max_D, -1, N);//优化的位置，
//		for (i = 1; i <= N; i++)
//			for (j = 1; j <= i; j++)
//				scanf("%d", &D[i][j]);
//		printf("%d\n", MaxSum(1, 1));
//	}
//}



/*问题描述：
一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。对于给定的一个序列(a1, a2, ..., aN)，我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，这里1 <= i1 < i2 < ... <iK <= N。比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8).
你的任务，就是对于给定的序列，求出最长上升子序列的长度。
输入：
输入的第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。
输出：
最长上升子序列的长度。 
样例输入1：
7
1 7 3 5 9 4 8
样例输出1：
4

样例输入2：
6
2 3 4 1 6 5
样例输出2：
4

样例输入3：
9
1 2 3 9 4 5 6 7 8
样例输出3：
8

解题思路：
	如何把这个问题分解成子问题呢？经过分析，发现“求以ak（k=1, 2, 3…N）为终点的最长上升子序列的长度”是个好的子问题――这里把一个上升子序列中最右边的那个数称为该子序列的“终点”。虽然这个子问题和原问题形式上并不完全一样，但是只要这N个子问题都解决了，那么这N个子问题的解中，最大的那个就是整个问题的解。
由上所述的子问题只和一个变量相关，就是数字的位置。因此序列中数的位置k就是“状态”，而状态 k对应的“值”，就是以ak做为“终点”的最长上升子序列的长度。这个问题的状态一共有N个。状态定义出来后，转移方程就不难想了。假定MaxLen (k)表示以ak做为“终点”的最长上升子序列的长度，那么：
MaxLen (1) = 1
MaxLen (k) = Max { MaxLen (i)：1<i < k 且 ai < ak 且 k≠1 } + 1
这个状态转移方程的意思就是，MaxLen(k)的值，就是在ak左边，“终点”数值小于ak，且长度最大的那个上升子序列的长度再加1。因为ak左边任何“终点”小于ak的子序列，加上ak后就能形成一个更长的上升子序列。
实际实现的时候，可以不必编写递归函数，因为从 MaxLen(1)就能推算出MaxLen(2)，
有了MaxLen(1)和MaxLen(2)就能推算出MaxLen(3)……*/

//#include <stdio.h>
//#include <memory.h>
//
//#define MAX_N 1000
//
//int b[MAX_N + 10];
//int aMaxLen[MAX_N + 10];
//
//main()
//{
//	int N, i, j;
//	while (~scanf("%d", &N))
//	{
//		for (i = 1;i <= N;i++)
//			scanf("%d", &b[i]);
//		aMaxLen[1] = 1;
//		for (i = 2; i <= N; i++)
//		{ //每次求以第i个数为终点的最长上升子序列的长度
//			int nTmp = 0; //记录满足条件的，第i个数左边的上升子序列的最大长度
//			for (j = 1; j < i; j++)
//			{ //察看以第j个数为终点的最长上升子序列
//				if (b[i] > b[j])
//				{
//					if (nTmp < aMaxLen[j])
//						nTmp = aMaxLen[j];
//				}
//			}
//			aMaxLen[i] = nTmp + 1;
//		}
//		int nMax = -1;
//		for (i = 1;i <= N;i++)
//			if (nMax < aMaxLen[i])
//				nMax = aMaxLen[i];
//		printf("%d\n", nMax);
//	}
//	return 0;
//}


/*"Help Jimmy" 

场景中包括多个长度和高度各不相同的平台。地面是最低的平台，高度为零，长度无限。
Jimmy老鼠在时刻0从高于所有平台的某处开始下落，它的下落速度始终为1米/秒。当Jimmy落到某个平台上时，游戏者选择让它向左还是向右跑，它跑动的速度也是1米/秒。当Jimmy跑到平台的边缘时，开始继续下落。Jimmy每次下落的高度不能超过MAX米，不然就会摔死，游戏也会结束。
设计一个程序，计算Jimmy到地面时可能的最早时间。
输入：
第一行是测试数据的组数t（0 <= t <= 20）。每组测试数据的第一行是四个整数N，X，Y，MAX，用空格分隔。N是平台的数目（不包括地面），X和Y是Jimmy开始下落的位置的横竖坐标，MAX是一次下落的最大高度。接下来的N行每行描述一个平台，包括三个整数，X1[i]，X2[i]和H[i]。H[i]表示平台的高度，X1[i]和X2[i]表示平台左右端点的横坐标。1<= N <= 1000，-20000 <= X, X1[i], X2[i] <= 20000，0 < H[i] < Y <= 20000（i = 1..N）。所有坐标的单位都是米。
Jimmy 的大小和平台的厚度均忽略不计。如果Jimmy 恰好落在某个平台的边缘，被视为落在平台上。所有的平台均不重叠或相连。测试数据保Jimmy一定能安全到达地面。
输出：
对输入的每组测试数据，输出一个整数，Jimmy到地面时可能的最早时间。
样例输入：
1
3 8 17 20
0 10 8
0 10 13
4 14 3
样例输出：
23
解题思路：
	此题目的“子问题”是什么呢？Jimmy跳到一块板上后，可以有两种选择，向左走，或向右走。走到左端和走到右端所需的时间，是很容易算的。如果我们能知道，以左端为起点到达地面的最短时间，和以右端为起点到达地面的最短时间，那么向左走还是向右走，就很容易选择了。因此，整个问题就被分解成两个子问题，即Jimmy所在位置下方第一块板左端为起点到地面的最短时间，和右端为起点到地面的最短时间。这两个子问题在形式上和原问题是完全一致的。将板子从上到下从1开始进行无重复的编号(越高的板子编号越小，高度相同的几块板子，哪块编号在前无所谓)，那么，和上面两个子问题相关的变量就只有板子的编号，所以，本题目的“状态”就是板子编号，而一个“状态”对应的“值”有两部分，是两个子问题的解，即从该板子左端出发到达地面的最短时间，和从该板子右端出发到达地面的最短时间。不妨认为Jimmy开始的位置是一个编号为0，长度为0 的板子，假设LeftMinTime(k)表示从k号板子左端到地面的最短时间，RightMinTime(k)表示从k号板子右端到地面的最短时间，那么，求板子k左端点到地面的最短时间的方法如下：
if (板子k左端正下方没有别的板子) 
{
if(板子k的高度h(k)大于Max)
LeftMinTime(k) = ∞;
else
LeftMinTime(k) = h(k);
}
else if(板子k左端正下方的板子编号是m )
LeftMinTime(k) = h(k)-h(m) + Min( LeftMinTime(m) + Lx(k)-Lx(m), RightMinTime(m) + Rx(m)-Lx(k));
}
上面，h(i)就代表i号板子的高度，Lx(i)就代表i号板子左端点的横坐标，Rx(i)就代表i号板子右端点的横坐标。那么h(k)-h(m)当然就是从k号板子跳到m号板子所需要的时间，Lx(k)-Lx(m)就是从m号板子的落脚点走到m号板子左端点的时间，Rx(m)-Lx(k)就是从m号板子的落脚点走到右端点所需的时间。
求RightMinTime(k)的过程类似。
不妨认为Jimmy开始的位置是一个编号为0，长度为0的板子，那么整个问题就是要求LeftMinTime(0)。
输入数据中，板子并没有按高度排序，所以程序中一定要首先将板子排序。*/

//#include <cstdio>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//#define INF 1000000
//int k, max, n;
//int minleft[1010];//动态规划每个板子左侧的下落最短时间
//int minright[1010];//动态规划每个板子右侧的下落最短时间
////板子的信息
//struct platform
//{
//    int left;
//    int right;
//    int high;
//}p[1010];
//
//int cmp(const void* a, const void* b)
//{
//    return ((struct platform*)b)->high - ((struct platform*)a)->high;
//}
//int min(int k, bool left)
//{
//    int x;
//    if (left)//左
//    {
//        x = p[k].left;
//    }
//    else//右
//    {
//        x = p[k].right;
//    }
//    int y = p[k].high;//高
//    // k为当前板子编号 i为下一个板子编号（或者直接落地）
//    int i;
//    for (i = k + 1;i <= n;i++)//找到可以落到板子编号
//    {
//        if (p[i].left <= x && p[i].right >= x)
//            break;
//    }
//    if (i == n + 1)//下面没有板，两种情况，过高和正常落地
//    {
//        if (y > max)
//            return INF;
//        else
//            return y;
//    }
//    else if (y - p[i].high > max)//有板子但是过高
//        return INF;
//    //上面板子到目标板子的下落时间+到边界时间，垂直下落和水平移动同属于到 i 号板子的时间范畴
//    int lefttime = y - p[i].high + x - p[i].left;
//    int righttime = y - p[i].high + p[i].right - x;
//
//    if (minleft[i] == -1)//动态规划
//        minleft[i] = min(i, true);
//    if (minright[i] == -1)
//        minright[i] = min(i, false);
//
//    lefttime += minleft[i];
//    righttime += minright[i];
//
//    return lefttime < righttime ? lefttime : righttime;
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    for (int a = 0;a < t;a++)
//    {
//        memset(minleft, -1, sizeof(minleft));
//        memset(minright, -1, sizeof(minright));
//        int x, y;
//        scanf("%d%d%d%d", &n, &x, &y, &max);
//        p[0].left = x;
//        p[0].right = x;
//        p[0].high = y;
//        //n个板子
//        for (int i = 1;i <= n;i++)//【注意加上开头一共是n+1个！】
//        {
//            scanf("%d%d%d", &p[i].left, &p[i].right, &p[i].high);
//        }
//        qsort(p, n + 1, sizeof(platform), cmp);//【一定要排序。。。而且一共是n+1个！】
//
//        printf("%d\n", min(0, true));
//
//    }
//
//    return 0;
//}



/*将整数n分成k份，且每份不能为空，任意两种分法不能相同（不考虑顺序）。
例如：n=7，k=3，下面三种分法被认为是相同的。
1,1,5；1,5,1；5,1,1；问有多少种不同的分法。
输入：
每组数据由一行上的2个整数n，k构成（6<n≤200,2≤k≤6）。
输出：
对每组测试数据，输出不同的分法整数。
样例输入：
7 3
样例输出：
4
说明：
样例中的4种分法为1,1,5；1,2,4；1,3,3；2,2,3。
解题思路：
对整个数n，其划分的基本思想是将n分为两部分：m+(n-m)，其中m是小于n的正整数。那么可以继续将m分解为k1份，同时也将n-m分解为k2=k-k1份。
以数n=7为例。将m从1开始一次考查。
首先，取m=1,7=1+6；m已不可分，此时6需要分为2份，有6=1+5=2+4=3+3；合起来有3种分解形式，1+（1+5）=1+（2+4）=1+（3+3）。
其次，取m=2,7=2+5；如果将2分为2份，5不可再分，此时有一种分解（1+1）+5，与前面m=1时的一种分解1+（1+5）是相同的。为保证分解的方便处理，这里m=2应不再分解而将5分为2份。于是有7=（1+1）+5=2+（1+4）=2+（2+3）。不相同的分法有4种。
现在，对n=m+（n-m），在具体实施分解时用深度优先算法，对数m与n-m用回溯递归方法搜索。
以下参考程序中，dep为当前已试放的数的个数或层次，prev为试放的数，n为当前剩余的将要分解的数n=prev+(n-prev)，这里要求n-prev划分时划分的数必须不小于prev。*/

#include <iostream>
using namespace std;
int k,n;
long r;			//r用于统计分法数

void backtrack(long dep, long prev, long n)
{
	long m;		//递归回溯程序
	if(dep == k)
	{
		if(n >= prev)
		{
			r++;
			return;
		}
	}
	for(m=prev; m<=n/2; m++)	//划分是一种组合形式，后面的数必须不小于prev
		backtrack(dep + 1,m,n-m);	//考虑下一次对n-m的划分
}

int main()
{
	while(cin>>n>>k)
	{
		r = 0;
		backtrack(1,1,n);
		cout<<r<<endl;
	}
	return 0;
}