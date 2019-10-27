/*
 * 删除迭代器中的偶数，并且迭代器不失效
 */
#include <iostream>
#include <vector>

using namespace std;

void fun(vector<int> &arr)
{
    auto it = arr.begin();
    for(; it != arr.end();)
    {
        if(*it % 2 == 0)
        {
            it = arr.erase(it);
        }
        else
            it++;
    }
}

int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8};
    fun(arr);
    for(auto i : arr)
        cout << i << " ";
}