/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */
#include<bits/stdc++.h>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix)
{
    int y = matrix.size();
    int x = matrix[0].size();

    vector<int> ans;
    int left=0, right=x-1, top=0, bottom=y-1;
    while(left <= right && top <= bottom)
    {
        for(int i=left; i<=right; i++)
            ans.push_back(matrix[top][i]);
        for(int i=top+1; i<=bottom; i++)    //top要+1
            ans.push_back(matrix[i][right]);
        if(top != bottom)                   //防止只有一行，这里要判断列相不相等
        for(int i=right-1; i>=left; i--)
            ans.push_back(matrix[bottom][i]);
        if(left != right)                   //防止只有一列
        for(int i=bottom-1; i>=top+1; i--)
            ans.push_back(matrix[i][left]);
        left++; right--; top++; bottom--;
    }
    return ans;
}

int main()
{
{
    vector<vector<int>> arr{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{ 13, 14, 15, 16}};
    vector<int>ans = printMatrix(arr);
    for(auto i : ans)
        cout<< i << " ";
    cout << endl;
}
{
    vector<vector<int>> arr{{1, 2, 3, 4}};
    vector<int>ans = printMatrix(arr);
    for(auto i : ans)
        cout<< i << " ";
    cout << endl;
}
}