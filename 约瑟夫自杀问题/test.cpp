#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

int FindendPeo(ListNode* p, int m) {
    int count = 1;
    ListNode* pre = nullptr;
    ListNode* cur = p;
    while (cur->next != cur) {
        if (count == m) {
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
            count = 1;
        }
        else {
            pre = cur;
            cur = cur->next;
            count++;
        }
    }
    return cur->val;
}

//头插建环
ListNode* _InitList(int len) {
    ListNode* head = nullptr;
    int m = 1;
    while (m <= len) {
        ListNode* newnode = new ListNode;
        newnode->val = len - m + 1;
        newnode->next = head;
        head = newnode;
        m++;
    }
    ListNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head;
    return head;
}

//尾插建环
ListNode* InitList_(int len)
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int m = 0;
    while (++m < len)
    {

    }
}
void PrintList(ListNode* p,int len)
{
    while (len--)
    {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << endl;;
}
int main() {
    int m, n;
    cin >> m >> n;
    ListNode* P = _InitList(m);
    PrintList(P,m);
    cout << FindendPeo(P, n);

    return 0;
}
