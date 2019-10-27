/*
 * 给定一个包含 n 个整数的数组 nums，
 * 判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    //双指针(对撞指针)
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answer;
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2;
        vector<int>::iterator it3;
        int sum;
        if (nums.size() < 3)
            return answer;
        sort(nums.begin(), nums.end());
        for (; it1 < nums.end() - 2; ++it1)
        {
            if (it1 == nums.begin() || *it1 != *(it1 - 1))
            {
                it2 = it1+1; it3 = nums.end()-1; sum = 0 - *it1;
                while(it2 < it3)
                {
                    if(*it2 + *it3 == sum)
                    {
                        answer.push_back({*it1, *it2, *it3});
                        while(it2 < it3 && *it2 == *(it2+1)) ++it2;
                        while(it2 < it3 && *it3 == *(it3-1)) --it3;
                        ++it2;
                        --it3;
                    }else if (*it2 + *it3 < sum)
                        ++it2;
                    else
                        --it3;
                }
            }
        }

        return answer;
    }

    vector<vector<int>> threeSum_1(vector<int> &nums)
    {
        vector<vector<int>> answer;
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2;
        vector<int>::iterator it3;
        int diff;
        if (nums.size() < 3)
            return answer;
        sort(nums.begin(), nums.end());
        for (; it1 < nums.end() - 2; ++it1)
        {
            if (it1 == nums.begin() || *it1 != *(it1 - 1))
            {

                for (it2 = it1 + 1; it2 < nums.end() - 1; it2++)
                {
                    if (it2 == it1 + 1 || *it2 != *(it2 - 1))
                    {
                        diff = 0 - *it1 - *it2;
                        if ((it3 = find(it2 + 1, nums.end(), diff)) != nums.end())
                            answer.push_back({*it1, *it2, *it3});
                    }
                }
            }
        }

        return answer;
    }
};
int main(int argc, char *argv[])
{
    vector<int> nums = {0, 0, 0, 0, 0, 0};

    Solution a;

    vector<vector<int>> answer = a.threeSum(nums);

    for (vector<vector<int>>::iterator i = answer.begin(); i != answer.end(); i++)
    {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j)
            cout << *j << " ";
        cout << endl;
    }
}
