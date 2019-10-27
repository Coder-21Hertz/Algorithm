/*
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//后序遍历，即先求左右子树的高度，在返回来求高度差（相当于父节点的高度）
bool getDepth(TreeNode* root, int &dep) //要用引用
{
    if(root == nullptr)
        return true;
    int left=0, right=0;
    if(getDepth(root->left, left) && getDepth(root->right, right))
    {
        int dif = left-right;   //高度差
        if(dif<-1 || dif>1)
            return false;
        dep = (left>right ? left : right)+1;    //求高度
        return true;
    }
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
    int dep = 0;
    return getDepth(pRoot, dep);
}