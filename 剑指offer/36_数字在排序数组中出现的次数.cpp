/*
 * 统计一个数字在排序数组中出现的次数。
 * 注意会重复，找的是次数
 */
#include <bits/stdc++.h>
using namespace std;

int findnum(vector<int> &data, double k)
{
    int i=0, j=data.size()-1;
    while(i <= j)
    {
        int mid = i+(j-i)/2;
        if(k < data[mid])
            j = mid-1;
        else if(k > data[mid])
            i = mid+1;
    }
    return i;
}

/*因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
  不能找+1和-1的因为其他数字也会重复*/
int GetNumberOfK(vector<int> data ,int k)
{
    return findnum(data, k+0.5) - findnum(data, k-0.5);
}

int main()
{
    vector<int> arr{1,2,2,3,4,5,6,7,8,9,10};
    cout << GetNumberOfK(arr, 2) << endl;
}