#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

// ��������
bool assert_tree(char* t, int i)
{	
	
	while (t[i] != '\0')
	{
		//���˽�β
		if (t[i] == 0)
		{
			return true;
		}
		else if (t[i] == '#')//Ҷ�ӽڵ�
		{
			return false;
		}
		else//��Ҷ�ӽڵ�
		{
			(assert_tree(t, i + 1));
			++i;
			(assert_tree(t, i + 1));
			++i;

		}

	}
}

int main()
{
	char ch;
	int i = 0;
	char tree[100] = { 0 };
	while (scanf("%c", &ch) != EOF)
	{
		tree[i] = ch;
		i++;
	}
	assert_tree(tree, 0);
	return 0;
}