/*
 * @Description:
 * @Company: SZU
 * @Author: PerkyRookie
 * @Date: 2019-08-11 11:07:30
 * @LastEditors: PerkyRookie
 * @LastEditTime: 2019-08-11 12:34:30
 */
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

/*
 * 层序遍历的使用，即从上到下打印子树
 */
struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
        : value(val), left(nullptr), right(nullptr){}
};

/*
 * 层序遍历
 */
vector<int> printnode(TreeNode* root)
{
    vector<int> ans;
    if(root == nullptr)
        return ans;

    queue<TreeNode*> q;
    TreeNode* p = nullptr;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        ans.push_back(p->value);
        q.pop();
        if(p->left)  q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return ans;
}
/*
 * 第一种，计算二叉树每层最大个数的宽度
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

/*
 * 第二种，计算二叉树的最大宽度，需要加入中间的null
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/submissions/
 */
int MaxWidth1(TreeNode* root)
{
    if(root == nullptr)
        return 0;

    deque<TreeNode*> q;
    TreeNode* p = nullptr;
    int maxwidth = 1;
    q.push_back(root);
    while(!q.empty())
    {
        //去除两端的null
        while(!q.empty() && q.front() == nullptr) q.pop_front();
        while(!q.empty() && q.back()  == nullptr) q.pop_back();
        int n = q.size();
        if(n == 0) break;       //注意这里的跳出循环
        maxwidth = max(maxwidth, n);
        for(int i=0; i<n; i++)
        {
            p = q.front();
            q.pop_front();
            q.push_back(p==nullptr ? nullptr : p->left);    //null也要入队列
            q.push_back(p==nullptr ? nullptr : p->right);
        }
    }
    return maxwidth;
}

int main()
{

}