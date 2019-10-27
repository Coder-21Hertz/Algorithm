/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 找规律解法
 * 因为n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级
 * 跳1级，剩下n-1级，则剩下跳法是f(n-1)
 * 跳2级，剩下n-2级，则剩下跳法是f(n-2)
 * .....    //比斐波那契数列多了这里
 * f(n)=f(n-1)+f(n-2)+……f(1)
 * f(n-1)=f(n-2)+……f(1)
 * 两式相减得f(n)=2f(n-1)
 */
#include <bits/stdc++.h>
using namespace std;

int fun(int num)
{
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    int ans=1;
    for(int i=1; i<num; i++)
        ans = 2*ans;
    return ans;
}

int main()
{
    cout << fun(4) << endl;
}