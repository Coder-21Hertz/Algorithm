#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x) :val(x){}
};
/*
 * 1 -> 2 -> 3 -> 4 -> NULL;
 * NULL <- 1 -> 2...
 * NULL <- 1 <- 2 -> 3...
 * ......
 * NULL <- 1 <- 2 <- 3 <- 4
 */
ListNode* reverseList(ListNode* h)
{
    if(h == NULL || h->next == NULL)
        return h;

    ListNode *p = h;
    ListNode *pnew = NULL;

    while(p != NULL)
    {
        ListNode *pnext = p->next;
        p->next = pnew; //翻转指向

        pnew = p;   //让位结点指向当前
        p = pnext;  //操作下一个
    }
    return pnew;    //注意这里返回的结点
}


void printList(ListNode* head)
{
	ListNode * p = head;
	while (p != NULL)
	{
		cout << p->val<< " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    ListNode* head = first;
    printList(head);
    head = reverseList(head);    //翻转
    printList(head);

    return 0;
}