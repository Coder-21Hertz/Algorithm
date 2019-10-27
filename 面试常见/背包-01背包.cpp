/*
 * https://segmentfault.com/a/1190000008731254
*/

#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;
//看本文件夹的笔记
int main()
{
    const int N = 5;                      //物品个数
    const int V = 10;                     //背包体积
    vector<int> weight{-1,2,2,6,5,4};   //第i个物品的体积（下标从1开始）
    vector<int> value{-1,6,3,5,4,6};    //第i个物品的价值
    vector<int> dp(V + 1,0);              //状态

    for (int i = 1; i <= N; i++)  //对于第i个物品
        for (int j = V; j >= weight[i]; j--)    //j不能小于物品的体积
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    cout  << dp[V] << endl;

    return 0;
}