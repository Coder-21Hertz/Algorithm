/*
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 * 注意是：质因子
 */
#include <bits/stdc++.h>
using namespace std;

int GetUglyNumber_Solution(int index)
{
    if(index <= 0) return 0;
    if(index == 1) return 1;
    vector<int> res(index);
    res[0] = 1;
    int t2=0, t3=0, t5=0;
    for(int i=1; i<index; i++)
    {
        res[i] = min(res[t2]*2, min(res[t3]*3, res[t5]*5));
        if(res[i] == res[t2]*2) t2++;   //相等或重复的情况才要自增
        if(res[i] == res[t3]*3) t3++;
        if(res[i] == res[t5]*5) t5++;
    }
    return res[index-1];//减1是下标问题
}

int main()
{
    cout << GetUglyNumber_Solution(6) << endl;
}

