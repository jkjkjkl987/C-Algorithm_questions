#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


////求两个整形的最大公约数
//int gcd(int u, int v)
//{
//	int r;
//	while (r = u % v != 0)
//	{
//		u = v;
//		v = r;
//	}
//	return v;
//}
////用递归思想实现：
//int _gcd(int u, int v)
//{
//	if (u % v == 0) return v;
//	else  return gcd(v, u % v);
//}
//int main()
//{
//	int m, n, t;
//	scanf("%d %d", &m, &n);
//	if (m < n)
//	{
//		t = n;
//		n = m;
//		m = t;
//	}
//	printf("%d\n", gcd(m, n));
//	printf("%d\n", _gcd(m, n));
//	return 0;
//}


////汉诺塔问题
//void print(char start, char end)
//{
//	printf("%c - > %c\n", start, end);
//}
//void hanoi(int n, char start, char temp, char end)
//{
//	if (n == 1)
//	{
//		print(start, end);
//	}
//	else
//	{
//		hanoi(n - 1, start, end, temp);//借助目标轴，将n上n-1个圆盘转移至中转轴上
//		print(start, end); 
//		hanoi(n - 1, temp, start, end);//借助起始轴，酱中转轴上的n-1个圆盘转移到目标轴上
//	}
//}
//int main()
//{	
//	hanoi(3, 'A', 'B', 'C');
//	return 0;
//}


////斐波那契数列
//int FindN(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return  1;
//	}
//	else
//	{
//		return FindN(n - 1) + FindN(n - 2);
//	}
//}
////非递归
//int _FindN(int n)
//{
//	
//	int j = 1, k = 1, l = 0;
//	if (n == 3)
//	{
//		return j + k;
//	}
//	while (n >= 3)
//	{			  //    n=5     n=4    n=3
//		l = j + k;//0	//2		3	   5
//		j = k;	  //1	//1		2	   3
//		k = l;	  //1   //2		3	   5
//		n--;
//	}
//	return l;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", FindN(n));//1 1 2 3 5 8 13 21
//	printf("%d\n", _FindN(n));
//	return 0;
//}


//盒形分形
//#include<stdio.h>
//#include<math.h>
//
//#define MAXSCALE 730  //n为最大值7，分形的大小是3^6*3^6，而3^6=729
//
////函数功能：从(startX,startY)位置开始设置度数为n的盒形分形 
////即对盒形分形中的每个X，在字符数组Frac的相应 位置设置字符"X" 
////其中第1个形参为一个二维数组名，其第2维不能省略
//void SetFractal(char Frac[][730], int startX, int startY, int n)
//{
//    if (n == 1) Frac[startX][startY] = 'X';
//    else
//    {
//        int L0 = (int)pow(3, n - 2);
//        SetFractal(Frac, startX + 0, startY + 0, n - 1);
//        SetFractal(Frac, startX + 2 * L0, startY + 0, n - 1);
//        SetFractal(Frac, startX + L0, startY + L0, n - 1);
//        SetFractal(Frac, startX + 0, startY + 2 * L0, n - 1);
//        SetFractal(Frac, startX + 2 * L0, startY + 2 * L0, n - 1);
//    }
//}
//
//int main()
//{
//    int n;  //分形的大小
//    int i, j, k = 0;   //循环变量
//    char Fractal[MAXSCALE][MAXSCALE];
//    while (scanf("%d", &n))
//    {
//        if (n == -1) break;
//        int measure = (int)pow(3, n - 1);   //盒形分形大小
//        SetFractal(Fractal, 0, 0, n);
//        for (i = 0;i < measure;i++)  //保证每行最后的'X'后是串结束标志'\0'
//        {
//            int max = 0;
//            for (j = 0;j < measure;j++)   //找到每行最后的'X'
//                if (Fractal[i][j] == 'X')  max = j;
//            for (j = 0;j < max;j++)   //非'X'的位置上为空格
//                if (Fractal[i][j] != 'X')  Fractal[i][j] = ' ';
//            Fractal[i][max + 1] = '\0';
//        }
//        if (k > 0)
//            printf("-\n");
//        k++;
//        for (i = 0;i < measure;i++)
//            printf("%s\n", Fractal[i]);
//    }
//    return 0;
//}


/*
由正整数1, 2, 3, ...组成了一棵无限大的二叉树。
从某一个结点到根结点（编号是1的结点）都有一条唯一的路径，
比如从10到根结点的路径是(10, 5, 2, 1)，
从4到根结点的路径是(4, 2, 1)，从根结点1到根结点的路径上只包含一个结点1，
因此路径就是(2)。
对于两个结点x和y，假设他们到根结点的路径分别是(x1, x2, ..., 1)和(y1, y2, ..., 1)
（这里显然有x = x1，y = y1），那么必然存在两个正整数i和j，使得从xi 和 yj开始，
有xi = yj, xi + 1 = yj + 1, xi + 2 = yj + 2, ... 
现在的问题就是，给定x和y，要求xi（也就是yj）。

输入：
输入有多行，每行包括两个正整数x和y，这两个正整数都不大于1000。

输出：
每行输出只有一个正整数xi。

样例输入：
10 4
样例输出：
2
*/
//#include<stdio.h>
//
//int common(int x, int y)
//{
//	if (x == y) return x;
//	if (x > y) return common(x / 2, y);
//	return common(x, y / 2);
//}
//
//int main()
//{
//	int m, n;
//
//	while (~scanf("%d %d", &m, &n))
//		printf("%d\n", common(m, n));
//	return 0;
//}


//把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法（用K表示）？注意：5，1，1和1，5，1 是同一种分法。
/*输入：
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1 <= M，N <= 10。
输出：
对输入的每组数据M和N，用一行输出相应的K。
样例输入：
1
7 3
样例输出：
8

解题思路：
所有不同的摆放方法可以分为两类：至少有一个盘子空着和所有盘子都不空。我们可以分别计算这两类摆放方法的数目，然后把它们加起来。对于至少空着一个盘子的情况，则N个盘子摆放M个苹果的摆放方法数目与N - 1个盘子摆放M个苹果的摆放方法数目相同。对于所有盘子都不空的情况，则N个盘子摆放M个苹果的摆放方法数目等于N个盘子摆放M - N个苹果的摆放方法数目。我们可以据此来用递归的方法求解这个问题。
设f(m, n)为m个苹果，n个盘子的放法数目，则先对n作讨论，

如果n > m，必定有n - m个盘子永远空着，去掉它们对摆放苹果方法数目不产生影响；即if(n > m) f(m, n) = f(m, m)。
当n <= m 时，不同的放法可以分成两类：
即有至少一个盘子空着或者所有盘子都有苹果，前一种情况相当于f(m, n) = f(m, n - 1); 
后一种情况可以从每个盘子中拿掉一个苹果，不影响不同放法的数目，即f(m, n) = f(m - n, n)。
总的放苹果的放法数目等于两者的和，即 f(m, n) = f(m, n - 1) + f(m - n, n)。

整个递归过程描述如下：
int f(int m, int n) {
	if (n == １ || m == 0) return 1;
	if (n > m)  return f(m, m);
	return f(m, n - 1) + f(m - n, n);
}
出口条件说明：当n = １时，所有苹果都必须放在一个盘子里，所以返回１；当没有苹果可放时，定义为１种放法；递归的两条路，第一条n会逐渐减少，终会到达出口n == 1; 第二条m会逐渐减少，因为n > m时，我们会return f(m, m) 所以终会到达出口m == 0。
*/
//#include<stdio.h>
//
//int count(int x,int y)
//{
//	if(y==1 || x==0) return 1;
//	if(x<y) return count(x,x);
//	return count(x,y-1)+count(x-y,y);
//}
//
//int main()
//{
//	int t,m,n;
//	int i;
//	scanf("%d",&t);
//	for(i=0;i<t;i++)
//	{
//		scanf("%d%d",&m,&n);
//		printf("%d\n",count(m,n));
//	}
//	return 0;
//}



//波兰表达式
/*解题思路：
这个问题看上去有些复杂，如果只是简单地模拟计算步骤不太容易想清楚，但是如果用递归的思想就非常容易想清楚。让我们根据逆波兰表达式的定义进行递归求解。在递归函数中，针对当前的输入，有五种情况：1）输入是常数，则表达式的值就是这个常数；2）输入是’ + ’ ，则表达式的值是再继续读入两个表达式并计算出它们的值，然后将它们的值相加；3）输入是’ - ’；4）输入是’ * ’； 5）输入是’ / ’；后几种情况与2）相同，只是计算从’ + ’ 变成’ - ’，’ * ’，’ / ’ 。
*/

//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//
//double expa()
//{
//	char a[10];
//	scanf("%s", a);
//	switch (a[0])
//	{
//	case '+': return expa() + expa();
//	case '-': return expa() - expa();
//	case '*': return expa() * expa();
//	case '/': return expa() / expa();
//	default:  return atof(a);
//	}
//}
//
//int main()
//{
//	double ans;
//	int n;
//	//freopen("input","r",stdin);
//	//freopen("output","w",stdout);
//	scanf("%d", &n);
//	while (n--)
//	{
//		ans = expa();
//		printf("%f\n", ans);
//	}
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<assert.h>
//#include<stdbool.h>
//#include<stdlib.h>
//#include<string.h>
//bool f(char x)
//{
//    if (x == '*' || x == '+' || x == '-' || x == '/')
//        return true;
//    return false;
//}
//double ff(double x, double y, char s)
//{
//    switch (s)
//    {
//    case '*':
//        return x * y;
//    case '/':
//        return x / y;
//    case '-':
//        return x - y;
//    }
//    return x + y;
//}
//int main()
//{
//    char s[] = { '+','*','+',11,12,'+',24,35,1,'\0' };
//    int len = strlen(s);
//    double* nums1 = (double*)calloc(len + 1, sizeof(double));
//    double* nums2 = (double*)calloc(len + 1, sizeof(double));
//    assert(nums1 && nums2);
//    double* tmp = NULL;
//    int i = 0, j = 0;
//    for (i = 0; i < len; i++)
//    {
//        printf("% ", s[i]);
//        nums1[i] = (double)s[i];
//    }
//    while (len >= 2)
//    {
//        j = 0;
//        for (i = 0; i < len - 2;)
//        {
//            if (!f(nums1[i + 1]) && !f(nums1[i + 2]) && f(nums1[i]))
//            {
//                nums2[j] = ff(nums1[i + 1], nums1[i + 2], (char)nums1[i]);
//                ++j; i += 3;
//            }
//            else
//            {
//                nums2[j] = (double)nums1[i];
//                ++j; ++i;
//            }
//        }
//        while (i < len)
//        {
//            nums2[j] = nums1[i];
//            ++j; ++i;
//        }
//        len = j;
//        tmp = nums1; nums1 = nums2; nums2 = tmp;
//    }
//    printf("%lf\n", nums1[0]);
//    return 0;
//}



//（递归）反转链表1 . 2
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
 
////反转链表1,整体
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)
//        return NULL;
//    if (head->next == NULL)
//        return head;
//    struct ListNode* newnode = reverseList(head->next);
//    head->next->next = head;
//    head->next = NULL;
//    return newnode;
//}

//反转相邻两结点
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    struct ListNode* newnode = reverseList(head->next->next);
//    head->next->next = head;
//    struct ListNode* temp = head->next;
//    head->next = newnode;
//    return temp;
//}
//
//struct ListNode* creatList(struct ListNode* head, int l)
//{
//    struct ListNode* phead = head;
//    struct ListNode* cur = head;
//
//    // 确保头节点不为空
//    if (!phead) {
//        phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//        if (!phead) {
//            perror("空间分配失败\n");
//            return NULL; // 返回空指针表示创建链表失败
//        }
//        phead->next = NULL;
//        phead->val = l;
//        cur = phead; // 当前节点也指向头节点
//        --l; // 已经添加了一个节点
//    }
//
//    while (l > 0)
//    {
//        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//        if (newnode)
//        {
//            newnode->next = NULL;
//            newnode->val = l;
//
//            //尾插
//            cur->next = newnode;
//            cur = newnode;
//        }
//        else
//        {
//            perror("空间分配失败\n");
//            break; // 停止创建链表
//        }
//        --l;
//    }
//    return phead;
//}
//
//void Print(struct ListNode* p)
//{
//    while (p)
//    {
//        printf("%d -> ", p->val);
//        p = p->next;
//    }
//    printf("NULL\n");
//}
//int main()
//{
//    struct ListNode* head = NULL;
//    head = creatList(head, 5);
//    Print(head);
//    head = reverseList(head);
//    Print(head);
//    return 0;
//}



//
