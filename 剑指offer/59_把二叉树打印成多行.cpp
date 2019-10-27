/*
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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

vector<vector<int> > Print(TreeNode* pRoot)
{
    vector<vector<int>> ans;
    if(pRoot == nullptr)
        return ans;
    queue<TreeNode*> s;
    s.push(pRoot);
    while(!s.empty())
    {
        vector<int> tmp;
        int len = s.size();
        while(len--)
        {
            pRoot = s.front(); s.pop();
            tmp.push_back(pRoot->val);
            if(pRoot->left)  s.push(pRoot->left);
            if(pRoot->right) s.push(pRoot->right);
        }
        ans.push_back(tmp);
    }
    return ans;
}