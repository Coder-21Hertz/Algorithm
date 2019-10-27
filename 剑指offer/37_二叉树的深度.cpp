/*
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的
 * 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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

/* 利用层序遍历*/
int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;
    TreeNode* p=pRoot;
    queue<TreeNode*> s;
    s.push(p);
    int depth=0;
    while(!s.empty())
    {
        int len = s.size();
        depth++;
        while(len--)
        {
            p = s.front();
            s.pop();
            if(p->left)  s.push(p->left);
            if(p->right) s.push(p->right);
        }
    }
    return depth;
}




/*
 * 计算二叉树最大个数的宽度
 * 原理是一次性把队列中结点的子树全部入队
 *  [求二叉树的深度和宽度](https://blog.csdn.net/qinghezhen/article/details/12857717)
 */
int MaxWidth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    queue<TreeNode*> q;
    TreeNode *p=nullptr;
    int maxwidth = 1;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        maxwidth = max(maxwidth, n);
        for(int i=0; i<n; i++)
        {
            p = q.front();
            q.pop();
            if(p->left)  q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return maxwidth;
}