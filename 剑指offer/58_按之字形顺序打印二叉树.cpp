/*
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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

/*
 * 双端队列，一次头出，一次尾出
 */
vector<vector<int> > Print(TreeNode* pRoot)
{
    vector<vector<int>> ans;
    if(pRoot == nullptr)
        return ans;
    deque<TreeNode*> s;
    s.push_back(pRoot);
    int flag = 1;
    while(!s.empty())
    {
        vector<int> tmp;
        int len = s.size();
        if(flag == 1)
        {
            flag = 0;
            while(len--)
            {
                pRoot = s.front(); s.pop_front();
                tmp.push_back(pRoot->val);
                if(pRoot->left)  s.push_back(pRoot->left);
                if(pRoot->right) s.push_back(pRoot->right);
            }
        }
        else
        {
            flag = 1;
            while(len--)
            {
                pRoot = s.back(); s.pop_back();
                tmp.push_back(pRoot->val);
                if(pRoot->right) s.push_front(pRoot->right);
                if(pRoot->left)  s.push_front(pRoot->left);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}