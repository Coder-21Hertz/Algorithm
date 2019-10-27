/*
 * n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人 继续从0开始报数。求胜利者的编号
 */
#include <bits/stdc++.h>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n==0 || m==0)
        return -1;
    vector<int> arr;

    for(int i=0; i<n; i++)
        arr.push_back(i);
    int index = 0;
    while(arr.size() > 1)
    {
        index = (m+index-1) % arr.size();   //要删除的元素下标
        arr.erase(arr.begin()+index);
    }
    return arr[0];
}