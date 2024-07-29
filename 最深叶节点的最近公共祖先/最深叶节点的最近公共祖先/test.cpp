#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Tree {
public:
    TreeNode* buildTree(const vector<int>& nodes) {
        if (nodes.empty() || nodes[0] == -1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nodes[0]);
        queue<TreeNode*> q;
        q.push(root);
        size_t i = 1;

        while (i < nodes.size()) {
            TreeNode* current = q.front();
            q.pop();

            if (nodes[i] != -1) {
                current->left = new TreeNode(nodes[i]);
                q.push(current->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != -1) {
                current->right = new TreeNode(nodes[i]);
                q.push(current->right);
            }
            i++;
        }

        return root;
    }
};

int flag = 0;
class Solution1 {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = 0;
        return findLCA(root, 0, maxDepth, root);
    }

    TreeNode* findLCA(TreeNode* node, int depth, int& maxDepth, TreeNode*& M) {
        if (!node) {
            return nullptr;
        }

        // ����������
        if (depth > maxDepth) {
            maxDepth = depth;
        }

        // �����ǰ�ڵ���Ҷ�ӽڵ㣬���ص�ǰ�ڵ�
        if (!node->left && !node->right) {
            return node;
        }

        TreeNode* leftLCA = findLCA(node->left, depth + 1, maxDepth, M);
        TreeNode* rightLCA = findLCA(node->right, depth + 1, maxDepth, M);
        // ���Һ��ӽ�㶼��Ϊ��ʱ�Ĺ�������
        if (leftLCA && rightLCA && depth == maxDepth - 1) {
            M = node;
            flag = 1;
            return node;
        }
        // ���������ϴ���
        if (M && leftLCA && leftLCA)//�������ȣ���ȷ����
            return M;
        // һ�ߺ���Ϊ�յĹ�������
        if (flag == 0 && depth == maxDepth - 1)//��û������
            return M = leftLCA ? leftLCA : rightLCA;
        return leftLCA ? leftLCA : rightLCA;
    }
};

class Solution2 {
public:
    TreeNode* p = nullptr;
    int maxh = 0;
    bool dfs1(TreeNode* root, int h)
    {
        if (root == nullptr)
        {
            if (h == maxh)
                return true;
            return false;
        }
        bool left = dfs1(root->left, h + 1);
        bool right = dfs1(root->right, h + 1);
        if (left && right)
            p = root;
        return left || right;
    }
    void dfs2(TreeNode* root, int h)
    {
        if (root == nullptr)
        {
            if (h > maxh)
                maxh = h;
            return;
        }
        dfs2(root->left, h + 1);
        dfs2(root->right, h + 1);
        return;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs2(root, 0);
        dfs1(root, 0);
        return p;
    }
};

int main() {
    Solution2 test;
    // ����
    //vector<int> nodes = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };
    vector<int> nodes = { 0,1,3,-1,2 };
    Tree tree;
    TreeNode* root = tree.buildTree(nodes);

    TreeNode* lca = test.lcaDeepestLeaves(root);
    if (lca) {
        cout << lca->val << endl;
    }
    else {
        cout << "not found" << endl;
    }

    return 0;
}
