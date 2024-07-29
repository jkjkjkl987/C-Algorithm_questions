#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // ��ʼ�����к�ˮ��ĸ߶�
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({ i, j }); // �ȴ����
                }
            }
        }

        // 4������
        vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        // BFS

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    height[nx][ny] == -1)
                {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
        return height;
    }
};

int main()
{
    Solution test;
    vector<vector<int>> isWater = { {0,0,1 }, { 1,0,0 }, {0, 0, 0} };
    vector<vector<int>> height = test.highestPeak(isWater);

    for (int i = 0;i < height.size();++i)
    {
        for (int j = 0;j < height[0].size();++j)
        {
            cout << height[i][j];
        }
        cout << endl;
    }
    return 0;
}