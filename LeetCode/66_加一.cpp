/*
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 */

#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it;
        for(it = digits.end()-1; it >= digits.begin(); it--){
        	*it = *it + 1;
			if(*it > 9)
        		*it = 0;
			else
				return digits;
		}
		*digits.begin() = 0;
		digits.insert(digits.begin(), 1);
		return digits;
    }
};

int main()
{
	vector<int> vi{1,9};
	Solution a;
	vector<int> vi1 = a.plusOne(vi);
	
	for(auto it = vi1.begin(); it != vi1.end(); ++it)
		cout << *it << endl;
}
