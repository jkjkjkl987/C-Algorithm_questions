#define _CRT_SECURE_NO_WARNINGS 1

/*����������
��һֻ���ֵ�����ס��һ��m��n��С�������С��������ĳЩλ�÷�����k��ʯͷ�������е�ÿ��λ��Ҫô�ǿյģ�Ҫô������һ��ʯͷ�������˯��ʱ������ˮƽ�����ֱ���������ţ������御������չ���������������Ȳ��ܽ��뵽����ʯ��ķ����У�Ҳ������������⡣�������ĳ��Ȳ������2������Ĵ�С��
	����������Ǹ�������Ҫ�����������ڶ��ٸ���ͬ��λ������˯����
���룺
�����ļ��ĵ�1����һ������t��1<=t<=11,��ʾ�������ݵĸ�����ÿ���������ݵĵ�1��Ϊ3��������m,n��k(0<=m,n,k<=200000),��������k�У�ÿ��Ϊ2��������������һ��ʯͷ��λ�ã��к��У������Ͻ�λ��Ϊ��1,1������
�����
��ÿ���������ݣ����ռһ�У�Ϊһ����������ʾ����������˯���Ĳ�ͬλ�õ���Ŀ��
�������룺
1
5 5 6
1 5
2 3
2 4
4 2 
4 3
5 1
���������
9
*/
//#include<stdio.h>
//#include<stdlib.h>
//
//struct In
//{
//	int x;
//	int y;
//}s[1000000];  //�洢ʯͷ��λ�ã���������ӵ�ʯͷ��
//typedef struct In In;
//int cmpx(const void* a, const void* b)   //���������ȱȽ�x���ٱȽ�y
//{
//	struct In* c = (In*)a;
//	struct In* d = (In*)b;
//	if (c->x != d->x) return c->x - d->x;
//	return c->y - d->y;
//}
//
//int cmpy(const void* a, const void* b)    //���������ȱȽ�y���ٱȽ�x
//{
//	struct In* c = (In*)a;
//	struct In* d = (In*)b;
//	if (c->y != d->y) return c->y - d->y;
//	return c->x - d->x;
//}
//
//int main()
//{
//	int kase;   //�����ļ��в������ݸ���
//	scanf("%d", &kase);
//	while (kase--)
//	{
//		int m, n, k;			//ÿ�����������е�3����
//		int i, j;			//ѭ������
//		scanf("%d%d%d", &m, &n, &k);
//		for (i = 0;i < k;i++)    //����k��ʯͷ��λ��
//			scanf("%d%d", &s[i].x, &s[i].y);
//		for (j = 1;j <= n;j++)   //��Ӵ�ֱ�����ϱ߽��ʯͷ
//		{
//			s[i].x = 0;
//			s[i].y = j;
//			i++;
//			s[i].x = m + 1;
//			s[i].y = j;
//			i++;
//		}
//		for (j = 1;j <= m;j++)   //���ˮƽ�����ϱ߽��ʯͷ
//		{
//			s[i].y = 0;
//			s[i].x = j;
//			i++;
//			s[i].y = n + 1;
//			s[i].x = j;
//			i++;
//		}
//		int t = 0;   //����������˯���Ĳ�ͬλ�õ���Ŀ
//		qsort(s, i, sizeof(s[0]), cmpx);
//		for (j = 0;j < i - 1;j++)
//		{
//			//���ǰ������λ�õ�x������ͬ��y��������2
//			if (s[j].x == s[j + 1].x && s[j + 1].y - s[j].y > 2)
//				t++;
//		}
//		qsort(s, i, sizeof(s[0]), cmpy);
//		for (j = 0;j < i - 1;j++)
//		{
//			//���ǰ������λ�õ�y������ͬ��x��������2
//			if (s[j].y == s[j + 1].y && s[j + 1].x - s[j].x > 2)
//				t++;
//		}
//		printf("%d\n", t);
//	}
//	return 0;
//}


//��������
/*����������
	���������԰���Ƶı�ֽ�У���һ�ֵ�����Ϸ��Ϊ�´ʡ���Ϸ��Ŀ���ǲ��գ�Ϊ���ҳ�����ȱ�ٵ���ĸ���б�Ҫ��4�����ʵ���ĸ˳�����µ������ڱ����У���������Ǳ�д����ʵ�ֶԵ����е���ĸ˳�����µ�����
���룺
�����ļ�����4���֣�
��1��һ���ֵ䣬��������1�����ʣ�����100�����ʣ�ÿ������ռһ�У�
��2���ֵ����һ���ַ�����XXXXXX������ʾ�ֵ������
��3��һ��������������ĸ˳��ġ����ʡ���ÿ������ռһ�У������������Щ��ĸ��˳��
��4�������ļ������һ��Ϊ�ַ�����XXXXXX�������������ļ�������
���е��ʣ������ֵ��еĵ��ʺͱ�������ĸ˳��ĵ��ʣ���ֻ����СдӢ����ĸ���������ٰ���һ����ĸ���������6����ĸ���ֵ��еĵ��ʲ�һ���ǰ�˳�����еģ�����֤�ֵ��еĵ�����Ψһ�ġ�
�����
�������ļ���ÿ����������ĸ˳��ĵ���w������ĸ˳������ֵ��������������������ĵ��ʵ��б�ͨ����������w�е���ĸ˳�򣬿��Ա���ֵ��еĵ��ʡ��б��е�ÿ������ռһ�С�����б�Ϊ�գ�������w����ת�����ֵ��е��κ�һ�����ʣ��������һ���ַ�����NOT A VALID WORD���������������ζ����б�����һ�а���6���Ǻ��ַ����ַ�������ʾ�б������
�������룺
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
���������
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
/*����˼·��
�������˼�Ǹ���һ���ֵ䣨����1-100�����ʣ����Լ����ɸ���ĸ˳�򱻴��ҵĵ��ʣ���ÿ��������˳��ĵ��ʣ��������������ĸ˳��������ֵ��в��ҵ���ÿ�����ʣ���Щ����Ҫ����ĸ˳��������������ǰ����ֵ��г��ֵ�˳�򣩡�
���������ط���Ҫ��������
��1��Ϊ�����ֵ����ƥ��ĵ��ʣ���Ҫ���ֵ��е�ÿ�������Լ��������ĸ˳�򱻴��ҵĵ��ʣ������е���ĸ��ASCII����ֵ���������������ֵ��еĵ��ʣ�ֻ��Ƚ�һ�μ��ɡ�
��2����ÿ����ĸ˳�򱻴��ҵĵ��ʣ�������ֵ�������ƥ��ĵ��ʣ���Ҫ���ֵ����������������Ҫ���ֵ��еĵ��ʰ��ֵ��������ڲ���ʱ����ǰ��ĵ��ʿ�ʼ���ҡ�*/

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <algorithm>
//
//using namespace std;
//struct Dir	//�ֵ��еĵ���
//{
//	char str[10];		//����ʱ������˳��
//	char sorted[10];	//������˳��
//}dir[101];	//�ֵ�
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
//		//���ֵ���ÿ�����ʵ���ĸ��ASCII����ֵ��������
//		sort(dir[i].sorted, dir[i].sorted + strlen(dir[i].str));
//		++i;
//	}
//	qsort(dir, i, sizeof(dir[0]), compare);		//���ֵ������е��ʽ�������
//	char s[10];
//	while (scanf("%s", s) && strcmp(s, "XXXXXX"))
//	{
//		sort(s, s + strlen(s));		//�Զ���Ĵ�����ĸ˳��ĵ����е���ĸ����
//		bool flag = false;			//�Ƿ���ҵ�ƥ�䵥�ʵı�־
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


/*DNA����

һ�����е�����������Ϊ����������Ԫ�ضԵ���Ŀ�����磬���ַ�����DAABEC�У�������Ϊ5����Ϊ�ַ�D�����ұߵ�4���ַ��󣬶��ַ�E�����ұߵ�1���ַ����ַ�����AACEDGGֻ��1�����򣬼�E��D,���������Ѿ��ź���ģ����ַ����С�ZWQM����6�������������̶ȵ����򣬼��������е�����
 �ڱ����У���������Ƕ�DNA�ַ�����ֻ�����ַ���A������C������G���͡�T������������ע�ⲻ�ǰ�����ĸ˳�򣬶��ǰ����������ӵ͵��߽������������ַ����ĳ��ȶ�һ���� 

Input
�����ļ��а�������������ݡ�ÿ��������ݵĸ�ʽΪ����1��Ϊ2��������������n(0 < n <= 50����ʾ�ַ����ĳ���)��������m(1 < m <= 100,��ʾ�ַ�������Ŀ)��Ȼ����m�У�ÿһ��Ϊһ���ַ���������Ϊn��

Output
��Ӧ�������ļ��е�N��������ݣ����Ҳ��N�飬ÿ2�����֮����һ�����С���ÿ���������ݣ����������ӵ͵���������ַ��������2���ַ�����������һ�У�������ʱ���Ⱥ�˳�������

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
