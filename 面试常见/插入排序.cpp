#include <iostream>
#include <vector>
using namespace std;

void insertsort (vector<int> &arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        int temp = arr[i];
        int j=i-1;
        for(; j>-1 && arr[j] > temp; j--)   //大的往后移
            arr[j+1] = arr[j];
        arr[j+1] = temp;    //这里是j+1
    }
}

int main()
{
    vector<int> arr = {3,4,2,8,6,7,9,1};
    insertsort(arr);
    for(auto i : arr)
        cout << i << " ";
}