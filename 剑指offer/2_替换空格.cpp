/*
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为        We Are Happy
 * 则经过替换之后的字符串为 We%20Are%20Happy
 *
 * 思路：先遍历一遍字符串，找出空格数量，根据空格数量确定新字符串长度
 * 然后再次从后往前遍历字符串，替换空格
 */

#include <bits/stdc++.h>
using namespace std;
void replaceSpace(char *str,int length)
{
    int newlength = length;
    for(int i=0; i<length; i++) //计算出新字符串长度
    {
        if(str[i] == ' ')
            newlength+=2;
    }
    int j=newlength-1;
    for(int i=length-1; i>=0; i--)  //从后往前遍历
    {
        if(str[i] != ' ')
            str[j]=str[i];
        else
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j] = '%';
        }
        j--;
    }
}
string fun(string str)
{
    int len = str.size();
    int newlen = len;
    for(int i=0; i<len; i++)
    {
        if(str[i] == ' ')
            newlen += 2;
    }
    string ans(newlen, '\0');
    int i=len-1;
    int j=newlen-1;
    for(; i>=0; i--,j--)
    {
        if(str[i] != ' ')
            ans[j] =str[i];
        else
        {
            ans[j--] = '0';
            ans[j--] = '2';
            ans[j] = '%';
        }
    }
    return ans;
}

int main()
{
    char str[] = "We Are Happy";    //注意后面还有\0
    replaceSpace(str, 13);
    cout << str << endl;

    string s("We Are Happy");
    cout << fun(s) << endl;
}