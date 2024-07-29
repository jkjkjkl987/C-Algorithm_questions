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
        vector<int> vis(26), count(26); // vis��¼ջ�е��ַ��Ƿ���ڣ�count��������
        string ans = "";
        for(const char &ch : s) count[ch - 'a']++;
        for(char &ch : s) {
            if(!vis[ch - 'a']) 
            {    // û�м�¼                           
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
            count[ch - 'a'] -= 1;              // ��ջ�ˣ�����-1
        }
        return ans;
    }

    string removeDuplicateLetters_stack(string s)
    {
        unordered_map<char, int> char_count;  // ����Ҫָ����ʼ��С
        for (const char& ch : s) ++char_count[ch];

        vector<int> vis(26, 0);
        stack<char> st;
        for (auto& c : s)
        {
            if (!vis[c - 'a'])      // û�м�¼��ջ��һ������ջ
            {
                while (!st.empty() && st.top() > c)// �ж�ջ��Ԫ���Ƿ���Ҫpop()
                {
                    if (char_count[st.top()] > 0)
                    {
                        vis[st.top() - 'a'] = 0;
                        st.pop();
                    }
                    else
                        break;
                }
                // ��ջ
                st.push(c);
                vis[c - 'a'] = 1;
            }
            --char_count[c]; // ջ���Ѿ���¼�ˣ���ǰ�ַ����Ժ��ԣ���Ϊ֮ǰ�Ѿ��ź�����
        }
        // ��������ַ���
        string ans;
        while (!st.empty())
        {
            char c = st.top();
            st.pop();
            ans.insert(ans.begin(), c); // ͷ�巨
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