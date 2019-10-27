/*
 * https://segmentfault.com/a/1190000008731254
*/

#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    const int N = 5;                     //物品个数
    const int V = 10;                    //背包体积
    vector<int> weight{ -1,1,2,3,4,5 };  //第i个物品的体积（下标从1开始）
    vector<int> value{ -1,5,4,3,2,1 };   //第i个物品的价值
    vector<int> dp(V + 1,0);                //状态

    for (int i = 1; i <= N; i++)  //对于第i个物品
        for (int j = weight[i]; j <= V; j++)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    cout  << dp[V] << endl;  //9

    return 0;
}