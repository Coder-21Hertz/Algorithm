#include <bits/stdc++.h>
using namespace std;

//完全背包
int cutRope(int number)
{
    if(number < 3)
        return 1;
    vector<int> dp(number+1, 0);
    dp[1] = 1;dp[2] = 2;

    for(int i=2; i<=number; i++)    //绳每段的长度
        for(int j=i+1; j<=number; j++)  //绳长
            dp[j] = max(dp[j], dp[j-i]*i);

    for(auto a : dp)
        cout << a << " ";
    return dp[number];
}

int main()
{
    cout << cutRope(8);
}