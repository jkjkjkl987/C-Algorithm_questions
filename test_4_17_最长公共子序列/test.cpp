#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution
{
public:
	int FindLongestpartstr(string& s, string& t)
	{
		int sl = s.length();
		int tl = t.length();
		function<int(int, int)> dfs = [&](int i, int j)->int
			{
				if (i < 0 || j < 0)
					return 0;
				if (s[i] == t[j])
					return dfs(i - 1, j - 1) + 1;
				else
					return max(dfs(i, j - 1), dfs(i - 1, j));
			};
		int res = dfs(sl - 1, tl - 1);
		return res ? res : -1;
	}
	//记忆化搜索
	int FindLongestpartstr_m(string& s, string& t)
	{
		int sl = s.length();
		int tl = t.length();
		vector<vector<int>> memo(sl, vector<int>(tl, -1));

		function<int(int, int)> dfs = [&](int i, int j)->int
			{
				if (i < 0 || j < 0)
					return 0;
				int& res = memo[i][j];
				if (res != -1)
					return res;

				if (s[i] == t[j])
					return dfs(i - 1, j - 1) + 1;
				else
					return	res = max(dfs(i, j - 1), dfs(i - 1, j));
			};
		int res = dfs(sl - 1, tl - 1);
		return res ? res : -1;
	}
	//翻译成递推
};
int main()
{
	string s = "abcde";
	string t = "ace";
	Solution test;
	cout << "s、t的最长公共子序列长度为：" << test.FindLongestpartstr(s, t) << endl;

	return 0;
}