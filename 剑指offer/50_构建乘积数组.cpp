/*
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
 * 不能使用除法。B数组的每一个元素=除了自身之外A[i]，所有元素相乘
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * 矩阵法
 * https://uploadfiles.nowcoder.com/images/20160829/841505_1472459965615_8640A8F86FB2AB3117629E2456D8C652
 */
vector<int> multiply(const vector<int>& A)
{
    if(A.empty())
        return vector<int>{};

    vector<int> b(A.size());
    //计算下三角
    b[0] = 1;
    for(int i=1; i<A.size(); i++)
    {
        b[i] = b[i-1] * A[i-1];
    }
    //计算上三角
    int temp = 1;
    for(int i=A.size()-2; i>=0; i--)
    {
        temp *= A[i+1];
        b[i] *= temp;
    }

    return b;
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    arr = multiply(arr);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}