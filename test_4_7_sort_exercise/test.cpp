#define _CRT_SECURE_NO_WARNINGS 1

/*问题描述：
有一只快乐的蠕虫居住在一个m×n大小的网格中。在网格的某些位置放置了k块石头。网格中的每个位置要么是空的，要么放置了一块石头。当蠕虫睡觉时，它在水平方向或垂直方向上躺着，把身体尽可能伸展开来。蠕虫的身躯既不能进入到放有石块的方格中，也不能伸出网格外。而且蠕虫的长度不会短于2个方格的大小。
	本题的任务是给定网格，要计算蠕虫可以在多少个不同的位置躺下睡觉。
输入：
输入文件的第1行是一个整数t，1<=t<=11,表示测试数据的个数。每个测试数据的第1行为3个整数：m,n和k(0<=m,n,k<=200000),接下来有k行，每行为2个整数，描述了一块石头的位置（行和列，最左上角位置为（1,1））。
输出：
对每个测试数据，输出占一行，为一个整数，表示蠕虫可以躺着睡觉的不同位置的数目。
样例输入：
1
5 5 6
1 5
2 3
2 4
4 2 
4 3
5 1
样例输出：
9
*/
//#include<stdio.h>
//#include<stdlib.h>
//
//struct In
//{
//	int x;
//	int y;
//}s[1000000];  //存储石头的位置（包括后添加的石头）
//typedef struct In In;
//int cmpx(const void* a, const void* b)   //二级排序，先比较x，再比较y
//{
//	struct In* c = (In*)a;
//	struct In* d = (In*)b;
//	if (c->x != d->x) return c->x - d->x;
//	return c->y - d->y;
//}
//
//int cmpy(const void* a, const void* b)    //二级排序，先比较y，再比较x
//{
//	struct In* c = (In*)a;
//	struct In* d = (In*)b;
//	if (c->y != d->y) return c->y - d->y;
//	return c->x - d->x;
//}
//
//int main()
//{
//	int kase;   //输入文件中测试数据个数
//	scanf("%d", &kase);
//	while (kase--)
//	{
//		int m, n, k;			//每个测试数据中的3个数
//		int i, j;			//循环变量
//		scanf("%d%d%d", &m, &n, &k);
//		for (i = 0;i < k;i++)    //读入k块石头的位置
//			scanf("%d%d", &s[i].x, &s[i].y);
//		for (j = 1;j <= n;j++)   //添加垂直方向上边界的石头
//		{
//			s[i].x = 0;
//			s[i].y = j;
//			i++;
//			s[i].x = m + 1;
//			s[i].y = j;
//			i++;
//		}
//		for (j = 1;j <= m;j++)   //添加水平方向上边界的石头
//		{
//			s[i].y = 0;
//			s[i].x = j;
//			i++;
//			s[i].y = n + 1;
//			s[i].x = j;
//			i++;
//		}
//		int t = 0;   //蠕虫可以躺着睡觉的不同位置的数目
//		qsort(s, i, sizeof(s[0]), cmpx);
//		for (j = 0;j < i - 1;j++)
//		{
//			//如果前后两个位置的x坐标相同，y坐标相差超过2
//			if (s[j].x == s[j + 1].x && s[j + 1].y - s[j].y > 2)
//				t++;
//		}
//		qsort(s, i, sizeof(s[0]), cmpy);
//		for (j = 0;j < i - 1;j++)
//		{
//			//如果前后两个位置的y坐标相同，x坐标相差超过2
//			if (s[j].y == s[j + 1].y && s[j + 1].x - s[j].x > 2)
//				t++;
//		}
//		printf("%d\n", t);
//	}
//	return 0;
//}


//单词重组
/*问题描述：
	在美国数以百万计的报纸中，有一种单词游戏称为猜词。游戏的目标是猜谜，为了找出答案中缺少的字母，有必要对4个单词的字母顺序重新调整。在本题中，你的任务是编写程序实现对单词中的字母顺序重新调整。
输入：
输入文件包含4部分：
（1）一部字典，包含至少1个单词，至多100个单词，每个单词占一行；
（2）字典后是一行字符串“XXXXXX”，表示字典结束；
（3）一个或多个被打乱字母顺序的“单词”，每个单词占一行，你必须整理这些字母的顺序；
（4）输入文件的最后一样为字符串“XXXXXX”，代表输入文件结束。
所有单词，包括字典中的单词和被打乱字母顺序的单词，都只包含小写英文字母，并且至少包含一个字母，至多包含6个字母。字典中的单词不一定是按顺序排列的，但保证字典中的单词是唯一的。
输出：
对输入文件中每个被打乱字母顺序的单词w，按字母顺序输出字典中所有满足以下条件的单词的列表：通过调整单词w中的字母顺序，可以变成字典中的单词。列表中的每个单词占一行。如果列表为空（即单词w不能转换成字典中的任何一个单词），则输出一行字符串“NOT A VALID WORD”。以上两种情形都在列表后，输出一行包含6个星号字符的字符串，表示列表结束。
样例输入：
tarp
given
score
refund
only
trap
work
earn
course
pepper
part
XXXXXX
resco
nfudre
aptr
sett
oresuc
XXXXXX
样例输出：
score
******
refund
******
part
tarp
trap
******
NOT A VALID WORD
******
course
*******/
/*解题思路：
本题的意思是给定一部字典（包含1-100个单词），以及若干个字母顺序被打乱的单词；对每个被打乱顺序的单词，输出经过重排字母顺序后能在字典中查找到的每个单词（这些单词要按字母顺序输出来，而不是按在字典中出现的顺序）。
本题两个地方需要进行排序：
（1）为了在字典查找匹配的单词，需要将字典中的每个单词以及读入的字母顺序被打乱的单词，对其中的字母按ASCII编码值进行排序。这样的字典中的单词，只需比较一次即可。
（2）对每个字母顺序被打乱的单词，在输出字典中所有匹配的单词，需要按字典序输出来；所以需要将字典中的单词按字典序排序，在查找时从最前面的单词开始查找。*/

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <algorithm>
//
//using namespace std;
//struct Dir	//字典中的单词
//{
//	char str[10];		//读入时的排列顺序
//	char sorted[10];	//排序后的顺序
//}dir[101];	//字典
//
//int compare(const void* arg1, const void* arg2)
//{
//	return strcmp((*(struct Dir*)arg1).str, (*(struct Dir*)arg2).str);
//}
//
//int main()
//{
//	int i = 0;
//	while (scanf("%s", &dir[i].str) && strcmp(dir[i].str, "XXXXXX"))
//	{
//		strcpy(dir[i].sorted, dir[i].str);
//		//对字典中每个单词的字母按ASCII编码值进行排序
//		sort(dir[i].sorted, dir[i].sorted + strlen(dir[i].str));
//		++i;
//	}
//	qsort(dir, i, sizeof(dir[0]), compare);		//对字典中所有单词进行排序
//	char s[10];
//	while (scanf("%s", s) && strcmp(s, "XXXXXX"))
//	{
//		sort(s, s + strlen(s));		//对读入的打乱字母顺序的单词中的字母排序
//		bool flag = false;			//是否查找到匹配单词的标志
//		for (int j = 0; j < i; ++j)
//		{
//			if (strcmp(s, dir[j].sorted) == 0)
//			{
//				flag = true;
//				printf("%s\n", dir[j].str);
//			}
//		}
//		if (!flag)
//			printf("NOT A VALID WORD\n");
//		printf("******\n");
//	}
//	return 0;
//}


/*DNA排序

一个序列的逆序数定义为序列中无序元素对的数目。例如，在字符序列DAABEC中，逆序数为5，因为字符D比它右边的4个字符大，而字符E比它右边的1个字符大。字符序列AACEDGG只有1个逆序，即E和D,它几乎是已经排好序的，而字符序列“ZWQM”有6个逆序，它是最大程度的无序，即有序序列的逆序。
 在本题中，你的任务是对DNA字符串（只包含字符“A”、“C”，“G”和“T”）进行排序。注意不是按照字母顺序，而是按照逆序数从低到高进行排序，所有字符串的长度都一样。 

Input
输入文件中包含多组测试数据。每组测试数据的格式为：第1行为2个整数，正整数n(0 < n <= 50，表示字符串的长度)和正整数m(1 < m <= 100,表示字符串的数目)；然后是m行，每一行为一个字符串，长度为n。

Output
对应到输入文件中的N组测试数据，输出也有N组，每2组输出之间有一个空行。对每组输入数据，按逆序数从低到高输出各字符串，如果2个字符串的逆序数一行，则按输入时的先后顺序输出。

Sample Input
10 5
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

Sample Output

CCCGGGGGGA
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_str 50
#define max 100

struct Info
{
	char str[max_str];
	int renum;
}DNA[max];

int infocmp(const void* n1, const void* n2)
{
	return ((struct Info*)n1)->renum - ((struct Info*)n2)->renum;
}
struct Info* cnt(struct Info* dan, int m, int n)
{	
	for (int i = 0;i < m;++i)
	{	
		int count = 0;

		for (int j = 0;j < n;++j)
		{
			int p = j, q = j;
			while (p >= 0) { --p;if (p >= 0 && dan[i].str[p] > dan[i].str[j]) { ++count; } };
			while (q < n) { ++q;if (q < n && dan[i].str[q] < dan[i].str[j]) { ++count; } };
		}
		dan[i].renum = count;
	}
	qsort(dan, m, sizeof(dan[0]), infocmp);
	return dan;
}

int main()
{	
	int m, n;
	printf("Sample Input\n");
	scanf("%d %d", &m, &n);
	int i;
	for (i = 0;i < m;++i)
	{
			scanf("%s", DNA[i].str);
	}
	struct Info* alg = cnt(DNA, m, n);
	printf("Sample Output\n");
	for (int i = 0;i < m;++i)
	{
		printf("%s\n", alg[i].str);
	}
}
