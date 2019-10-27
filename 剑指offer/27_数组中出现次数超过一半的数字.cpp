/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * 保存一个元素，遍历后序的，相同就+1，不同就-1，减到0时更新为当前元素
 * 原理：如果一个元素统计有2次了，后面的必须要有两次的才能超过他
 */
int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if(numbers.empty())
        return 0;
    int count = 0;  //次数
    int res;
    for(int i=0; i<numbers.size(); i++)
    {
        if(count == 0)
        {
            res = numbers[i];
            count = 1;
        }
        else if(res == numbers[i])
            count++;
        else
            count--;
    }
    count = 0;
    for(int i=0; i<numbers.size(); i++)
    {
        if(res == numbers[i])
            count++;
    }
    return (count>numbers.size()/2) ? res : 0;
}

//哈希表法
int MoreThanHalfNum_Solution1(vector<int> numbers)
{
    if(numbers.empty())
        return 0;
    unordered_map<int, int> arr;
    for(int i=0; i<numbers.size(); i++)
    {
        arr[numbers[i]]++;
        if(arr[numbers[i]] > numbers.size()/2)
            return numbers[i];
    }
    return 0;
}

int main()
{
    vector<int> arr{1,2,3,2,2,2,5,4,2};
    cout << MoreThanHalfNum_Solution(arr) << endl;
    cout << MoreThanHalfNum_Solution1(arr) << endl;
}