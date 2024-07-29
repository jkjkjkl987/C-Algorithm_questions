#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static constexpr int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate {
        int x, y, step;
    };

    int n, m;
    vector<vector<int>> a;

    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y) {
        memset(vis, 0, sizeof vis);//�µĺ�����ʼ�㣬û���߹�Ҫ����
        queue <Coordinate> q;
        q.push({ x, y, 0 });
        vis[x][y] = 1;//�߹��ĵ㣬��¼
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) //ÿ��·�����ϵ��ĸ�����
            {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) //λ�ú���
                {
                    continue;
                }
                if (!vis[nx][ny])//û�߹�
                {
                    q.push({ nx, ny, f.step + 1 });//������û�н��������ܻ����õ����·����
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) //��½��
                    {
                        return f.step + 1;
                    }
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid.at(0).size();
        a = grid;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution test;
    vector<vector<int>> grid = { {1,0,1 }, {0, 0, 0} ,{1, 0, 1} };
    cout << test.maxDistance(grid) << endl;
    return 0;
}