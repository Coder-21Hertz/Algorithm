#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

/*
 * 无优化，暴力法
 * 将所有的物品(不管同不同一类)都看不同的种类，进行01背包的求解
 */
void fun1()
{
    int n,m;
    cin >> n;   //物品种数
    cin >> m;   //背包容量
    vector<int> weight(n+1);
    vector<int> value(n+1);
    vector<int> num(n+1);

    for(int i=1; i<=n; i++)
        cin >> weight[i] >> value[i] >> num[i];//输入物品的重量、价值、数量

    int k=n+1;  //记录转化后的物品种数
    for(int i=1; i<=n; i++) //进行转化为01背包
    {
        while(num[i] != 1)  //大于1个，就加到后面，并把数量减1
        {
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            k++;
            num[i]--;
        }
    }
    vector<int> dp(m+1);
    //01背包问题
    for(int i=1; i<=k; i++)
        for(int j=m; j>=weight[i]; j--)
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);

    cout << dp[m] << endl;
}

/*
 * 二进制优化
 * https://blog.csdn.net/yo_bc/article/details/72801742
 */
void fun2()
{
    int n,m;
    cin >> n;   //物品种数
    cin >> m;   //背包容量
    int weight,value,num;
    vector<int> dp(m+1);
    for(int i=1; i<=n; i++)
    {
        cin >> weight >> value >> num;//输入物品的重量、价值、数量

        for(int k=1; k<num; k<<=1)
        {
            for(int j=m; j>=k*weight; j--)
                dp[j] = max(dp[j], dp[j-k*weight]+k*value);
            num -= k;
        }
        for(int j=m; j>=num*weight; j--)
            dp[j] = max(dp[j], dp[j-num*weight]+num*value);
    }

    cout << dp[m] << endl;
}

int main()
{
    fun2();
}