/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;

    ListNode* p = nullptr;  //这个用来记录头结点的，用来返回
    ListNode* head = nullptr;
    if(pHead1->val < pHead2->val)       //设置最初始的一个结点
    {                                   //有些教程把这个放到while循环里面，这样会加大运算量，每次都要判断一次
        p = head = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        p = head = pHead2;
        pHead2 = pHead2->next;
    }

    while(pHead1 != nullptr && pHead2 != nullptr)   //这里是&&
    {
        if(pHead1->val < pHead2->val)
        {
            head->next = pHead1;    //这里用的是next
            pHead1 = pHead1->next;
        }
        else
        {
            head->next = pHead2;
            pHead2 = pHead2->next;
        }
        head = head->next;
    }
    if(pHead1 != nullptr)
        head->next = pHead1;
    if(pHead2 != nullptr)
        head->next = pHead2;

    return p;
}