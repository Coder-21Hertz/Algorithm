/*
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知
 * 道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例
 * 如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
 */
#include <bits/stdc++.h>
using namespace std;

/*
* 不用额外空间
* 因为范围是0~n-1，所以可以先把出现的元素当做下标，再把下标对应的元素+长度，
* 那如果扫到相同的元素，也就是之前扫过的元素，自然对应的下标的元素值也变大了，
* 即>length，这样重复的元素就是下标
*/
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr)
        return false;
    for(int i=0; i<length; i++)
    {
        int index = numbers[i] % length;    //元素当做下标，由于可能大于len，也就是之前出现过的情况，所以取余
        if(numbers[index] >= length)         //如果大于length，说明加长过，也就是出现过
        {
            *duplication = index;
            return true;
        }
        numbers[index] += length;       //下标对应的元素加长
    }
    return false;
}

/*
 * 哈希表法
 * duplication: 重复的数字
 */
bool duplicate1(int numbers[], int length, int* duplication)
{
    unordered_map<int, int> mp;
    for(int i=0; i<length; i++)
    {
        if((++mp[numbers[i]]) > 1)
        {
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2,3,1,0,2,5,3};
    int n;
    cout << duplicate(arr, 7 ,&n) << endl;
    cout << n << endl;
}