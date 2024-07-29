#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
vector<int>& worker) {
        // 创建难度和利润的配对
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // 对工作进行排序，先按难度排序，如果难度相同则按利润排序
        sort(jobs.begin(), jobs.end());
        // 对工人能力进行排序
        sort(worker.begin(), worker.end());

        int maxProfit = 0, bestProfit = 0, j = 0;
        for (int w : worker) {
            // 遍历所有工作，找到工人能胜任的最大利润工作
            while (j < n && w >= jobs[j].first) {
                bestProfit = max(bestProfit, jobs[j].second);
                ++j;
                if (w < jobs[j].first)
                    break;
            }
            // 累计最大利润
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};

#if 0
//自定义排序方法的实现：
int main() {
    vector<pair<int, int>> jobs = {{2, 100}, {1, 200}, {2, 150}, {1, 300}};

    // 自定义比较函数
    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // 如果难度相同，则按利润降序排序
        }
        return a.first < b.first; // 否则按难度升序排序
    };

    // 对jobs进行排序
    sort(jobs.begin(), jobs.end(), compare);

    // 输出排序后的结果
    for (const auto& job : jobs) {
        cout << "Difficulty: " << job.first << ", Profit: " << job.second << endl;
    }

    return 0;
}
#endif

int main()
{   
    vector<int> difficulty1 = { 2,4,6,8,10 };
    vector<int> profit1 = { 10,20,30,40,50 };
    vector<int> worker1 = { 4,5,6,7 };
    //100
    vector<int> difficulty2 = { 85,47,57 };
    vector<int> profit2 = { 24,66,99 };
    vector<int> worker2 = { 40,25,25 };
    //0
    Solution test;
    cout << test.maxProfitAssignment(difficulty1, profit1, worker1) << endl;
    cout << test.maxProfitAssignment(difficulty2, profit2, worker2) << endl;

    return 0;
}