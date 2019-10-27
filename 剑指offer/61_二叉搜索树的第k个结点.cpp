/*
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如，(5，3，7，2，4，6，8)中，按结点数值大小顺序第三小结点的值为4。
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if(pRoot == nullptr || k == 0)
        return nullptr;
    stack<TreeNode*> s;
    TreeNode* p = pRoot;
    int count = 1;
    while(p || !s.empty())
    {
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            if(count == k)
                return p;
            count++;
            p = p->right;
        }
    }
    return nullptr;
}