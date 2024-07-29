#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
vector<int>& worker) {
        // �����ѶȺ���������
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // �Թ������������Ȱ��Ѷ���������Ѷ���ͬ����������
        sort(jobs.begin(), jobs.end());
        // �Թ���������������
        sort(worker.begin(), worker.end());

        int maxProfit = 0, bestProfit = 0, j = 0;
        for (int w : worker) {
            // �������й������ҵ�������ʤ�ε����������
            while (j < n && w >= jobs[j].first) {
                bestProfit = max(bestProfit, jobs[j].second);
                ++j;
                if (w < jobs[j].first)
                    break;
            }
            // �ۼ��������
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};

#if 0
//�Զ������򷽷���ʵ�֣�
int main() {
    vector<pair<int, int>> jobs = {{2, 100}, {1, 200}, {2, 150}, {1, 300}};

    // �Զ���ȽϺ���
    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // ����Ѷ���ͬ��������������
        }
        return a.first < b.first; // �����Ѷ���������
    };

    // ��jobs��������
    sort(jobs.begin(), jobs.end(), compare);

    // ��������Ľ��
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