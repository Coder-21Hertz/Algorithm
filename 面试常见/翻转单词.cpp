#include <iostream>
#include <string>
using namespace std;

string fun1(string str)
{
    string res = "", tmp = "";
    for(unsigned int i = 0; i < str.size(); ++i)
    {
        if(str[i] == ' ')
            res = " " + tmp + res, tmp = "";    //遇到空格 = 当前的tmp+之前的res（之前的tmp）
        else
            tmp += str[i];      //暂存每一个单词
    }
    if(!tmp.empty())
        res = tmp + res;
    return res;
}

string fun2(string str)
{
    auto it1 = str.begin();
    auto it2 = str.end()-1;
    while(it1 != it2)
    {
        swap(*it1,*it2);
        it1++;it2--;
    }
    return str;
}

int main()
{
    string str = "hello world !";

    cout << fun1(str) << endl;
    cout << fun2(str) << endl;
}