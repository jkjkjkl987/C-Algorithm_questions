#define _CRT_SECURE_NO_WARNINGS 1
/*����������
	N����ͽһ�������һ����Ϸ��
	��Ϸ�տ�ʼ��ʱ��ÿ����ͽ�Ѷ�ע�������ϲ���ס������Ҫ�鿴ÿ���˵Ķ�ע��ȷ��ÿ���˵Ķ�ע����һ�������һ����ͽûǮ�ˣ�����Ҫ��һЩ���룬������Ķ�עΪ�������ٶ���ע����������
	����ͽ�ǽҿ����ӣ���ʾ���ǵĶ�ע�����˭�µĶ�ע��������ͽ��ĳ3�����µĶ�ע֮�ͣ�������ʤ���ߡ�����ж���һ��ʤ���ߣ����µĶ�ע���Ķ�ͽ�������յ�ʤ���ߡ�
	���磬�ٶ���ͽΪ��Tom��Bill��John��Roger��Bush�������µĶ�ע�ֱ�Ϊ��$2��$3��$5��$7��$12 ��������ջ�ʤ����Bush������û����������ʤ���ߣ�����Ϊ���µĶ�עΪ$12�������������µĶ�ע֮��Ҳ����12��$2+$3+$7=$12��
���룺
�����ļ��а����˶����ͽ�µĶ�ע��ÿ���ע�����ݵ�1����һ������n,1<=n<=1000,�����ͽ�ĸ�����Ȼ���������µĶ�ע��ÿ���˵Ķ�עռһ�У���Щ��ע������ͬ�����ҷ�Χ��[-536870912,+536870911]�������ļ������һ��Ϊ0���������������
�����
��ÿ���ע�����ʤ�����µĶ�ע�����û�н⣬�������no solution����
�������룺
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
���������
12
no solution
���������
	����Ҫ�����һ�����Ķ�ע�����㣺��������3����ע�ĺ͡������ע�����data�����У��Ƚ�n���˵Ķ�ע����С�����˳�����򡣿��Բ��õ�˼·��ö�٣��������Ķ�ע��ʼ�����Ƿ����һ����ע������3����ͬ��ע֮�͡����������Ҫ������ѭ��ʵ�֡�
��1�����ݽṹ
int n;				//ÿ���ͽ��������Ҳ�������ֵĸ�����
int data[1000];		//ÿ����ͽ�Ķ�ע��
int winner;			//Ӯ�ҵı�ţ����ע��data[winner]
��2�����������ְ���С�����˳������
����C���Կ⺯����
qsort(bet, n, sizeof(int), cmp);
����cmpΪ�Ƚ����ӣ�����������
int cmp(const void *a, const void *b)
{
		return (*(int *)a - *(int *)b);
}
��3��ö�٣��ҳ�Ӯ�ҵı��
������������У��Ӻ���ǰȡӮ�ҵ����i����������Ľ����Ȼ�Ƕ�ע����Ӯ�ҡ�������ͽ�ı�ţ�������һ�������Ӯ�ҵ�ǰ�棨j�������ڴ��ڸ���������������ͽ�ı�ţ����п�����Ӯ�ұ�ŵĺ��档��ö��������ͽ��j,k�������������ͽ�Ķ�עΪM= data[i]-data[j]-data[k]��Ҳ����data[i]=data[j]+data[k]+M�����data[i]������Ŀ��Ҫ�󡣵�ͬʱҪ��֤��data[i]-data[j]-data[k]���Ȳ�����data[i]��data[j]��Ҳ������data[k]�������data[i]Ϊ�������data[i]-data[j]- data[k]=data[i]����ֻҪdata[j]=-data[k]�����е�data[i]������������������ҵ��������i����Ӯ�ң�����������ҡ�ֱ�����е����ֶ�������ϣ���û��Ӯ�ҵĻ�������û�н���ˡ�
ע�⣺����n��ֵ������ȡ��1000�����n��ֵȡ1000��������ѭ����if�����ıȽ��������������Ҫִ��1000��1000��1000��1000�Σ�����Ȼ�ⲻ��һ�ֺ÷�����*/
//#include <stdio.h>
//#include <stdlib.h>
//
//const int MAXN = 1001;
//int data[MAXN], n;   //��ͽ���µĶ�ע����ͽ������
//
////�������ıȽ����ӣ���������
//int cmp(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//
//int search(int x)  //��data�����в���x��������ҵ���������Ӧ���±꣬���򷵻�-1,���ö���������
//{
//	int low = 0, high = n - 1, mid;			//�������ұ߽�
//	while (low <= high)
//	{
//		mid = (low + high) / 2;			//�м�λ��
//		if (data[mid] == x) return mid;//�ҵ��ˣ�����λ�����
//		if (data[mid] > x) high = mid - 1;
//		if (data[mid] < x) low = mid + 1;
//	}
//	return -1;						//û���ҵ�
//}
//
////ö���㷨������
//void work()
//{
//	qsort(data, n, sizeof(data[0]), cmp);//��С��������
//	int i, j, k, m;
//	//ö�ٲ���
//	for (i = n - 1;i >= 0;i--)					//Ӯ�Ҵ����еĺ���ȡ��ȷ��������
//	{
//		for (j = 0;j < n;j++);
//		{
//			if (i == j)  continue;
//			for (k = j + 1;k < n;k++)
//			{
//				if (i == k) continue;
//				m = search(data[i] - data[j] - data[k]);
//				//���ڵ�4�����µĶ�עΪdata[i]-data[j]-data[k]
//				//��������˲���i,j,Ҳ����k����i����ʤ����
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


//������
/*����������
	�����Ķ��壺����һ�����ڣ�����������������ˣ���������û����������Լ���ˣ���ô������ͳ�Ϊ���������磬2,11,67,89��������8,20,27����������
	�������Ķ��壺����һ������1������������������Ա��ֽ��2�������ĳ˻�����Ƹ���Ϊ������������6��һ������������12���ǡ�
	����������ж�һ�����Ƿ��ǰ�������
���룺
�����ļ����ж���������ݣ�ÿ���������ݰ���һ������N��2<=N<=1,000,000��
�����
��ÿ���������ݣ����N�ǰ������������YES���������NO��
�������룺
3
4
6
12
���������
No
Yes
Yes
No
���������
�������˼������һ������N��2��N��1000000���ж�N�ǲ��ǰ������������500000���ڵ���������Ϊ��С������Ϊ2������41538�����������ÿ������N����2��ʼ����������i�����i��N/i�������������в��ҵ�����N�ǰ�������*/
//#include <stdio.h>
//#include <math.h>
//#include <fstream>
//
//int p[500001]; //p[i]Ϊ1���ʾiΪ����
//int primes[41540]; //�洢500000���ڵ�ÿ����������41538����
//int k; //1000000������������
//
//void compute_prime_table() //ɸѡ�����500000���ڵ���������
//{
//	int i, j;
//	p[0] = p[1] = 0;
//	for (i = 2;i <= 500000;i++)
//		p[i] = 1; //��ʼ��
//	for (i = 2;i <= 1000;)//������С��1000��������ɾ�����ǵı���
//	{
//		for (j = i + i;j <= 500000;j += i)
//			p[j] = 0;//ɾ��i�����б���
//		for (i++;!p[i];i++);//����һ������
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
//bool BinSearch(int tab[], int n, int num)//���ֲ���
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
//	int N, sqrtN, flag, i; //NΪ�����ÿ������
//	compute_prime_table();
//	while (scanf("%d", &N) != EOF)
//	{
//		sqrtN = sqrt(double(N));
//		flag = 0; //��־
//		for (i = 2;i <= sqrtN;i++)
//		{
//			if (N % i == 0)
//			{
//				//���������в���i��N/i
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



/*����������
��ҹ�ճ���ɶ�άƽ�棬ÿ������һ��(X,Y)���ꡣ��Щ������γɶ��������Σ�
���룺
�������롣����ÿ�����ݣ���һ����n��1<=n<=1000����ʾ��֪��������Ȼ����n�У�ÿ��һ������ֵ���������ֵС��20000��n=0��ʾ������
�����
����ÿ����������γ������εĸ�����
�������룺
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
���������
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
void out(int a)  //����printf���ٶȸ��죬�׳������
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