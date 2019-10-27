/*
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个
 * 只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 */
#include <bits/stdc++.h>
using namespace std;

int FirstNotRepeatingChar(string str)
{
    unordered_map<char, int> mp;
    for(int i=0; i<str.size(); i++)
        mp[str[i]]++;

    for(int i=0; i<str.size(); i++)     //因为说的是第一个出现的字符，所以必须遍历str，不能遍历哈希表
    {
        if(mp[str[i]] == 1)
            return i;
    }
    return -1;
}

int main()
{
    string str = "aacbc";
    cout << FirstNotRepeatingChar(str) << endl;
}