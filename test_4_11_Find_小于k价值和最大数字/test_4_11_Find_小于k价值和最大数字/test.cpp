#define _CRT_SECURE_NO_WARNINGS 1
#include <unordered_map>
#include <string>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <bitset>
using namespace std;

//求1~num 之间1的个数:Solution1,Solution2

//Solution3是根据上面的模板进行修改完成价值和的求解（二进制中从右往左第i位）

//1 .数学方法求：
class Solution1 {
public:
    int countDigitOne(int n) {
        // mulk 表示 10^k
        // 在下面的代码中，可以发现 k 并没有被直接使用到（都是使用 10^k）
        // 但为了让代码看起来更加直观，这里保留了 k
        long long mulk = 1;
        int ans = 0;//从个位开始，索引为0，初始的mulk便是10^0 == 1
        //每10^k+1 个数，会有 10^k 个1，，如k=2,百位，1000中：100 101 ~ 199，百位上共有100个1
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
};
// 递归根据上界求：
class Solution2 {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.length();

        vector<vector<int>> dp(m, vector<int>(m, -1)); // 初始化为 -1，表示未计算过，//动态规划（剪枝）

        function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
            if (i == m) 
                return cnt1;
            if (!is_limit && dp[i][cnt1] != -1)
                return dp[i][cnt1];
            int res = 0;//用来统计所有下一位的1总数
            int up = is_limit ? s[i] - '0' : 9;//计算上界 

            for (int d = 0; d <= up; d++) {
                res += f(i + 1, cnt1 + (d == 1), is_limit && d == up);//cnt1为已经选的1个数；
                //上界为true的成立条件是第一个1就被选择，并且后面每一项都选择了该位的最大值
            }
            if (!is_limit) dp[i][cnt1] = res; 
            return res;
            // 保存计算结果,（不是限制的情况下）只要是在同一位，取得了相同的1个数，该位后面1的个数的和是一样的，因为下一位取值都是一样的，进而后面的情况都是不被限制的，组合都一样。
            // 但如果该位置是限制的，下一位的取值就被限制了，只能取0~s[i+1]，可能会使得1的个数减少
            //（这里说一下：各个位被限制的情况只有一次，也就是前面都被限制了）
            };
        return f(0, 0, true);
    }
};
//求价值和，（需要转换成二进制）
class Solution3 {
public:
    long long findMaximumNumber(long long k, int x) { 
        auto check = [&](long long num) {

            //int m = 64 - __builtin_clzll(num);  __builtin_clzll 函数不被识别的问题，
            // 因为 __builtin_clzll 是 GCC 和 Clang 编译器的内部函数，而不是 Visual Studio 的内部函数。
            unsigned long index;
            unsigned char result = _BitScanReverse64(&index, num);
            int m = index + 1;//计算有效位
            vector<vector<long long>> memo(m, vector<long long>(m + 1, -1));//用于记忆化搜索
            function<long long(int, int, bool)> dfs = [&](int i, int cnt1, bool is_limit) -> long long {
                if (i < 0) return cnt1;
                if (!is_limit && memo[i][cnt1] >= 0) return memo[i][cnt1];
                int up = is_limit ? num >> i & 1 : 1;
                long long res = 0;
                for (int d = 0; d <= up; d++) // 枚举要填入的数字 d
                    res += dfs(i - 1, cnt1 + (d == 1 && (i + 1) % x == 0), is_limit && d == up);
                if (!is_limit) memo[i][cnt1] = res;//最高位被限制，同理上面，动态规划是为了避免重复计算，但是每一位被限制的情况只有一次的计算，不被限制的情况的返回值是一样的，后面的可以随意取值，本题则是0~1
                return res;
                };
            return dfs(m - 1, 0, true) <= k;
            };

        // 开区间二分，原理见 https://www.bilibili.com/video/BV1AP41137w7/
        long long left = 0, right = (k + 1) << x;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;//避免数据溢出
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};


int main() {
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol4;
    int n = 123;
    int k, x;
    cin >> k >> x;

    unsigned long num;//13
    unsigned long index;//用于储存最高位索引的变量

    cin >> num;
    int nm1 = bitset<64>(num).count();//求二进制中有多少1
    int nm2 = bitset<32>(num).size();//求二进制的位数
    unsigned char result = _BitScanReverse64(&index, num);//求二进制的有效位数 ,如果找不到有效位，它会将 result 参数设置为 0
    //因为二进制从右往左是从0开始的，所以索引为0意味着第一位
    int nm3 = index + 1;
    /* 
    unsigned char _BitScanReverse64(
    unsigned long* Index,
        unsigned __int64 Mask
        );
    */
    cout << num << "有多少位 1:" << nm1 << endl;
    cout << num << "有多少位:" << nm2 << endl;
    cout << num << "有多少有效位:" << nm3 << endl;

    cout << "Number of 1's in binary representation of " << n << ": " << sol1.countDigitOne(n) << endl;
    cout << "Number of 1's in binary representation of " << n << ": " << sol2.countDigitOne(n) << endl;

    cout << "等于" << k << "价值和最大为: " << sol4.findMaximumNumber(k, x) << endl;// 7 2
    return 0;
}