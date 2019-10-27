/*
 * 动态规划算法的核心是记住已经求过的解
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(10);

int fib(int i)
{
    if(i <= 0)
        return 0;
    if(i == 1)
        return 1;

    return fib(i-1)+fib(i-2);
}

int fib1(int i)
{
    if(i <= 0)
        return 0;
    if(i == 1)
        return 1;
    if(arr[i] != 0)
        return arr[i];

    return arr[i] = fib1(i-1)+fib1(i-2);
}

/* 非递归法1 */
int Fibonacci(int n) {
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    for(int i = 2; i<=n; i++){
        arr.push_back(arr[i-1]+arr[i-2]);
    }
    return arr[n];
}
/* 非递归法2 */
int Fibonacci1(int n) {
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    int n1 = 0;
    int n2 = 1;
    int sum = 0;
    for(int i = 2; i<=n; i++){
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    return sum;
}

void fun() {
    int n = 8;	//机器人个数
    int pre[] = {0,0,0,1,0,2,3,5};	//选择这个机器人之后前驱最近机器人下标
    int profit[] = {5,1,8,4,6,3,2,4};	//机器人收益
    int opt[8];

    opt[0]=0;

    for(int i=1; i<9; i++){
        opt[i]=max(opt[i-1], opt[pre[i-1]]+profit[i-1]);
    }

    for(int i=1;i<n+1;i++){
        cout << opt[i] << " ";
    }
}

int main()
{
    cout << "递归：" << endl;
    for(int i = 1; i < 10; i++)
        cout << fib(i) << " ";
    cout << endl;
    cout << "递归，动态规划：" << endl;
    for(int i = 1; i < 10; i++)
        cout << fib1(i) << " ";
}