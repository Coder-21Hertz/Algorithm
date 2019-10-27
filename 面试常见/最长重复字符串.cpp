#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int Getnext(char *str)
{
    int len = strlen(str);
    vector<int> next(len);
    int i = 0;
    int j = -1;
    next[0] = -1;
    int max = 0;

    while(i < len - 1)
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
            if(j+1 > max)     //得出最大的next值
                max = j+1;
        }
        else
            j = next[j];
    }
    return max;
}

string fun(char *str)
{

    int max = 0;
    int maxi = 0;
    int len = strlen(str);
    for(int i = 0; i< len-1; i++)
    {
        int x = Getnext(str+i);
        if(x > max)
        {
            max = x;
            maxi = i;
        }
    }
    string s(str+maxi, max);
    return s;
}

int main()
{
    string s1 = "abcab";
    string s2 = "bbbbb";
    char *str = const_cast<char*>(s1.c_str());
    cout << fun(str) << endl;
    char *str1 = const_cast<char*>(s2.c_str());
    cout << fun(str1);

    cout << endl;
}