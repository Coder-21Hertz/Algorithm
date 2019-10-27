/*
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
 * 即输出P%1000000007
 * 归并思想
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data)
    {
        count = 0;
        if(!data.empty())
            mergeSort(data, 0, data.size()-1);

        return count%1000000007;
    }

private:
    long count;
    void mergeSort(vector<int> &arr, int start, int end)
    {
        if(start < end)
        {
            int mid = (start+end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);
            merge(arr, start, mid, end);
        }
    }
    void merge(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> tmp;
        int i=start, j=mid+1;
        while(i <= mid && j <= end)
        {
            if(arr[i] > arr[j])     //注意这里，逆序对，符号相反，和归并排序不同
            {
                tmp.push_back(arr[i++]);
                count += end - j + 1;
            }
            else
                tmp.push_back(arr[j++]);
        }
        while(i <= mid)
            tmp.push_back(arr[i++]);
        while(j <= end)
            tmp.push_back(arr[j++]);
        for(int i=0; i<tmp.size(); i++)
            arr[start+i] = tmp[i];
    }
};


int main()
{
    vector<int> arr = {5,3,7,1,8,2,9,4,7,2,6,6,10,3,11};
    Solution s;
    cout << s.InversePairs(arr)<< endl;
}