#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vec;
    void Insert(int num)
    {
        vec.push_back(num);
    }

    double GetMedian()
    {
        sort(vec.begin(),vec.end());
        int size = vec.size();
        if(size % 2 == 0){
            return (double)(vec[size/2] + vec[size/2 - 1]) / 2;
        }else{
            return (double)vec[size/2];
        }
    }

};