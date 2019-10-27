/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的
 * 后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
#include <bits/stdc++.h>

using namespace std;

/*需要保证稳定性：插排思想*/
void fun(vector<int> &array)
{
    for(int i=0; i<array.size(); i++)
    {
        if(array[i]%2 != 0)     //比插排多了这一步
        {
            int temp = array[i];
            int j=i-1;
            for(; j>-1 && array[j]%2 == 0; j--)
                array[j+1] = array[j];
            array[j+1] = temp;    //这里是j+1
        }
    }
}
/*不用保证稳定性的：快排思想*/
void fun2(vector<int> &array)
{
    int value = array[0];
    int i=0;
    int j=array.size()-1;
    while(i < j)
    {
        while(i<j && array[j]%2 == 0) j--;
        array[i] = array[j];
        while(i<j && array[i]%2 != 0) i++;
        array[j] = array[i];
    }
    array[j] = value;
}

/*用迭代器，但是earse复杂度O(n)，所以整体退化为O(n^2)*/
void fun1(vector<int> &array)
{
    auto it = array.begin();
    int len = array.size();
    for(int i=0; i<len; i++)
    {
        if(*it%2 == 0)
        {
            int temp = *it;
            array.erase(it);
            array.push_back(temp);
        }
        else
            it++;
    }
}

int main()
{
    vector<int> arr = {3,4,2,8,6,7,9,1};
    fun(arr);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    arr = {3,4,2,8,6,7,9,1};
    fun1(arr);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    arr = {3,4,2,8,6,7,9,1};
    fun2(arr);
    for(auto i : arr)
        cout << i << " ";
}