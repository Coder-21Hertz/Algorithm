/*
 * 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 * (注意: 在返回值的list中，数组长度大的数组靠前)
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};


/*
 * 非递归法：后序遍历
 * 1.进栈时候，把值同时压入路径的向量数组，修正路径的和
 * 2.出栈时候，先判断和是否相等，且该节点是否是叶节点，
 * 判断完成后保持和栈一致，抛出路径，修改路径的和
 * 3.向量数组和栈的操作要保持一致
 */
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    stack<TreeNode*> s;
    vector<int> v;
    vector<vector<int> > res;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            v.push_back(root->val);
            expectNumber -= root->val;
            //能左就左，否则向右
            root = root->left ? root->left : root->right;
        }
        root = s.top();
        if (expectNumber == 0 && root->left == NULL && root->right == NULL)
            res.push_back(v);

        s.pop();
        v.pop_back();
        expectNumber += root->val;
        //右子数没遍历就遍历，如果遍历就强迫出栈
        if (!s.empty() && s.top()->left == root)    //root在前面赋值过，不是左子树就是右子树
            root = s.top()->right;
        else
            root = NULL;//强迫出栈
    }
    return res;
}