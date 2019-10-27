/*
 * 层序遍历：
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

vector<int> PrintFromTopToBottom(TreeNode* root)
{
    vector<int> arr;
    if(root == nullptr)
        return arr;

    queue<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        root = s.front();
        s.pop();
        arr.push_back(root->val);
        if(root->left) s.push(root->left);
        if(root->right) s.push(root->right);
    }
    return arr;
}

int main()
{

}