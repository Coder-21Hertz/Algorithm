/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

/* 非递归：根据结点是最后输出的特点*/
bool VerifySquenceOfBST(vector<int> sequence)
{
    int len = sequence.size();
    if(len == 0)
        return false;
    int i=0;
    while(--len)
    {
        while(sequence[i] < sequence[len]) i++;
        while(sequence[i] > sequence[len]) i++;
        if(i < len)
            return false;
        i=0;
    }
    return true;
}

/* 递归*/
bool judge(vector<int>arr, int low, int high)
{
    if(low >= high)
        return true;    //注意返回的是true
    int r=high-1;
    while(r>low && arr[r] > arr[high]) r--;
    for(int i=r-1; i>=low; i--)     //注意是和low比较
        if(arr[i] > arr[high])      //一但有大于的就返回false
            return false;

    return judge(arr, low, r-1) && judge(arr, r, high-1);   //注意后面这个
}

bool VerifySquenceOfBST1(vector<int> sequence)
{
    if(sequence.size() == 0)
        return false;
    return judge(sequence, 0, sequence.size()-1);
}