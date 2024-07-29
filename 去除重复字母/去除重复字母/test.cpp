#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), count(26); // vis记录栈中的字符是否存在，count用来计数
        string ans = "";
        for(const char &ch : s) count[ch - 'a']++;
        for(char &ch : s) {
            if(!vis[ch - 'a']) 
            {    // 没有记录                           
                while(!ans.empty() && ans.back() > ch) 
                {          
                    if(count[ans.back() - 'a'] > 0)
                    {
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else 
                    {
                        break;
                    }
                }
                ans.push_back(ch);
                vis[ch - 'a'] = 1;
            }
            count[ch - 'a'] -= 1;              // 入栈了，计数-1
        }
        return ans;
    }

    string removeDuplicateLetters_stack(string s)
    {
        unordered_map<char, int> char_count;  // 不需要指定初始大小
        for (const char& ch : s) ++char_count[ch];

        vector<int> vis(26, 0);
        stack<char> st;
        for (auto& c : s)
        {
            if (!vis[c - 'a'])      // 没有记录到栈中一定会入栈
            {
                while (!st.empty() && st.top() > c)// 判断栈中元素是否需要pop()
                {
                    if (char_count[st.top()] > 0)
                    {
                        vis[st.top() - 'a'] = 0;
                        st.pop();
                    }
                    else
                        break;
                }
                // 入栈
                st.push(c);
                vis[c - 'a'] = 1;
            }
            --char_count[c]; // 栈中已经记录了，当前字符可以忽略，因为之前已经排好升序
        }
        // 构建结果字符串
        string ans;
        while (!st.empty())
        {
            char c = st.top();
            st.pop();
            ans.insert(ans.begin(), c); // 头插法
        }
        return ans;
    }

};



int main()
{
    Solution test;
    string s("cbacdcbc");
    cout << test.removeDuplicateLetters(s) << endl;
    cout << test.removeDuplicateLetters_stack(s) << endl;

    return 0;
}