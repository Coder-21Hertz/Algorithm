/*
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一
 * 个整数，判断数组中是否含有该整数。
 */
#include <bits/stdc++.h>

using namespace std;

bool Find(int target, vector<vector<int> > array)
{
    if(array.empty())
        return false;
    int rows = array.size();    //行
    int cols = array[0].size(); //列
    int i=rows-1, j=0;          //左下角的数字作为切入点
    while(i>=0 && j<cols)
    {
        if(target < array[i][j])
            i--;
        else if(target > array[i][j])
            j++;
        else
            return true;
    }
    return false;
}

int main()
{

}