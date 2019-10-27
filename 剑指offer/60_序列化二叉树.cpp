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
char* Serialize(TreeNode *root)
{
    string str;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(p || !s.empty())
    {
        while(p)
        {
            str += to_string(p->val) + '!';
            s.push(p);
            p = p->left;
        }
        str += "#!";
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    str += "#!";
    /* 复制字符串，strdup()会先用maolloc()配置与参数s 字符串相同的空间大小，
    然后将参数s 字符串的内容复制到该内存地址，然后把该地址返回。该地址最后可以利用free()来释放。*/
    char *ans = strdup(str.c_str());
    return ans;
}


TreeNode* Deserialize(char *&str)
{
    TreeNode* p=NULL;
    int num=0;
    if(str[0]=='#'){
        str=str+2;
        return NULL;
    }
    while(*str!='!'){
        num=num*10+(*str-'0');
        str++;
    }
    str++;
    p=new TreeNode(num);
    p->left=Deserialize(str);
    p->right=Deserialize(str);
    return p;
}