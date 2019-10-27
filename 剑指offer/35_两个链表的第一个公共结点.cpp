/*
 * 输入两个链表，找出它们的第一个公共结点。
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getlength(ListNode* pHead)
{
    int len = 0;
    while(pHead)
    {
        pHead = pHead->next;
        len++;
    }
    return len;
}

/* 记长度法*/
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr || pHead1 == nullptr)
        return nullptr;
    int len1 = getlength(pHead1);
    int len2 = getlength(pHead2);
    int len = len1-len2;
    if(len > 0)     //长的先走
    {
        while(len--)
            pHead1 = pHead1->next;
    }
    else
    {
        while(len++)
            pHead2 = pHead2->next;
    }
    while(pHead1 != pHead2)
    {
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }
    return pHead1;
}

/*
 * 不用记长度，类似循环链表，最多遍历两次最长链表即可
 * --------------          --------------
 * ----------   循环肯定会变成   ----------
 */
ListNode* FindFirstCommonNode1(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr || pHead1 == nullptr)
        return nullptr;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while(p1 != p2)
    {
        p1 = (p1 == nullptr ? pHead2 : p1->next);
        p2 = (p2 == nullptr ? pHead1 : p2->next);
    }
    return p1;
}