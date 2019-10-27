/*
 * 求一个数组元素是不是顺序的，数组元素的范围是1~13，其中0可以看成任何数
 */
#include <bits/stdc++.h>
using namespace std;

bool IsContinuous( vector<int> numbers )
{
    if(numbers.empty())
        return false;
    int min = 14;
    int max = -1;
    vector<int> arr(14, 0);
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == 0)
            continue;

        arr[numbers[i]]++;      //防止出现相同的数字
        if(arr[numbers[i]] > 1)
            return false;
        if(numbers[i] > max)
            max = numbers[i];
        if(numbers[i] < min)
            min = numbers[i];
    }
    if(max-min < 5)
        return true;
    return false;
}