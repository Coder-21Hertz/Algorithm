/*
 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
 * 但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
 * 数值为0或者字符串不是一个合法的数值则返回0。
 * +2147483647  ->  2147483647
 *    1a33      ->    0
 */
#include <bits/stdc++.h>
using namespace std;

int StrToInt(string str)
{
    if(str.empty())
        return 0;
    int flag = 1; //符号位
    int ans=0;
    int i=0;
    while(str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
        i++;
    if(str[i] == '-')
    {
        flag = -1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    while(i < str.size() && str[i] >= '0' && str[i] <= '9')
    {
        ans = ans*10 + str[i++]-'0';
    }
    if(i != str.size())
        ans = 0;

    return flag*ans;
}

int main()
{
    cout << StrToInt("-123") << endl;
}