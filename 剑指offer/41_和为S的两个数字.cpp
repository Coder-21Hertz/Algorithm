/*
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 * 对应每个测试案例，输出两个数，小的先输出。
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * 数列满足递增，设两个头尾两个指针i和j，
 * 若ai + aj == sum，就是答案（相差越远乘积越小，x+y=c，y=-x+c，画图，求的就是x*y的矩形面积大小，同时有正方形>长方形）
 * 若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j--
 * 若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i++
 */
vector<int> FindNumbersWithSum(vector<int> arr,int sum)
{
    vector<int> res;
    if(arr.empty())
        return res;
    int i=0, j=arr.size()-1;
    while(i < j)
    {
        if(arr[i]+arr[j] == sum)
        {
            res.push_back(arr[i]);
            res.push_back(arr[j]);
            break;
        }
        while(i < j && arr[i]+arr[j] > sum) j--;
        while(i < j && arr[i]+arr[j] < sum) i++;
    }
    return res;
}