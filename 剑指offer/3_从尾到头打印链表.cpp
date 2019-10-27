/*
 * 输入一个链表，按链表值从尾到头的顺序返回一个vector。
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

vector<int> printListFromTailToHead(ListNode* head)
{
    stack<int> s;
    vector<int> arr;
    while(head)
    {
        s.push(head->val);
        head = head->next;
    }
    while(!s.empty())
    {
        arr.push_back(s.top());
        s.pop();
    }
    return arr;
}