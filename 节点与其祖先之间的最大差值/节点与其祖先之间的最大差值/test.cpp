#define _CRT_SECURE_NO_WARNINGS 1

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
//二叉树结点
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
	right(right) {}
	
};

//向上传递
class Solution1 {
public:
	int maxd;
	pair<int, int> dfs(TreeNode* root)
	{
		if (root == nullptr)
			return { -1,-1 };
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		if (left.first == -1 && right.first == -1) {
			left.first = left.second = root->val;
		}
		else if (left.first == -1 && right.first != -1) {
			left = right;
		}
		else if (left.first != -1 && right.first == -1);
		else {
			left.first = max(left.first, right.first);
			left.second = min(left.second, right.second);
		}
		maxd = max(maxd, max(abs(root->val - left.first), abs(root->val - left.second)));
		//cout<<maxd<<endl<<left.first<<' '<<left.second<<endl;
		left.first = max(root->val, left.first);
		left.second = min(root->val, left.second);
		return left;
	}
	int maxAncestorDiff(TreeNode* root) {
		dfs(root);
		return maxd;
	}
};

//向下传递
class Solution2
{
	int abs_sub(struct TreeNode* root, int mins, int maxs)
	{
		int absa = 0, tmp = 0;
		if (root == NULL)
			return 0;
		absa = max(abs(root->val - mins), abs(root->val - maxs));
		mins = min(root->val, mins);
		maxs = max(root->val, maxs);
		//最大和最小值向下传递
		tmp = max(abs_sub(root->left, mins, maxs), abs_sub(root->right, mins, maxs));
		return max(absa, tmp);
	}
	int maxAncestorDiff(struct TreeNode* root) {
		return abs_sub(root, root->val, root->val);
	}
};

int main()
{
	Solution1 test1;
	Solution2 test2;

	return 0;
}