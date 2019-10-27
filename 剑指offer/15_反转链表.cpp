/*
 * 输入一个链表，反转链表后，输出新链表的表头。
 */
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode *fun(ListNode* pHead)
{
    ListNode *pnew=nullptr;
    ListNode *pnext=nullptr;
    while(pHead)
    {
        pnext = pHead->next;
        pHead->next=pnew;
        pnew = pHead;
        pHead = pnext;
    }
    return pnew;    //注意这个返回值，因为pHead在最后会指向null
}