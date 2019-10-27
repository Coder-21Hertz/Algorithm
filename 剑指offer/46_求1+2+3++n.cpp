/*
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 */
#include <bits/stdc++.h>
using namespace std;

int Sum_Solution(int n)
{
    int res = n;
    n && (res += Sum_Solution(n-1));  //n=0时，就不会执行后面的
    return res;
}

int main()
{
    cout << Sum_Solution(100) << endl;
}