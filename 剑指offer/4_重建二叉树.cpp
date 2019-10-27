/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}
 * 和中序遍历序列     {4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * https://www.cnblogs.com/edisonchou/p/4741099.html
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //根据先序和中序遍历重建二叉树
    TreeNode* reTree(vector<int> &pre, vector<int> &vin){
        if(pre.empty() || vin.empty() || pre.size() != vin.size())
            return NULL;

        int root = pre[0];         //前序序列的第一个一定是头结点
        TreeNode* proot = new TreeNode(root);   //创建二叉树

        vector<int> preL, preR, vinL, vinR;
        int i = 1, j = 0;
        while(vin[j] != root){          //中序数组进行遍历分为左右两部分，即为左右子树，可参考上述链接
            preL.push_back(pre[i++]);
            vinL.push_back(vin[j++]);
        }
        j++;
        while(j < vin.size()){
            preR.push_back(pre[i++]);
            vinR.push_back(vin[j++]);
        }
        if(!preL.empty() && !vinL.empty())  //递归退出条件
            proot->left = reTree(preL,vinL);
        if(!preR.empty() && !vinR.empty())
            proot->right = reTree(preR, vinR);
        return proot;
    }
    //根据中序和后序遍历重建二叉树
    TreeNode* reTree1(vector<int> &post, vector<int> &vin){
        if(post.empty() || vin.empty() || post.size() != vin.size())
            return NULL;

        int len=post.size();
        int root=post[len-1]; //第一个结点
        TreeNode* proot=new TreeNode(root);

        vector<int> postL,postR,vinL,vinR;
        int i=0,j=0;
        while(vin[j] != root)
        {
            postL.push_back(post[i++]);
            vinL.push_back(vin[j++]);
        }
        j++;
        while(j<vin.size())
        {
            postR.push_back(post[i++]);
            vinR.push_back(vin[j++]);
        }
        if(!postL.empty() && !vinL.empty())
            proot->left=reTree1(postL, vinL);
        if(!postR.empty() && !vinR.empty())
            proot->right=reTree1(postR, vinR);
        return proot;
    }
};

void PostOrder(TreeNode* root)
{
    if(root==nullptr)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}
void preOrder(TreeNode *t)
{
    if(t != nullptr)
    {
        cout << t->val << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

int main()
{
    vector<int> pre {1,2,4,5,7,8,10,3,6,9};
    vector<int> post{4,7,10,8,5,2,9,6,3,1};
    vector<int> vin {4,2,7,5,8,10,1,3,9,6};
    TreeNode* root;
    Solution s;
    root = s.reTree1(post,vin);
    preOrder(root);
    cout << endl;
    root = s.reTree(pre,vin);
    PostOrder(root);
}