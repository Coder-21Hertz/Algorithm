/*
 * 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，
 * 返回移除后数组的新长度。不要使用额外的数组空间，你必须在原地修改输入数
 * 组并在使用 O(1) 额外空间的条件下完成。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 * 例：给定 nums = [0,1,2,2,3,0,4,2], val = 2,
 * 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 * 注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	//双指针，自己的方法
	int removeElement(vector<int> &nums, int val)
	{
		if (nums.empty())
			return 0;
		vector<int>::iterator end = nums.end() - 1;

		for (vector<int>::iterator it = nums.begin(); it < end; ++it)
		{
			while (*end == val)
			{
				if (end == it)
					return end - nums.begin();
				--end;
			}

			if (*it == val)
			{
				*it = *end;
				--end;
			}
		}
		if (*end == val)
			--end;
		return end - nums.begin() + 1;
	}

	//双指针，快慢指针
	int removeElement_2(vector<int> &nums, int val)
	{
		vector<int>::iterator it1 = nums.begin();
		vector<int>::iterator it2 = nums.begin();

		for (; it2 != nums.end(); ++it2)
		{
			if (*it2 != val)
			{
				*it1 = *it2;
				++it1;
			}
		}
		return it1 - nums.begin();
	}
};

int main()
{
	vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	Solution a;
	// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
	int len = a.removeElement_2(nums, 2);

	// 在函数里修改输入数组对于调用者是可见的。
	// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << endl;
	}
}
