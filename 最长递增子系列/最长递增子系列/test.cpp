#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <vector>

using namespace std;

//求最长递增子序列长度


// 1、 动态规划
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
    // 2、 贪心 + 二分查找 

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
                // 二分查找
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i])  // 目标数d[mid]小，找大区间
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else                    // 找小区间
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
                    if (d[mid] > nums[i])  // 目标数d[mid]小，找大区间
                    {
                        pos = mid;
                        r = mid - 1;
                    }
                    else                    // 找小区间
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
                p.push_back(num); // 更大的尾部，更新了序列的长度
            }
            else 
            {
                auto j = std::lower_bound(p.begin(), p.end(), num); 
                    // p[j](代表长度j+1的序列尾部的最小值)处有更小的尾部可以替代
                    // 这样使得增长更慢，意味着可能更长的增长序列
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


// 输出一条最长递增路径

//核心思想:
//可以在每次遇到一个新元素时检查它是否能连接到每一个桶的尾部元素。
//如果能，则将其放入相应的桶中。如果没有桶的尾部元素能够连接该元素，则新建一个桶。

//但由于输出一条即可，所以遍历到的元素只需要连接上一个桶的尾部连接就行。
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOneLIS(vector<int>& nums) 
    {
        using Node = pair<int, int>;  // 槽位, {父节点在桶中的位置、元素值}
        using Bucket = vector<Node>;  // 桶

        vector<Bucket> buckets;  // 各个列的桶 ( 桶中存放的是对应长度的递增子序列的尾部元素 以及 其父节点的位置 )
        vector<int> p;           // 辅助数组, 冗余各个桶的尾部元素

        // 放入头节点到第一个桶
        buckets.push_back({ {-1, nums[0]} });
        p.push_back(nums[0]);

        // 辅助函数, 给第 k 个桶放入一个新元素
        auto push = [&](int k, int num) 
            {
            // 上个桶的当前尾部节点当做父节点
            int j = (k == 0) ? -1 : (buckets[k - 1].size() - 1); // k>0,j为前一个桶的最后一个元素的索引
            buckets[k].push_back({ j, num }); 
            // 更新辅助数组
            p[k] = num;
            };

        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] > p[p.size() - 1]) 
            {
                // 新建一个空桶, 扩展辅助数组
                buckets.push_back({});
                p.push_back(0);// 为了push中对p[k]尾插，需要开辟一个空间。

                // 加入此元素到新桶 (最后一个桶)
                push(buckets.size() - 1, nums[i]);
            }
            else 
            {
                // 查找合适的桶放入新元素
                int k = lower_bound(p.begin(), p.end(), nums[i]) - p.begin();
                push(k, nums[i]);
            }
        }

        // 要返回最长的上升子序列，需要从"最后一个桶"反向找回去
        vector<int> ans(buckets.size());

        // i 是第 i 个桶，j 父节点在前面一个桶的位置
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