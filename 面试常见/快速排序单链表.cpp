/*
 * 由于链表只能顺序索引，故不能使用数组划分的方法。
 * 将比基元小的节点的值，依次和基元后的节点的值交换。
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int value;
    ListNode *next;

    ListNode(const int &val) : value(val), next(nullptr){}
};

/*插入 */
void install_back(ListNode *&pHead, int value)
{
    ListNode *s = pHead;

    while (s->next)
        s = s->next;

    ListNode *p = (ListNode*) malloc (sizeof(ListNode));
    p->value = value;
    p->next = nullptr;
    s->next = p;
}

/*插入 */
void install_back(ListNode *&pHead, int value, int i)
{
    ListNode *s = pHead;
    int j=1;
    while (s && j<i)
    {
        s = s->next;
        j++;
    }
    ListNode *p = (ListNode*) malloc(sizeof(ListNode));
    p->value = value;
    p->next = s->next;  //这部有区别
    s->next = p;
}
/*遍历 */
void print_list(ListNode *pHead)
{
    while(pHead != nullptr)
    {
        cout << pHead->value << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

/*排序 */
ListNode *Partation(ListNode *pBegin, ListNode *pEnd)
{
    if(pBegin == pEnd)
        return pBegin;
    int key = pBegin->value;
    ListNode *p=pBegin;
    for(ListNode *q=p->next; q!=pEnd; q=q->next)
    {
        if(q->value < key)  //
        {
            p = p->next;
            swap(p->value, q->value);
        }
    }
    swap(p->value, pBegin->value);
    return p;
}

void QuickSort(ListNode *pBegin, ListNode *pEnd)
{
    if(pBegin == pEnd)
        return;
    ListNode *pMid = Partation(pBegin, pEnd);
    QuickSort(pBegin, pMid);
    QuickSort(pMid->next, pEnd);
}
void QuickSort(ListNode *p)
{
    QuickSort(p, nullptr);
}

int main()
{
    ListNode *p = new ListNode(0);
    vector<int> arr{3,2,5,6,4,1};
    for(auto i : arr)
        install_back(p, i);

    QuickSort(p);
    print_list(p);
}