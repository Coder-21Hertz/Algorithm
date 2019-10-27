/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
 * 斐波那契数列
 * 因为n级台阶，第一步有n种跳法：跳1级、跳2级
 * 跳1级，剩下n-1级，则剩下跳法是f(n-1)
 * 跳2级，剩下n-2级，则剩下跳法是f(n-2)
 * f(n)=f(n-1)+f(n-2)
 * 同理也可得出跳3级的解法
 */
#include <bits/stdc++.h>

using namespace std;

int fun(int num)
{
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    int x=1,y=1;
    int ans=0;
    for(int i=1; i<num; i++)
    {
        ans = x+y;
        x=y;
        y=ans;
    }
    return ans;
}

int main()
{
    cout << fun(4) << endl;
}