/*
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::iterator it1 =  s.begin();
        string::iterator it2 =  s.begin() + 1;
        string::iterator result;
        int len = 1,ans = 1;

		if(s == "")
			return 0;
        for(; it2 != s.end(); ++it2){
        	result = find(it1, it2, *it2);
			if(result != it2 ){
        		cout << *it2 << endl;
        		it1 = result + 1;
				len = 1;
			}else{
				cout << "*" << *it2 << endl;
				len = it2 - it1 + 1;
			}
			if(len > ans)
				ans = len;
		}
		return ans;
    }
};

int main()
{
	string s = "aaaab";
	Solution a;
	cout << a.lengthOfLongestSubstring(s) << endl;
}
