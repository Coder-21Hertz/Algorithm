/*
 * 给定一个double类型的浮点数base和int类型的整数exponent。
 * 求base的exponent次方
 */
#include <bits/stdc++.h>

using namespace std;

double fun(double base, int exponent)   //注意返回值
{
    if(exponent < 0)
    {
        exponent=-exponent;
        base = 1.0/base;    //小于0要化为分数
    }
    else if(exponent==0)
        return 1;
    double ans=1;   //注意这里的double

    while(exponent!=0)  //快速幂法
    {
        if(exponent&1)
            ans *= base;
        base *= base;
        exponent>>=1;
    }
    return ans;
}

int main()
{
    cout << fun(2, -3) << endl;
}