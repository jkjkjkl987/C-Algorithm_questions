#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // ȡ��ͬ�������������������
    cin.tie(0);
    cout.tie(0);

    int t = 0; // ����������
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        int k = 0, x = 0, a = 0;
        cin >> k >> x >> a; // ��ȡ k, x, a ��ֵ

        int sum = 0, q = 0;
        bool ok = true; // ��־λ����ʾ�Ƿ����ڲ��Ʋ��������Ӯ������������Ӳ��

        // �� 0 ѭ���� x����ʾ������������Ĵ���
        for (int i = 0; i <= x; i++) {
            q = sum / (k - 1) + 1; // ������ע��
            sum += q; // �ۼ���ע� sum

            if (sum > a) { // ����Ƿ��Ʋ�
                ok = false; // ����Ʋ��������� ok Ϊ false
                break; // �˳�ѭ��
            }
        }

        // ������
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
