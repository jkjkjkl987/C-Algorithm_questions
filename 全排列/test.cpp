#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        // ��������������
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // ��̬ά������
            swap(output[i], output[first]);
            // �����ݹ�����һ����
            backtrack(res, output, first + 1, len);
            // ��������
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

int main()
{
    Solution test;
    vector<int> nums = { 1,2,3 };
    test.backtrack(nums);
    return 0;
}