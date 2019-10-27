/*
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 第一个横着放，就剩下2*(n-1),剩下的放法有f(n-1)
 * 第一个竖着放，就剩下2*(n-2),剩下的放法有f(n-2)
 * 所以这是个斐波那契数列：f(n)=f(n-1)+f(n-2)
 */
#include <bits/stdc++.h>

using namespace std;

int fun(int num)
{
    if(num <= 1)
        return num;
    int x=1, y=1;
    int ans=0;
    for(int i=1; i<=num; i++)
    {
        ans=x+y;
        x=y;
        y=ans;
    }
    return ans;
}