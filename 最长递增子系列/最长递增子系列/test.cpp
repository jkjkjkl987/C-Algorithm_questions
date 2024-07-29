#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <vector>

using namespace std;

//������������г���


// 1�� ��̬�滮
class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) 
    {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) 
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) 
            {
                if (nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    // 2�� ̰�� + ���ֲ��� 

    int lengthOfLIS2(vector<int>& nums) {

        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] > d[len])
            {
                d[++len] = nums[i];
            }
            else
            {
                // ���ֲ���
                int l = 1, r = len, pos = 0; // ����Ҳ���˵�����е������� nums[i] �󣬴�ʱҪ���� d[1]���������ｫ pos ��Ϊ 0
                
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i])  // Ŀ����d[mid]С���Ҵ�����
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else                    // ��С����
                    {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
                
                /*
                pos = 1;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] > nums[i])  // Ŀ����d[mid]С���Ҵ�����
                    {
                        pos = mid;
                        r = mid - 1;
                    }
                    else                    // ��С����
                    {
                        l = mid + 1;
                    }
                }
                d[pos] = nums[i];
                */
            }
        }
        return len;
    }


    int lengthOfLIS2_(std::vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        std::vector<int> p{ nums[0] };

        for (int i = 1; i < nums.size(); i++) 
        {
            int num = nums[i];
            if (num > p.back()) 
            {
                p.push_back(num); // �����β�������������еĳ���
            }
            else 
            {
                auto j = std::lower_bound(p.begin(), p.end(), num); 
                    // p[j](������j+1������β������Сֵ)���и�С��β���������
                    // ����ʹ��������������ζ�ſ��ܸ�������������
                *j = num;
            }
        }
        return p.size();
    }
};



int main()
{
    vector<int> v1 = { 10,9,2,5,3,7,101,18 };
    vector<int> v2 = { 0,1,0,3,2,3 };
    vector<int> v3 = { 7,7,7,7,7,7,7 };

    Solution test;
    cout << test.lengthOfLIS1(v1) << endl;
    cout << test.lengthOfLIS1(v2) << endl;
    cout << test.lengthOfLIS1(v3) << endl;
    cout << endl;
    cout << test.lengthOfLIS2(v1) << endl;
    cout << test.lengthOfLIS2(v2) << endl;
    cout << test.lengthOfLIS2(v3) << endl;
    cout << endl;
    cout << test.lengthOfLIS2_(v1) << endl;
    cout << test.lengthOfLIS2_(v2) << endl;
    cout << test.lengthOfLIS2_(v3) << endl;

    return 0;
}

#endif 




/////////////////////////////////////////////////////////////////////////


// ���һ�������·��

//����˼��:
//������ÿ������һ����Ԫ��ʱ������Ƿ������ӵ�ÿһ��Ͱ��β��Ԫ�ء�
//����ܣ����������Ӧ��Ͱ�С����û��Ͱ��β��Ԫ���ܹ����Ӹ�Ԫ�أ����½�һ��Ͱ��

//���������һ�����ɣ����Ա�������Ԫ��ֻ��Ҫ������һ��Ͱ��β�����Ӿ��С�
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOneLIS(vector<int>& nums) 
    {
        using Node = pair<int, int>;  // ��λ, {���ڵ���Ͱ�е�λ�á�Ԫ��ֵ}
        using Bucket = vector<Node>;  // Ͱ

        vector<Bucket> buckets;  // �����е�Ͱ ( Ͱ�д�ŵ��Ƕ�Ӧ���ȵĵ��������е�β��Ԫ�� �Լ� �丸�ڵ��λ�� )
        vector<int> p;           // ��������, �������Ͱ��β��Ԫ��

        // ����ͷ�ڵ㵽��һ��Ͱ
        buckets.push_back({ {-1, nums[0]} });
        p.push_back(nums[0]);

        // ��������, ���� k ��Ͱ����һ����Ԫ��
        auto push = [&](int k, int num) 
            {
            // �ϸ�Ͱ�ĵ�ǰβ���ڵ㵱�����ڵ�
            int j = (k == 0) ? -1 : (buckets[k - 1].size() - 1); // k>0,jΪǰһ��Ͱ�����һ��Ԫ�ص�����
            buckets[k].push_back({ j, num }); 
            // ���¸�������
            p[k] = num;
            };

        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] > p[p.size() - 1]) 
            {
                // �½�һ����Ͱ, ��չ��������
                buckets.push_back({});
                p.push_back(0);// Ϊ��push�ж�p[k]β�壬��Ҫ����һ���ռ䡣

                // �����Ԫ�ص���Ͱ (���һ��Ͱ)
                push(buckets.size() - 1, nums[i]);
            }
            else 
            {
                // ���Һ��ʵ�Ͱ������Ԫ��
                int k = lower_bound(p.begin(), p.end(), nums[i]) - p.begin();
                push(k, nums[i]);
            }
        }

        // Ҫ����������������У���Ҫ��"���һ��Ͱ"�����һ�ȥ
        vector<int> ans(buckets.size());

        // i �ǵ� i ��Ͱ��j ���ڵ���ǰ��һ��Ͱ��λ��
        for (int i = buckets.size() - 1, j = -1; i >= 0; i--)
        {
            const auto& b = buckets[i];
            const auto& pair = b[j < 0 ? (b.size() - 1) : j];
            j = pair.first;
            ans[i] = pair.second;
        }
        

        return ans;
    }
};

int main()
{
    Solution test;
    vector<int> nums1 = { 8,10,2,9,6,13,1,9,5,12,3,10,16 };
    vector<int> nums2 = { 4,2,7,6,8,3,5,6 };
    vector<int> nums3 = { 8,10,2,9,6,13,1,9,5,12,3,10,7,9,11 };
    auto res1 = test.findOneLIS(nums1);
    auto res2 = test.findOneLIS(nums2);
    auto res3 = test.findOneLIS(nums3);

    for (auto e : res1)
        cout << e << " ";// 2 6 9 10 16

    cout << endl;

    for (auto e : res2)
        cout << e << " ";// 2 3 5 6

    cout << endl;

    for (auto e : res3)
        cout << e << " ";// 1 3 7 9 11

    return 0;
}