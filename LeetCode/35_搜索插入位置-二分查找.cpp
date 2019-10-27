/*
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。
 * 输入: [1,3,5,6], 5
 * 输出: 2
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator it;
		for(it = nums.begin(); it != nums.end(); ++it){
			if(*it >= target)
				return it-nums.begin();
		}
		return it-nums.begin();
    }

    //二分查找
    int searchInsert_2(vector<int>& nums, int target) {
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = nums.end();
        vector<int>::iterator mid;

        while(it1 < it2){
        	mid = it1 + (it2 - it1)/2;
        	if(target > *mid){
        		it1 = mid+1;
			}else if(target < *mid)
				it2 = mid;
			else
				return mid - nums.begin();
		}
		return it1 - nums.begin();
    }
};

int main()
{
	vector<int> vi{1,3};
	Solution a;
	cout << a.searchInsert_2(vi, 5) << endl;
}
