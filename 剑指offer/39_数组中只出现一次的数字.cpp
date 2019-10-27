/*
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
#include <bits/stdc++.h>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
{

}

/* 哈希表法*/
void FindNumsAppearOnce1(vector<int> data,int* num1,int *num2)
{
    if(data.empty())
        return;
    unordered_map<int, int> mp;
    for(int i=0; i<data.size(); i++)
        mp[data[i]]++;
    for(auto w : mp)
    {
        if(w.second == 1)
        {
            *num2 = *num1;
            *num1 = w.first;
        }
    }
}

int main()
{
    vector<int> arr{1,1,2,3,4,4};
    int num1, num2;
    FindNumsAppearOnce(arr, &num1, &num2);
    cout << num1 << " " << num2 << endl;
}