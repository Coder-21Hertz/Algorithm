#include <iostream>
#include <malloc.h>
using namespace std;

/*char型转化为int */
int myatoi(const char *str)
{
    int result = 0;
    int sign = 0;

    if(str == NULL)
    {
        printf("Pointer is NULL\n");
		return 0;
    }

    while(*str == ' ' || *str == '\t' || *str == '\n')
        str++;

    if(*str == '-')
    {
        sign = 1;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        result = result*10 + *str - '0';
        str++;
    }

    if(sign == 1)
        return -result;
    else
        return result;
}

int main()
{
    char str1[] = "-1234562";
    char str2[] = "2";
    cout << myatoi(str1) + myatoi(str2) << endl;
    char *a=(char *) malloc(sizeof(char) * 10);
    cout<<sizeof(a)<<endl;
}