/*
 * 输入一个链表，输出该链表中倒数第k个结点。
 */
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value) : val(value), next(nullptr){}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k==0)
        return nullptr;
    ListNode* it1 = pListHead;
    ListNode* it2 = pListHead;
    for(int i=0; i<k; i++)  //先让一个指针先跑k位
    {
        if(it1 != nullptr)
            it1 = it1->next;
        else
            return nullptr;
    }
    while(it1 != nullptr)   //第二个指针也开始跑，这样先跑的始终比后跑的快k个，跑完后就是倒数第k个
    {
        it1 = it1->next;
        it2 = it2->next;
    }
    return it2;
}