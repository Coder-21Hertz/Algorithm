/*
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c
 * 所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 * 输入描述:
 * 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        if(!str.empty())
        {
            Permutation(str, 0);
            // 此时得到的result中排列并不是字典顺序，可以单独再排下序
            sort(res.begin(), res.end());
        }
        return res;
    }
private:
    vector<string> res;
    void Permutation(string str, int begin)
    {
        if(begin == str.size()-1)// 递归结束条件：索引已经指向str最后一个元素时
        {
            res.push_back(str);
        }
        else
        {
            // 第一次循环i与begin相等，相当于第一个位置自身交换，关键在于之后的循环，
            // 之后i != begin，则会交换两个不同位置上的字符，直到begin==str.size()-1，进行输出；
            for(int i=begin; i<str.size(); i++)
            {
                if(i==begin || str[i] != str[begin])    //去除字符相同的情况
                {
                    swap(str[begin], str[i]);
                    Permutation(str, begin+1);
                    swap(str[begin], str[i]);
                }
            }
        }

    }
};
int main()
{
    string str("abc");
    Solution s;
    vector<string> res = s.Permutation(str);
    for(auto s : res)
        cout << s << " ";
}