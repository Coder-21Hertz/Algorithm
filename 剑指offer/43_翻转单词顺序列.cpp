/*
 * 翻转句子中的字符串
 * 如：  “student. a am I”
 * 翻转后“I am a student.”
 */
#include <bits/stdc++.h>
using namespace std;

string ReverseSentence(string str)
{
    if(str.empty())
        return "";
    string s1="";
    string s2="";
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == ' ')
        {
            s2 = " " + s1 + s2;
            s1="";
        }
        else
            s1+=str[i];
    }
    if(!s1.empty())
        s2 = s1 + s2;
    return s2;
}

/*
 *算法思想：先翻转整个句子，然后，依次翻转每个单词。
 *依据空格来确定单词的起始和终止位置
*/
string ReverseSentence1(string str)
{
    if(str.empty())
        return "";
    reverse(str.begin(), str.end());    //先翻转整个句子
    int last = 0;       //记录空格的下一个位置
    for(int i = 0; i <= str.size(); i++)    //注意这里的边界，为了做最后一次没有空格判断的交换
    {
        if(i == str.size() || str[i] == ' ')    //这里要边界判断在前，不然会溢出
        {
            reverse(str.begin()+last, str.begin()+i);
            last = i+1;
        }
    }
    return str;
}

int main()
{
    string str("Is am a student");
    cout << ReverseSentence1(str) << endl;
}