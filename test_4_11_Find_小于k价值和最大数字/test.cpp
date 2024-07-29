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

//��1~num ֮��1�ĸ���:Solution1,Solution2

//Solution3�Ǹ��������ģ������޸���ɼ�ֵ�͵���⣨�������д��������iλ��

//1 .��ѧ������
class Solution1 {
public:
    int countDigitOne(int n) {
        // mulk ��ʾ 10^k
        // ������Ĵ����У����Է��� k ��û�б�ֱ��ʹ�õ�������ʹ�� 10^k��
        // ��Ϊ���ô��뿴��������ֱ�ۣ����ﱣ���� k
        long long mulk = 1;
        int ans = 0;//�Ӹ�λ��ʼ������Ϊ0����ʼ��mulk����10^0 == 1
        //ÿ10^k+1 ���������� 10^k ��1������k=2,��λ��1000�У�100 101 ~ 199����λ�Ϲ���100��1
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
};
// �ݹ�����Ͻ���
class Solution2 {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.length();

        vector<vector<int>> dp(m, vector<int>(m, -1)); // ��ʼ��Ϊ -1����ʾδ�������//��̬�滮����֦��

        function<int(int, int, bool)> f = [&](int i, int cnt1, bool is_limit) -> int {
            if (i == m) 
                return cnt1;
            if (!is_limit && dp[i][cnt1] != -1)
                return dp[i][cnt1];
            int res = 0;//����ͳ��������һλ��1����
            int up = is_limit ? s[i] - '0' : 9;//�����Ͻ� 

            for (int d = 0; d <= up; d++) {
                res += f(i + 1, cnt1 + (d == 1), is_limit && d == up);//cnt1Ϊ�Ѿ�ѡ��1������
                //�Ͻ�Ϊtrue�ĳ��������ǵ�һ��1�ͱ�ѡ�񣬲��Һ���ÿһ�ѡ���˸�λ�����ֵ
            }
            if (!is_limit) dp[i][cnt1] = res; 
            return res;
            // ���������,���������Ƶ�����£�ֻҪ����ͬһλ��ȡ������ͬ��1��������λ����1�ĸ����ĺ���һ���ģ���Ϊ��һλȡֵ����һ���ģ����������������ǲ������Ƶģ���϶�һ����
            // �������λ�������Ƶģ���һλ��ȡֵ�ͱ������ˣ�ֻ��ȡ0~s[i+1]�����ܻ�ʹ��1�ĸ�������
            //������˵һ�£�����λ�����Ƶ����ֻ��һ�Σ�Ҳ����ǰ�涼�������ˣ�
            };
        return f(0, 0, true);
    }
};
//���ֵ�ͣ�����Ҫת���ɶ����ƣ�
class Solution3 {
public:
    long long findMaximumNumber(long long k, int x) { 
        auto check = [&](long long num) {

            //int m = 64 - __builtin_clzll(num);  __builtin_clzll ��������ʶ������⣬
            // ��Ϊ __builtin_clzll �� GCC �� Clang ���������ڲ������������� Visual Studio ���ڲ�������
            unsigned long index;
            unsigned char result = _BitScanReverse64(&index, num);
            int m = index + 1;//������Чλ
            vector<vector<long long>> memo(m, vector<long long>(m + 1, -1));//���ڼ��仯����
            function<long long(int, int, bool)> dfs = [&](int i, int cnt1, bool is_limit) -> long long {
                if (i < 0) return cnt1;
                if (!is_limit && memo[i][cnt1] >= 0) return memo[i][cnt1];
                int up = is_limit ? num >> i & 1 : 1;
                long long res = 0;
                for (int d = 0; d <= up; d++) // ö��Ҫ��������� d
                    res += dfs(i - 1, cnt1 + (d == 1 && (i + 1) % x == 0), is_limit && d == up);
                if (!is_limit) memo[i][cnt1] = res;//���λ�����ƣ�ͬ�����棬��̬�滮��Ϊ�˱����ظ����㣬����ÿһλ�����Ƶ����ֻ��һ�εļ��㣬�������Ƶ�����ķ���ֵ��һ���ģ�����Ŀ�������ȡֵ����������0~1
                return res;
                };
            return dfs(m - 1, 0, true) <= k;
            };

        // ��������֣�ԭ��� https://www.bilibili.com/video/BV1AP41137w7/
        long long left = 0, right = (k + 1) << x;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;//�����������
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
    unsigned long index;//���ڴ������λ�����ı���

    cin >> num;
    int nm1 = bitset<64>(num).count();//����������ж���1
    int nm2 = bitset<32>(num).size();//������Ƶ�λ��
    unsigned char result = _BitScanReverse64(&index, num);//������Ƶ���Чλ�� ,����Ҳ�����Чλ�����Ὣ result ��������Ϊ 0
    //��Ϊ�����ƴ��������Ǵ�0��ʼ�ģ���������Ϊ0��ζ�ŵ�һλ
    int nm3 = index + 1;
    /* 
    unsigned char _BitScanReverse64(
    unsigned long* Index,
        unsigned __int64 Mask
        );
    */
    cout << num << "�ж���λ 1:" << nm1 << endl;
    cout << num << "�ж���λ:" << nm2 << endl;
    cout << num << "�ж�����Чλ:" << nm3 << endl;

    cout << "Number of 1's in binary representation of " << n << ": " << sol1.countDigitOne(n) << endl;
    cout << "Number of 1's in binary representation of " << n << ": " << sol2.countDigitOne(n) << endl;

    cout << "����" << k << "��ֵ�����Ϊ: " << sol4.findMaximumNumber(k, x) << endl;// 7 2
    return 0;
}