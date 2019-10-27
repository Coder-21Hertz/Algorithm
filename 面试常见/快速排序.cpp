#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int median(vector<int> &a, int left, int right)
{
    int center = (left+right)/2;
    if(a[center] < a[left])
        swap(a[left], a[center]);
    if(a[right] < a[left])
        swap(a[left], a[right]);
    if(a[right] < a[center])
        swap(a[center], a[right]);

    swap(a[center], a[right-1]);
    return a[right-1];
}

int partition(vector<int> &arr, int i, int j)
{
    int pivot = arr[i];
    while(i < j)
    {
        while(i<j && arr[j] >= pivot) j--;  //有等于号
        arr[i] = arr[j];
        while(i<j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}

/*没用三数取中，递归解法*/
void quickSort(vector<int> &arr, int left, int right)
{
    if(right <=left)        //注意这里的判断是right
        return;
    int mid = partition(arr, left, right);

    quickSort(arr, left, mid-1);
    quickSort(arr, mid+1, right);
}

/*非递归, 用队列*/
void quickSort1(vector<int> &arr, int left, int right)
{
    if(right <=left)
        return;
    queue<int> q;
    int i, j, mid;
    q.push(left);
    q.push(right);
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        j = q.front();
        q.pop();
        mid = partition(arr, i, j);
        if(i < mid-1)
        {
            q.push(i);
            q.push(mid-1);
        }
        if(j > mid+1)
        {
            q.push(mid+1);
            q.push(j);
        }
    }
}

int main()
{
    vector<int> arr = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};
    vector<int> arr1 = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};

    quickSort(arr, 0, arr.size()-1);
    quickSort1(arr1, 0, arr.size()-1);

    for(auto i : arr)
        cout << i << " ";
    cout << endl;
    for(auto i : arr1)
        cout << i << " ";
    cout << endl;

}