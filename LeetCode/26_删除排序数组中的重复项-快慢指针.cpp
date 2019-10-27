/*
 * 给定一个排序数组，你需要在原地删除重复出现的元素，
 * 使得每个元素只出现一次，返回移除后数组的新长度。
 * 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 * 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 * 你不需要考虑数组中超出新长度后面的元素。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //快慢指针
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = nums.begin() + 1;

        for (; it2 != nums.end(); ++it2)
        {
            if (*it1 != *it2)
            {
                ++it1;
                *it1 = *it2;
            }
        }
        return it1 - nums.begin() + 1;
    }

    //使用标准库算法
    int removeDuplicates_2(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

        return nums.size();
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution a;
    // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
    int len = a.removeDuplicates_2(nums);

    // 在函数里修改输入数组对于调用者是可见的。
    // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << endl;
    }
}
