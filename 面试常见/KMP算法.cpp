#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> GetNext(string s)
{
    int len = s.size();
    vector<int> next(len);
    int i = 0;
    int j = -1;
    next[0] = -1;

    while(i < len-1)
    {
        if(j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
    return next;
}

/* 最前一个匹配的字符 */
int KMPMatch(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int>next(GetNext(s2));
    int i = 0;
    int j = 0;      //不一样
    while(i < len1 && j < len2)     //不一样
    {
        if(j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j == len2)   //已经匹配到最后一个字符
        return i - j;
    return -1;
}

/* 最后一个匹配的字符 */
int KMPMatchEnd(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int t = -1;
    vector<int>next(GetNext(s2));
    int i = 0;
    int j = 0;
    while(i < len1)
    {
        j = 0;
        while(i < len1 && j < len2)
        {
            if(j == -1 || s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if(j == len2)   //已经匹配到最后一个字符
            t = i - j;
    }
    return t;
}

int main()
{
    string s1 = "abcacabcababcababcab";
    string s2 = "abcab";
    vector<int>next(GetNext(s2));
    for(int x : next)
        cout << x << " ";
    cout << endl;

    cout << KMPMatch(s1, s2) << endl;
    cout << KMPMatchEnd(s1, s2) << endl;
}