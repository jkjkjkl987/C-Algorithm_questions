#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

using namespace std;

/*
dp[i][0] = dp[i-1][0]+I(s[i]=‘1’
dp[i][1] = min(dp[i-1][0],dp[i-1][1])+I(s[i]=‘0’
*/
class Solution1 {
public:
    int minFlipsMonoIncr(string& s) {
        int dp0 = 0, dp1 = 0;
        for (char c : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                dp0New++;
            }
            else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};
class Solution2 {
public:
    int minFlipsMonoIncr(string s) {
        int o = 0;
        int f = 0;
        for (char c : s) {
            (c == '1') ? ++o : ++f;
            f = min(f, o);
        }
        return f;
    }
};

class Solution3 {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = dp[0][1] = 0;//第一个字符不需要翻转
        for (int i = 1;i < n;++i)
        {   
            dp[i][0] = dp[i - 1][0] + (s[i] == '1'); 
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '0');
        }       
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};



    //分区间判断个数：
    //1. 左0多 右0多 都要0
    //2. 左0多 右1多 左要0右要1
    //3. 左1多 右0多 判断哪个更多，要更多的一边
    //4. 左1多 右1多 都要1
 
int main()
{
    string s = "010110";
    Solution1 test1;
    Solution2 test2;
    Solution3 test3;
    cout << test1.minFlipsMonoIncr(s) << endl;
    cout << test2.minFlipsMonoIncr(s) << endl;
    cout << test3.minFlipsMonoIncr(s) << endl;
    return 0;
}