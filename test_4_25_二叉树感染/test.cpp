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
    //��α����������������
        //vector<int> t = {};
        vector<char> t = { '0','1','2','#','4','5','6','#','#','#','#','#','#','#','#' };
        //vector<char> t = { '0','1','2','#','4','5','6','#','#','9','#','#','#','#','#','#','#','#','#','#','#','#','#','#' };
        int babacount = 0;//����֧·����󳤶�
        int ret;//��������������
        int nowcountr = 0;
        int nowcountl = 0;
        bool right;
        if (start % 2 == 0)
            right = true;
        else
            right = false;
        function<int(int, int, bool, bool)> dfs = [&](int start, int count, bool right, bool baba) -> int
            {
                //start��λ�� count�������ʼstart�ĳ���  right�����ӵķ��� baba:���������Ҹ���

                if (start < 0)//û�и��׻�������û�н��
                    return 0;

                if (baba == false)//�������startֻ��Ҫ��ǰ���µ����
                {
                    if (t[start] == '#')
                        return 0;
                    nowcountr = dfs(start * 2 + 1, count, start % 2 == 0, false);
                    nowcountl = dfs(start * 2 + 2, count, start % 2 == 0, false);
                    return max(nowcountr, nowcountl) + 1;//������
                }

                //�ý�����ϵ���󳤶�
                babacount = dfs((start - 1) / 2, count + 1, start % 2 == 0, true) + count + 1;
                //�ý�����µ�������,//���Һ������ģ�����Ӧ��������                
                if (right)
                    start = start * 2 + 1;
                else
                    start = start * 2 + 2;
                ret = dfs(start, count, right, false) + 1;
                return max(babacount, ret + count);//��ǰ������󳤶�
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