/*
 * 链表的赋值：深拷贝的应用
 */
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

void insert(ListNode*& pHead, int x)
{
    ListNode* p=pHead;
    while(p->next != nullptr)
        p = p->next;
    ListNode* q = new ListNode(x);
    p->next = q;
}

ListNode* CopyList(ListNode* pHead)
{
    ListNode* ans = new ListNode(pHead->val);   //这个用来返回，不能移动，而且这个不能用=pHead，否则就指向同一个指针了（浅拷贝）
    ListNode* p= ans;
    pHead = pHead->next;
    while(pHead != nullptr)
    {
        ListNode* q = new ListNode(pHead->val);
        p->next = q;
        p = p->next;        //记住这两部的指向下一个结点
        pHead = pHead->next;
    }
    return ans;
}

void print(ListNode* pHead)
{
    while(pHead)
    {
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8,9};
    ListNode* root = new ListNode(0);
    for(int i=0; i< arr.size(); i++)
    {
        insert(root ,arr[i]);
    }
    ListNode*p = CopyList(root);
    insert(p, 10);
    print(root);
    print(p);
}