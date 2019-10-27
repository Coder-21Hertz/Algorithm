#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> tmp;
    int i=start, j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i] < arr[j])
            tmp.push_back(arr[i++]);
        else
            tmp.push_back(arr[j++]);
    }
    while(i<=mid)
        tmp.push_back(arr[i++]);
    while(j<=end)
        tmp.push_back(arr[j++]);
    for(int i=0; i<tmp.size(); i++)
        arr[start+i] = tmp[i];
}

void mergesort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int mid = start+(end-start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void insertsort(vector<int> &arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        int j=i-1;
        int temp = arr[i];
        for(; j>=0 && arr[j] > temp; j--)
            arr[j+1] = arr[j];
        arr[j+1] = temp;
    }
}

int main()
{
    int k =5;
    vector<int> arr = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};
    mergesort(arr,0, arr.size());
    insertsort(arr);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}