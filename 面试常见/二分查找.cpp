#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BinarySearch(vector<int> t, int value)
{
    if(t.empty())   //注意这里，不能和null比较
        return -1;

    int low = 0;
    int hig = t.size()-1;

    while (low <= hig)              //要=
    {
        int mid =low+ (hig-low)/2;  //这里要加low
        if(value == t[mid])
            return mid;
        else if(value < t[mid])
            hig = mid - 1;          //要-1
        else if(value > t[mid])
            low = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> t = {1,2,6,4,5};
    sort(t.begin(), t.end());
    cout << BinarySearch(t, 6) << endl;
}