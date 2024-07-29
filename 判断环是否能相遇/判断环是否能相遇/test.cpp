#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//最小公倍数
// 函数：计算GCD
int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// 函数：计算LCM
int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

bool Juage(int skip1,int skip2, int L, int C)
{
	//多余的长度
	long long RedLength1 = skip2 % C;
	long long RedLength2 = skip1 % C;
	//循环的长度
	long long L1 = lcm(RedLength1, C);
	long long L2 = lcm(RedLength2, C);
	//各自在环中起点,t为进环需要的次数
	int t = L % skip1 == 0 ? L / skip1 : L / skip1 + 1;

	long long n1 = ((skip1 * t) - L) % C;
	long long n2 = ((skip2 * t) - L) % C;

	long long times = lcm(L1 / skip1, L2 / skip2);
	while (times--)
	{
		if (L1 % C == L2 % C)
			return true;
		if (n1 + skip1 == L1)
			n1 = 0;
		if (n2 + skip2 == L2)
			n2 = 0;
		//继续走
		n1 += skip1;
		n2 += skip2;
	}
	return false;
}
int main()
{
	int skip1, skip2;
	cin >> skip1 >> skip2;
	int L, C;
	cin >> L>>C;
	Juage(skip1, skip2, L, C) ? cout << "YES" : cout << "NO";

	return 0;
}