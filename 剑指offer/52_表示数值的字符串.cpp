/*
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
#include <bits/stdc++.h>
using namespace std;

bool isNumeric(char* string)
{
    if(*string == '\0')
        return false;
    if(*string == '+' || *string == '-')
        string++;
    int flag = 0;   //小数点标记
    while(*string != '\0')
    {
        if(*string >= '0' && *string <= '9')
            string++;
        else if(*string == 'e' || *string == 'E')
        {
            flag = 1;
            if(*(string+1) == '\0')
                return false;
            else if(*(string+1) == '-' || *(string+1) == '+')
                string+=2;
            else
                string++;
        }
        else if(*string == '.')
        {
            if(flag == 0)
                flag = 1, string++;
            else
                return false;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    char str[] = "123.45e+6";
    cout << isNumeric(str) << endl;
}