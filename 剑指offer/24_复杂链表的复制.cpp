/*
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
 * 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 * 需要考虑的一个结果：由于随机结点指向的是链表中的结点，很可能在创建当前结点时，这个结点的特殊指针还没创建
 */
#include <bits/stdc++.h>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {}
};

RandomListNode* Clone(RandomListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    RandomListNode* pCur = pHead;
    //复制next 如原来是A->B->C 变成A->A'->B->B'->C->C'
    //这一步同时也改变了原来的链表，所以思考画图的时候，复制结点要考虑后面的所有结点
    while(pCur != nullptr)
    {
        RandomListNode* q = new RandomListNode(pCur->label);//这里用的是pCur
        q->next = pCur->next;   //把后面的结点赋给q->next
        pCur->next = q;
        pCur = pCur->next->next;    //复制了所以指向下下个结点
    }
    pCur = pHead;   //重新指向头结点
    //复制random结点
    while(pCur != nullptr)
    {
        if(pCur->random != nullptr)
            pCur->next->random = pCur->random->next;    //注意后面要指向next
        pCur = pCur->next->next;
    }
    pCur = pHead;
    //拆分链表，分为原链表和复制的链表
    RandomListNode* head = pHead->next;  //用来返回的
    RandomListNode* p = head;         //用来移动的
    while(pCur != nullptr)
    {
        pCur->next = pCur->next->next;
        if(p->next != nullptr)
            p->next = p->next->next;
        pCur = pCur->next;
        p = p->next;
    }
    return head;
}
