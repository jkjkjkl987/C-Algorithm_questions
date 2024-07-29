#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

int main()
{
	int t = 0, n = 0, count = 0;
	cin >> t;
	while (t--)
	{
		count = 0;
		string s;
		cin >> n >> s;
		for (auto e : s)
		{
			if (e == 'U')
				count++;
		}
		cout << (count & 1) ? "Yes" : "No";
	}
	return 0;
}