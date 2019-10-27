/*
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 */
#include <bits/stdc++.h>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
 * 1.二叉树为空，则返回空；
 * 2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
 * 3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果；
 * 4.节点是根结点，其之前已经判断过没有有孩子，则1返回空。
 */
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;
    if(pNode->right != nullptr)
    {
        TreeLinkNode* p = pNode->right;
        while(p->left)
            p = p->left;
        return p;
    }
    while(pNode->next != nullptr)   //这里是while
    {
        if(pNode == pNode->next->left)  //如果是左孩子
            return pNode->next;
        pNode = pNode->next;
    }
    return nullptr;
}