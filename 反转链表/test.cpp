#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <functional>
#define Datatype int

using namespace std;

typedef struct ListNode
{
	struct ListNode* next;
	Datatype val;
}LN;
//n1 n2 n3 //用于无头结点
LN* ReverseList1(LN* p)
{
	assert(p && p->next);
	LN* n1 = NULL, * n2 = p, * n3 = p->next;
	if (p->next == NULL || p == NULL)
	{
		printf("没有多余结点可以用来反转");
		return p;
	}
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 == NULL)
			break;
		n3 = n3->next;
	}
	return n1;//新的头结点
}
//头插创建新的链表cur next
LN* ReverseList2(LN* p)
{
	assert(p && p->next);
	LN* cur = p->next, * bes = cur->next;
	//创建新头结点
	LN* head = (LN*)malloc(sizeof(LN));
	if (head == NULL)
	{
		printf("%s", strerror(errno));
		return p;
	}
	head->next = NULL;//这个位置也可以判空
	//p->3->2->1->NULL
	while (cur)
	{
		cur->next = head;
		head = cur;
		cur = bes;
		if (bes)
			bes = bes->next;
		else break;
	}// 1->2->3->head 此时需要反转
	LN* tmp = head;//保存这个结点，用来链接头结点
	LN* realh = head;
	LN* pre;
	assert(head->next);
	realh = head->next;
	pre = head;
	while (realh->next != NULL)//遍历到末尾,此处结点是头结点
	{
		pre = pre->next;
		realh = realh->next;
	}
	realh->next = tmp;
	pre->next = NULL;
	printf("反转成功\n");
	return realh;
}
//递归(不带头结点)
LN* ReverseList3(LN* p)
{
	// 定义一个函数，接受前一个节点和当前节点，返回反转后的链表头节点
	function<LN* (LN*, LN*)> dfs = [&](LN* prev, LN* cur) -> LN*
		{
			if (!cur) // 如果当前节点为空，则直接返回前一个节点
				return prev;

			LN* next = cur->next; // 记录当前节点的下一个节点
			cur->next = prev; // 反转当前节点的指针指向

			// 递归调用，当前节点变为前一个节点，下一个节点变为当前节点
			return dfs(cur, next);
		};

	// 调用递归函数，并返回反转后的链表头节点
	return dfs(NULL, p);
}


//类似头插建表
LN* StackPush(LN* p, Datatype x)
{
	assert(p);
	LN* newnode = (LN*)malloc(sizeof(LN));
	if (newnode == NULL)
	{
		printf("%s", strerror(errno));
		return p;
	}
	newnode->next = NULL;
	newnode->val = x;
	if (p->next == NULL)//第一个结点的处理
	{
		p->next = newnode;
		return p;
	}
	else
	{
		LN* tmp = p->next;
		newnode->next = tmp;
		p->next = newnode;
	}
	return p;
}
//打印
void OutList(LN* p)
{
	assert(p);
	if (p->next == NULL)
	{
		printf("没有结点");
		return;
	}
	else//带头结点
	{
		printf("Head");
		p = p->next;
		while (p)
		{
			printf("->%d", p->val);
			p = p->next;
		}
		printf("->NULL\n");
	}
}

void Menu()
{
	printf("******************************\n");
	printf("******1.头插\t2.反转********\n");
	printf("******3.打印\t4.退出********\n");
	printf("******************************\n");
}
int main()
{
	Datatype x = 0;
	int input = 0;
	LN* head = (LN*)malloc(sizeof(LN));//头节点
	if (head != NULL)
		head->next = NULL;
	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入值：");
			scanf("%d", &x);
			head = StackPush(head, x);
			break;
		case 2:
			head = ReverseList3(head);
			break;
		case 3:
			OutList(head);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("输入错误，重新输入");
			break;
		}
	} while (input != 0);

	return 0;
}