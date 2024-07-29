#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <functional>
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

TreeNode* buildTree(const std::vector<char>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0] - '0');
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    size_t i = 1;
    while (i < nodes.size() && !nodeQueue.empty()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        if (nodes[i] != '#') {
            current->left = new TreeNode(nodes[i] - '0');
            nodeQueue.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != '#') {
            current->right = new TreeNode(nodes[i] - '0');
            nodeQueue.push(current->right);
        }
        i++;
    }

    return root;
}


class Solution {
public:
    //int amountOfTime(TreeNode* root, int start) {
    int amountOfTime(int start) {
    //层次遍历二叉树存进数组
        //vector<int> t = {};
        vector<char> t = { '0','1','2','#','4','5','6','#','#','#','#','#','#','#','#' };
        //vector<char> t = { '0','1','2','#','4','5','6','#','#','9','#','#','#','#','#','#','#','#','#','#','#','#','#','#' };
        int babacount = 0;//父亲支路的最大长度
        int ret;//左右子树最大深度
        int nowcountr = 0;
        int nowcountl = 0;
        bool right;
        if (start % 2 == 0)
            right = true;
        else
            right = false;
        function<int(int, int, bool, bool)> dfs = [&](int start, int count, bool right, bool baba) -> int
            {
                //start：位置 count：距离初始start的长度  right：儿子的方向 baba:继续向上找父亲

                if (start < 0)//没有父亲或者向下没有结点
                    return 0;

                if (baba == false)//代表这个start只需要求当前向下的深度
                {
                    if (t[start] == '#')
                        return 0;
                    nowcountr = dfs(start * 2 + 1, count, start % 2 == 0, false);
                    nowcountl = dfs(start * 2 + 2, count, start % 2 == 0, false);
                    return max(nowcountr, nowcountl) + 1;//最大深度
                }

                //该结点向上的最大长度
                babacount = dfs((start - 1) / 2, count + 1, start % 2 == 0, true) + count + 1;
                //该结点向下的最大深度,//从右孩子来的，现在应该走左孩子                
                if (right)
                    start = start * 2 + 1;
                else
                    start = start * 2 + 2;
                ret = dfs(start, count, right, false) + 1;
                return max(babacount, ret + count);//当前结点的最大长度
            };
        return dfs(start, 1, start % 2 == 0, true);
    }
};

int main()
{
    Solution test;
    
    int start;
    cin >> start;
    cout << test.amountOfTime(start) << endl;
    return 0;
}