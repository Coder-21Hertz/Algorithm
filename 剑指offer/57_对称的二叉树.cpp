/*
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {}
};

bool isSymmetrical(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return true;
    queue<TreeNode*> s;
    s.push(pRoot->left);
    s.push(pRoot->right);
    while(!s.empty())
    {
        TreeNode* p = s.front(); s.pop();
        TreeNode* q = s.front(); s.pop();
        if(p==nullptr && q==nullptr) continue;
        if(p==nullptr || q==nullptr) return false;
        if(p->val != q->val) return false;

        s.push(p->left);
        s.push(q->right);
        s.push(p->right);
        s.push(q->left);
    }
    return true;
}