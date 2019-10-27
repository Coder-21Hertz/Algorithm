/*
 * 给定一个无序数组，包含正数，负数和0，要求从中找出3个数的乘积，使得乘积最大
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp;

    if(n < 3)
        return 0;

    long long max1 = 1;
    long long max2 = 1;
    long long max3 = 1;
    long long min1 = -1;
    long long min2 = -1;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = temp;
        }
        else if(temp > max2)
        {
            max3 = max2;
            max2 = temp;
        }
        else if(temp > max3)
        {
            max3 = temp;
        }
        if(temp < min1)
        {
            min2 = min1;
            min1 = temp;
        }
        else if(temp < min2)
        {
            min2 = temp;
        }
    }
    cout << max((min1*min2*max1), (max1*max2*max3)) << endl;

    return 0;
}