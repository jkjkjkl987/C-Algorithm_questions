#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) { 
        // ��ȡ����
        int rows = frame.size();

        // ��ȡ���������������ж�����ͬ��������
        int columns = frame[0].size();
        vector<vector<int>> f(rows, vector<int>(columns, 0));
        f[0][0] = frame[0][0];
        for (int i = 0; i < rows; ++i) {

            for (int j = 0; j < columns; ++j) {
                if (i == 0 && j == 0)
                    continue;
                if ((i > 0 && i < columns) && (j > 0 && j < columns))
                {
                    f[i][j] = max(frame[i - 1][j], frame[i][j - 1]) + frame[i][j];
                    continue;
                }
                else if (i > 0 && j == 0)
                {
                    f[i][j] = f[i - 1][j] + frame[i][j];//��
                }
                else if (j > 0 && i == 0)
                    f[i][j] = f[i][j - 1] + frame[i][j];//��
                else
                    continue;
            }
        }
        return f[rows - 1][columns - 1];
    }
};

int main()
{
    vector<vector<int>>  frame = { {1, 3, 1},{1, 5, 1},{4, 2, 1} };
    // 1 -> 3 -> 5 -> 2 -> 1
    Solution test;
    cout << test.jewelleryValue(frame) << endl;

    return 0;
}