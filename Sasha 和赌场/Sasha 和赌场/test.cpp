#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 取消同步，提升输入输出性能
    cin.tie(0);
    cout.tie(0);

    int t = 0; // 测试用例数
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        int k = 0, x = 0, a = 0;
        cin >> k >> x >> a; // 读取 k, x, a 的值

        int sum = 0, q = 0;
        bool ok = true; // 标志位，表示是否能在不破产的情况下赢得任意数量的硬币

        // 从 0 循环到 x，表示允许连续输掉的次数
        for (int i = 0; i <= x; i++) {
            q = sum / (k - 1) + 1; // 计算下注额
            sum += q; // 累加下注额到 sum

            if (sum > a) { // 检查是否破产
                ok = false; // 如果破产，则设置 ok 为 false
                break; // 退出循环
            }
        }

        // 输出结果
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
