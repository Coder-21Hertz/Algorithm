#include <bits/stdc++.h>

using namespace std;

int expand(string s, int L, int R)
{
    // int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R])
    {// 计算以left和right为中心的回文串长度
        L--;
        R++;
    }
    return R - L - 1;
}

string longestPalindrome(string s)
{
    if (s.size() < 2)
        return s;
    int start = 0;  //记录回文子串起始位置
    int end = 0;    //记录回文子串终止位置
    int maxlen=0;   //记录最大回文子串的长度
    for (int i = 0; i < s.size(); i++)
    {
        int len1 = expand(s, i, i);//一个元素为中心
        int len2 = expand(s, i, i + 1);//两个元素为中心
        maxlen = max(max(len1, len2), maxlen);
        if (maxlen > end - start+1)
        {
            start = i - (maxlen - 1) / 2;   //i是中间位置，所以这里是减去一半
            end = i + maxlen / 2;
        }
    }
    return s.substr(start, maxlen);    //该函数的意思是获取从start开始长度为end - start + 1长度的字符串
}

int main()
{
    string s="aaaabab";
    cout << longestPalindrome(s) << endl;
}