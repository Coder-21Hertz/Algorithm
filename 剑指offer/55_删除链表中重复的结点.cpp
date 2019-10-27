/*
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    ListNode* q = pHead;

    while(q)
    {
        while(q && q->next && q->val == q->next->val)   //这里要用while，防止出现3->3->4->4现象
        {
            int tmp = q->val;
            while(q && q->val == tmp)
            {
                ListNode* oldNode = q;
                q = q->next;
                delete oldNode;
            }
        }
        p->next = q;
        p = p->next;
        if(q)       //因为当前可能会是null，当前为null时，q->next就越界了
            q = q->next;
    }
    ListNode* newNode = head->next;
    delete head;
    return newNode;
}