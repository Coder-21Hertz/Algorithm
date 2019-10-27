/*
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 */
#include <bits/stdc++.h>
using namespace std;

//额外空间
string LeftRotateString(string str, int n)
{
    if(str.empty())
        return "";
    int len = str.size();
    str += str;     //巧妙的地方
    return str.substr(n, len);
}

//不用额外空间，三次翻转字符串，用reverse函数
string LeftRotateString1(string str, int n)
{
    if(str.empty())
        return "";
    reverse(str.begin(), str.begin()+n);
    reverse(str.begin()+n, str.end());
    reverse(str.begin(), str.end());
    return str;
}
