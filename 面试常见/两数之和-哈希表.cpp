#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> arr = {2,7,11,5};
    int target = 9;
    unordered_map<int,int> mp;
    for(int i = 0; i< arr.size(); i++)
    {
        int com = target - arr[i];
        if(mp.find(com) != mp.end())
            cout << i << "," << mp[com];

        mp[arr[i]] = i; //键是数值，值是下标
    }
}