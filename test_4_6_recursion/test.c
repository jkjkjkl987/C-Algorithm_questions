#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


////���������ε����Լ��
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
////�õݹ�˼��ʵ�֣�
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


////��ŵ������
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
//		hanoi(n - 1, start, end, temp);//����Ŀ���ᣬ��n��n-1��Բ��ת������ת����
//		print(start, end); 
//		hanoi(n - 1, temp, start, end);//������ʼ�ᣬ����ת���ϵ�n-1��Բ��ת�Ƶ�Ŀ������
//	}
//}
//int main()
//{	
//	hanoi(3, 'A', 'B', 'C');
//	return 0;
//}


////쳲���������
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
////�ǵݹ�
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


//���η���
//#include<stdio.h>
//#include<math.h>
//
//#define MAXSCALE 730  //nΪ���ֵ7�����εĴ�С��3^6*3^6����3^6=729
//
////�������ܣ���(startX,startY)λ�ÿ�ʼ���ö���Ϊn�ĺ��η��� 
////���Ժ��η����е�ÿ��X�����ַ�����Frac����Ӧ λ�������ַ�"X" 
////���е�1���β�Ϊһ����ά�����������2ά����ʡ��
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
//    int n;  //���εĴ�С
//    int i, j, k = 0;   //ѭ������
//    char Fractal[MAXSCALE][MAXSCALE];
//    while (scanf("%d", &n))
//    {
//        if (n == -1) break;
//        int measure = (int)pow(3, n - 1);   //���η��δ�С
//        SetFractal(Fractal, 0, 0, n);
//        for (i = 0;i < measure;i++)  //��֤ÿ������'X'���Ǵ�������־'\0'
//        {
//            int max = 0;
//            for (j = 0;j < measure;j++)   //�ҵ�ÿ������'X'
//                if (Fractal[i][j] == 'X')  max = j;
//            for (j = 0;j < max;j++)   //��'X'��λ����Ϊ�ո�
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
��������1, 2, 3, ...�����һ�����޴�Ķ�������
��ĳһ����㵽����㣨�����1�Ľ�㣩����һ��Ψһ��·����
�����10��������·����(10, 5, 2, 1)��
��4��������·����(4, 2, 1)���Ӹ����1��������·����ֻ����һ�����1��
���·������(2)��
�����������x��y���������ǵ�������·���ֱ���(x1, x2, ..., 1)��(y1, y2, ..., 1)
��������Ȼ��x = x1��y = y1������ô��Ȼ��������������i��j��ʹ�ô�xi �� yj��ʼ��
��xi = yj, xi + 1 = yj + 1, xi + 2 = yj + 2, ... 
���ڵ�������ǣ�����x��y��Ҫ��xi��Ҳ����yj����

���룺
�����ж��У�ÿ�а�������������x��y����������������������1000��

�����
ÿ�����ֻ��һ��������xi��

�������룺
10 4
���������
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


//��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�����K��ʾ����ע�⣺5��1��1��1��5��1 ��ͬһ�ַַ���
/*���룺
��һ���ǲ������ݵ���Ŀt��0 <= t <= 20��������ÿ�о�������������M��N���Կո�ֿ���1 <= M��N <= 10��
�����
�������ÿ������M��N����һ�������Ӧ��K��
�������룺
1
7 3
���������
8

����˼·��
���в�ͬ�İڷŷ������Է�Ϊ���ࣺ������һ�����ӿ��ź��������Ӷ����ա����ǿ��Էֱ����������ڷŷ�������Ŀ��Ȼ������Ǽ��������������ٿ���һ�����ӵ��������N�����Ӱڷ�M��ƻ���İڷŷ�����Ŀ��N - 1�����Ӱڷ�M��ƻ���İڷŷ�����Ŀ��ͬ�������������Ӷ����յ��������N�����Ӱڷ�M��ƻ���İڷŷ�����Ŀ����N�����Ӱڷ�M - N��ƻ���İڷŷ�����Ŀ�����ǿ��Ծݴ����õݹ�ķ������������⡣
��f(m, n)Ϊm��ƻ����n�����ӵķŷ���Ŀ�����ȶ�n�����ۣ�

���n > m���ض���n - m��������Զ���ţ�ȥ�����Ƕ԰ڷ�ƻ��������Ŀ������Ӱ�죻��if(n > m) f(m, n) = f(m, m)��
��n <= m ʱ����ͬ�ķŷ����Էֳ����ࣺ
��������һ�����ӿ��Ż����������Ӷ���ƻ����ǰһ������൱��f(m, n) = f(m, n - 1); 
��һ��������Դ�ÿ���������õ�һ��ƻ������Ӱ�첻ͬ�ŷ�����Ŀ����f(m, n) = f(m - n, n)��
�ܵķ�ƻ���ķŷ���Ŀ�������ߵĺͣ��� f(m, n) = f(m, n - 1) + f(m - n, n)��

�����ݹ�����������£�
int f(int m, int n) {
	if (n == �� || m == 0) return 1;
	if (n > m)  return f(m, m);
	return f(m, n - 1) + f(m - n, n);
}
��������˵������n = ��ʱ������ƻ�����������һ����������Է��أ�����û��ƻ���ɷ�ʱ������Ϊ���ַŷ����ݹ������·����һ��n���𽥼��٣��ջᵽ�����n == 1; �ڶ���m���𽥼��٣���Ϊn > mʱ�����ǻ�return f(m, m) �����ջᵽ�����m == 0��
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



//�������ʽ
/*����˼·��
������⿴��ȥ��Щ���ӣ����ֻ�Ǽ򵥵�ģ����㲽�費̫�������������������õݹ��˼��ͷǳ�����������������Ǹ����沨�����ʽ�Ķ�����еݹ���⡣�ڵݹ麯���У���Ե�ǰ�����룬�����������1�������ǳ���������ʽ��ֵ�������������2�������ǡ� + �� ������ʽ��ֵ���ټ��������������ʽ����������ǵ�ֵ��Ȼ�����ǵ�ֵ��ӣ�3�������ǡ� - ����4�������ǡ� * ���� 5�������ǡ� / �������������2����ͬ��ֻ�Ǽ���ӡ� + �� ��ɡ� - ������ * ������ / �� ��
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



//���ݹ飩��ת����1 . 2
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
 
////��ת����1,����
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

//��ת���������
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
//    // ȷ��ͷ�ڵ㲻Ϊ��
//    if (!phead) {
//        phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//        if (!phead) {
//            perror("�ռ����ʧ��\n");
//            return NULL; // ���ؿ�ָ���ʾ��������ʧ��
//        }
//        phead->next = NULL;
//        phead->val = l;
//        cur = phead; // ��ǰ�ڵ�Ҳָ��ͷ�ڵ�
//        --l; // �Ѿ������һ���ڵ�
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
//            //β��
//            cur->next = newnode;
//            cur = newnode;
//        }
//        else
//        {
//            perror("�ռ����ʧ��\n");
//            break; // ֹͣ��������
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
