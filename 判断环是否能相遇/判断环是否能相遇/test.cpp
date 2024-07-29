#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//��С������
// ����������GCD
int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// ����������LCM
int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

bool Juage(int skip1,int skip2, int L, int C)
{
	//����ĳ���
	long long RedLength1 = skip2 % C;
	long long RedLength2 = skip1 % C;
	//ѭ���ĳ���
	long long L1 = lcm(RedLength1, C);
	long long L2 = lcm(RedLength2, C);
	//�����ڻ������,tΪ������Ҫ�Ĵ���
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
		//������
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