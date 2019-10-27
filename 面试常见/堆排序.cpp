#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*建堆，大顶堆 */
void adjustHeap(vector<int> &arr, int i, int len)
{
    int value = arr[i];
    int child = 2*i + 1;

    while(child < len)
    {
        if(child+1 < len && arr[child] < arr[child+1])  //如果右孩子存在，且右孩子大于左孩子
            child++;
        if(value < arr[child])      //如果当前值小于孩子的值
        {
            arr[i] = arr[child];    //交换,把子节点中最大的换给当前结点
            i = child;              //继续比较孩子和孙子的大小
            child = 2*i + 1;
        }
        else
            break;
    }
    arr[i] = value;     //交换完后，i为最后一个孩子节点，把之前节点值赋给他
}

void heapSort(vector<int> &arr)
{
    for(int i = arr.size()/2; i>=0; i--)    //从一半开始的原因是：从这里开始，这些结点才会有子节点，比这大的都没有子节点
        adjustHeap(arr, i, arr.size());     //把完全二叉树变为大顶堆

    for(int j = arr.size()-1; j>0; j--)
    {
        swap(arr[0], arr[j]);       //交换第一个和最后一个位置，由于是大顶堆，所以最后一个为堆中最大值
        adjustHeap(arr, 0, j);      //交换后，去掉最后一个，重组大顶堆
    }
}

/*
 * 完全二叉树：最下层上的结点都集中在该层最左边的若干位置上，根结点为最小结点
 *                    0
 *                 /   \
 *                1    2
 *              / \   / \
 *             3   4 5  6
 *           / \
 *         7   8
 */
int main()
{
/*先把数组当成完全二叉树，即0   1   2   3  4  5   6   7    8   9  10  11 */
    vector<int> arr = {23, 65, 12, 3, 8, 76, 345, 90, 21, 75, 34, 61};

    heapSort(arr);
    for(auto i : arr){
        cout << i << " ";
    }
}