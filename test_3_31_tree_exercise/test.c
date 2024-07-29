#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

// 树的输入
bool assert_tree(char* t, int i)
{	
	
	while (t[i] != '\0')
	{
		//到了结尾
		if (t[i] == 0)
		{
			return true;
		}
		else if (t[i] == '#')//叶子节点
		{
			return false;
		}
		else//非叶子节点
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