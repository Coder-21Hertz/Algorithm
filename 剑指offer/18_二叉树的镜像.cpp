/*
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 * 二叉树的镜像定义：源二叉树
 *     	     8
 *   	   /  \
 *   	  6   10
 *  	 / \  / \
 *   	5  7 9 11
 *   	镜像二叉树
 *   	     8
 *   	   /  \
 *   	  10   6
 *   	 / \  / \
 *   	11 9 7  5
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) :
        val(value), left(nullptr), right(nullptr);
};

void Mirror(TreeNode *pRoot)
{
    if(pRoot == nullptr)
        return nullptr;
    TreeNode* p = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = p;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

void Mirror1(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;
    TreeNode* p = pRoot;
    stack<TreeNode*> s;
    s.push(p);
    while(!s.empty())
    {
        p = s.top();
        s.pop();
        TreeNode* q=p->left;
        p->left = p->right;
        p->right = q;
        if(p->left) s.push(p->left);
        if(p->right) s.push(p->right);
    }
}
