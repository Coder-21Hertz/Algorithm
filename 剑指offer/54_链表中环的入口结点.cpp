/*
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 * 题解：
 * https://www.nowcoder.com/questionTerminal/253d2c59ec3e4bc68da16833f79a38e4?toCommentId=1444359
 * 设：
 * 链表头到环入口长度为--a
 * 环入口到相遇点长度为--b
 * 相遇点到环入口长度为--c
 * 相遇时：
 * 快指针路程=a+(b+c)k+b，k>=1  其中b+c为环的长度，需要多走b长度，k为绕环的圈数（
 * k>=1,即最少一圈，不能是0圈，不然和慢指针走的一样长，矛盾）。
 * 慢指针路程=a+b
 * 快指针走的路程是慢指针的两倍，所以：(a+b)*2=a+(b+c)k+b
 * 化简可得：a=(k-1)(b+c)+c
 * 这个式子的意思是：链表头到环入口的距离=相遇点到环入口的距离+（k-1）圈环长度。其中k>=1,所以k-1>=0圈。
 * **因为(k-1)(b+c)表示圈数，所以可以看成 相遇点+c=环的入口=a
 * 所以两个指针分别从链表头和相遇点出发，最后一定相遇于环入口。
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == nullptr || pHead->next == nullptr)
        return nullptr;
    ListNode* p = pHead;
    ListNode* q = pHead;
    while(q != nullptr && q->next != nullptr)
    {
        p = p->next;
        q = q->next->next;
        if(p == q)
            break;
    }
    q = pHead;
    while(p != q)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}

/* 哈希表法*/
ListNode* EntryNodeOfLoop1(ListNode* pHead)
{
    if(pHead == nullptr || pHead->next == nullptr)
        return nullptr;
    unordered_map<ListNode*, int> mp;
    ListNode* p=pHead;
    while(p != nullptr)
    {
        if(mp[p]++ == 2)
            return p;
        p = p->next;
    }
    return nullptr;
}