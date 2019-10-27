/*
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 */
#include <bits/stdc++.h>
using namespace std;

/* 滑动窗口，双指针*/
vector<vector<int> > FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
    //两个起点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
    int low=1, high=2;
    while(low < high)
    {
         //由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2
        int cur = (low+high)*(high-low+1)/2;
        //相等，那么就将窗口范围的所有数添加进结果集
        if(cur == sum)
        {
            vector<int> arr;
            for(int i=low; i<=high; i++)
                arr.push_back(i);
            res.push_back(arr);
            low++;      //注意这里的自增
        }
        //如果当前窗口内的值之和小于sum，那么右边窗口右移一下
        else if(cur < sum)
            high++;
        //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
        else
            low++;
    }
    return res;
}

int main()
{
    vector<vector<int>> arr;
    arr = FindContinuousSequence(100);
    for(auto i : arr)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}