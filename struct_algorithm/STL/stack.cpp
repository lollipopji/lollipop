#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int a;
    cin>>a;
    stack<int>int_stack;
    while(a)
    {
        int_stack.push(a%8);
        a=a/8;
    }
    int b;
    while(!int_stack.empty())
    {
        b=int_stack.top();
        int_stack.pop();
        cout<<b<<" ";
    }
    cout<<endl;
}
