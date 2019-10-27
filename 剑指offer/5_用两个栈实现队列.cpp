/*
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */
#include<bits/stdc++.h>
using namespace std;

class my_queue{
public:
    void push(int node)
    {
        stack1.push(node);
    }
    int pop()
    {
        if(stack2.empty())  //这里要判断是不是空
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int a = stack2.top();
        stack2.pop();
        return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};