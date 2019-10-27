/*
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，
 * 则最小的4个数字是1,2,3,4,。
 */
#include <bits/stdc++.h>
using namespace std;

void makehead(vector<int> &arr, int i, int k)
{
    if(arr.empty())
        return;
    int child = 2*i+1;
    int value = arr[i];
    while(child < k)
    {
        if(child+1<k && arr[child] < arr[child+1])
            child++;
        if(arr[child] > value)
        {
            arr[i] = arr[child];
            i = child;
            child = 2*i+1;
        }
        else
            break;
    }
    arr[i] = value;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    if(input.size()==0 || input.size() < k)
        return vector<int>{};

    for(int i=k/2; i>=0; i--)
        makehead(input, i, k);
    for(int i=k; i<input.size(); i++)
    {
        if(input[i] < input[0])
        {
            input[0] = input[i];
            makehead(input, 0, k);
        }
    }
    return vector<int>(input.begin(), input.begin()+k);
}

int main()
{
    int k =5;
    vector<int> arr = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};
    arr = GetLeastNumbers_Solution(arr, k);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}