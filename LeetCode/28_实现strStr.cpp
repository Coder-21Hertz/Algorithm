#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int pos=haystack.find(needle);
        return pos;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    cout << s.strStr("hello", "ll") << endl;
}
