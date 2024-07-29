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
//n1 n2 n3 //������ͷ���
LN* ReverseList1(LN* p)
{
	assert(p && p->next);
	LN* n1 = NULL, * n2 = p, * n3 = p->next;
	if (p->next == NULL || p == NULL)
	{
		printf("û�ж��������������ת");
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
	return n1;//�µ�ͷ���
}
//ͷ�崴���µ�����cur next
LN* ReverseList2(LN* p)
{
	assert(p && p->next);
	LN* cur = p->next, * bes = cur->next;
	//������ͷ���
	LN* head = (LN*)malloc(sizeof(LN));
	if (head == NULL)
	{
		printf("%s", strerror(errno));
		return p;
	}
	head->next = NULL;//���λ��Ҳ�����п�
	//p->3->2->1->NULL
	while (cur)
	{
		cur->next = head;
		head = cur;
		cur = bes;
		if (bes)
			bes = bes->next;
		else break;
	}// 1->2->3->head ��ʱ��Ҫ��ת
	LN* tmp = head;//���������㣬��������ͷ���
	LN* realh = head;
	LN* pre;
	assert(head->next);
	realh = head->next;
	pre = head;
	while (realh->next != NULL)//������ĩβ,�˴������ͷ���
	{
		pre = pre->next;
		realh = realh->next;
	}
	realh->next = tmp;
	pre->next = NULL;
	printf("��ת�ɹ�\n");
	return realh;
}
//�ݹ�(����ͷ���)
LN* ReverseList3(LN* p)
{
	// ����һ������������ǰһ���ڵ�͵�ǰ�ڵ㣬���ط�ת�������ͷ�ڵ�
	function<LN* (LN*, LN*)> dfs = [&](LN* prev, LN* cur) -> LN*
		{
			if (!cur) // �����ǰ�ڵ�Ϊ�գ���ֱ�ӷ���ǰһ���ڵ�
				return prev;

			LN* next = cur->next; // ��¼��ǰ�ڵ����һ���ڵ�
			cur->next = prev; // ��ת��ǰ�ڵ��ָ��ָ��

			// �ݹ���ã���ǰ�ڵ��Ϊǰһ���ڵ㣬��һ���ڵ��Ϊ��ǰ�ڵ�
			return dfs(cur, next);
		};

	// ���õݹ麯���������ط�ת�������ͷ�ڵ�
	return dfs(NULL, p);
}


//����ͷ�彨��
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
	if (p->next == NULL)//��һ�����Ĵ���
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
//��ӡ
void OutList(LN* p)
{
	assert(p);
	if (p->next == NULL)
	{
		printf("û�н��");
		return;
	}
	else//��ͷ���
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
	printf("******1.ͷ��\t2.��ת********\n");
	printf("******3.��ӡ\t4.�˳�********\n");
	printf("******************************\n");
}
int main()
{
	Datatype x = 0;
	int input = 0;
	LN* head = (LN*)malloc(sizeof(LN));//ͷ�ڵ�
	if (head != NULL)
		head->next = NULL;
	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������ֵ��");
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
			printf("���������������");
			break;
		}
	} while (input != 0);

	return 0;
}