/*
 * 从arr[1, n]这n个数中，找出最大的k个数
 * 从arr[1, 12]={5,3,7,1,8,2,9,4,7,2,6,6} 这n=12个数中，找出最大的k=5个。
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*构建一个小顶堆,最上面的值为最小 */
void makeHeap(vector<int> &arr, int i, int len)
{
    int child = 2*i+1;
    int value = arr[i];
    while(child < len)
    {
        if(child+1 < len && arr[child] > arr[child+1])
            child++;
        if(value > arr[child])
        {
            arr[i] = arr[child]; //注意这里父节点等于子节点
            i = child;
            child = 2*i+1;
        }
        else    //注意退出
            break;
    }
    arr[i] = value; //这里是i
}

vector<int> TopK(vector<int> arr, int k)
{
    if(arr.size()==0 || arr.size() < k)
        return vector<int>{};

    for(int i = k/2; i>=0; i--)
        makeHeap(arr, i, k);    //建堆的时候保证了父节点一定比子节点大
    for(int i = k; i < arr.size(); i++)
    {
        if(arr[i] > arr[0])
        {
            arr[0] = arr[i];    //赋值就好，不用交换
            makeHeap(arr, 0, k);
        }
    }

    return vector<int>(arr.begin(), arr.begin()+k);
}

int main()
{
    int k =5;
    vector<int> arr = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};
    arr = TopK(arr, k);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}