/*
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近。
 * 返回这三个数的和。假定每组输入只存在唯一答案。
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        vector<int>::iterator it1;
        vector<int>::iterator it2;
        vector<int>::iterator it3;
        sort(nums.begin(), nums.end());
        int diff;

        for (; it1 != nums.end(); ++it1)
        {
            it2 = it1+1;
            while(it2 < it3)
            {
                
            }
        }
    }
};

int main()
{
}