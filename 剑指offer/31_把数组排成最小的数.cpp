/*
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 */
#include <bits/stdc++.h>
using namespace std;

static bool compare(const string &str1, const string &str2)
{
    return str1+str2 < str2+str1;
}

string PrintMinNumber(vector<int> numbers)
{
    vector<string> strnum;
    string res = "";
    for(int i=0; i<numbers.size(); i++)
        strnum.push_back(to_string(numbers[i]));
    sort(strnum.begin(), strnum.end(), compare);

    for(int i=0; i<strnum.size(); i++)
        res+=strnum[i];
    return res;
}

int main()
{
    vector<int> arr{3, 32, 321};
    cout << PrintMinNumber(arr) << endl;
}