/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */
#include <bits/stdc++.h>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
    int low = 0;
    int high = rotateArray.size()-1;

    while(low < high)
    {
        int mid = low + (high-low)/2;
        //类似[3,4,5,6,0,1,2]，此时最小数字一定在mid的右边
        if(rotateArray[mid] > rotateArray[high])
            low = mid+1;
        //类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边
        else if(rotateArray[mid] == rotateArray[high])
            high--;
        //类似[2,2,3,4,5,6,6],此时最小数字一定就是array[mid]或者在mid的左边
        else
            high = mid;
    }
    return rotateArray[low];
}