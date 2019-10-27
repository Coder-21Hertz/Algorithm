/*
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
};

bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if(pRoot2 == nullptr)
        return true;    //子结构已经到最后一个结点
    if(pRoot1 == nullptr)
        return false;
    if(pRoot1->val == pRoot2->val)
        return isSubtree(pRoot1->left, pRoot2->left)
            && isSubtree(pRoot1->right, pRoot2->right);
    else
        return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    return isSubtree(pRoot1, pRoot2)
        || HasSubtree(pRoot1->left, pRoot2)
        || HasSubtree(pRoot1->right, pRoot2);
}