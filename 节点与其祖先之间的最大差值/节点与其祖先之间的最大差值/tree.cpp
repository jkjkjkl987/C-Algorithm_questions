#define _CRT_SECURE_NO_WARNINGS 1

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

enum
{
	EMPTY,
};

template <typename T>
struct TreeNode
{
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode() : val(T()), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode<T>* left, TreeNode<T>* right) : val(x), left(left), right(right) {}
};

template <typename T>
//����
TreeNode<T>* BuildTree(const vector<T> vec)
{
	//�ȴ���ڵ�
    if (vec[0] == nullptr)
        return nullptr;
    queue q;
    q.push[0];
    TreeNode<T>* root = new(TreeNode<T>(vec[0]));
    int i = 1;
    TreeNode<T>* t = q.front();
    q.pop();
    while (i < vec.size())
    {   
        t = new(TreeNode<T>);
        //��
        if (vec[i] != EMPTY)
        {

            ++i;
        }
        //��
        if (i < vec.size() && vec[i] != EMPTY)
        {

        }
    }
}