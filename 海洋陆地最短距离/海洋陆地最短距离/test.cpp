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
        memset(vis, 0, sizeof vis);//新的海洋起始点，没有走过要清零
        queue <Coordinate> q;
        q.push({ x, y, 0 });
        vis[x][y] = 1;//走过的点，记录
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) //每次路径点上的四个方向
            {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) //位置合理
                {
                    continue;
                }
                if (!vis[nx][ny])//没走过
                {
                    q.push({ nx, ny, f.step + 1 });//如果这次没有结果后面可能还会用到这个路径点
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) //是陆地
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