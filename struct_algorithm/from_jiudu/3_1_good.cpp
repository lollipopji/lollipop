#include <iostream>
/*
 * 问题：设计一个栈，它可以在O(1)时间内实现push、pop和min操作，其中的min操作是得到栈中最小的元素
 * 思路一：使用一个额外的指针来只是当前栈中最小值得位置（No work）：如果pop刚好是最小的元素，那么接下来的min是什么？
 * 思路二：使用空间换时间，采用一个额外的栈空间，在栈顶存放当前栈中最小的元素：
 *         很巧妙的设计：两个栈采用同一个top指针来同步，也就是说两个栈同增同减
 */
#define MAXLEN 1024
#define MIN(a,b) ((a)>(b))?(b):(a) 
using namespace std;

class MyStack
{
    public:
         MyStack():top(-1){};
         ~MyStack(){};
         void push(int n);
         int pop();
         int min();
    private:
        int stack[MAXLEN];
        int min_stack[MAXLEN];
        int top;//我们设计的指针
};

void MyStack::push(int n)
{
    stack[++top]=n;//数据先入正常栈，此时top已经被更新。
    if(top==0)min_stack[top]=n;//如果min栈中现在还没有数据，则直接将数据存放进去min栈
    else
    {
        min_stack[top]=MIN(n,min_stack[top-1]);//因为原先的min栈栈顶已经存放了目前栈中最小的值，所以只要将即将存入的数据
        //与栈顶元素进行compare即可
    }
    //上面的if-else语句可以合并成一句：min_stack[top]=( (top==0)?n:MIN(n,min_stack[top-1]) );
}

int MyStack::pop()
{
    if(top<0) return -1;
    else
        return stack[top--];//pop会使得top减1,pop之后去取min得到的是剩余元素中最小的元素。
}

int MyStack::min()
{
    if(top<0)return -1;
    else
        return min_stack[top];//这个不是pop，不能对top实行减一的操作。
}

int main()
{
    MyStack my_stack;
    my_stack.push(2);
    my_stack.push(3);
    my_stack.push(1);
    cout<<"Now the min is:"<<my_stack.min()<<endl;
    my_stack.pop();
    cout<<"Now the min is:"<<my_stack.min()<<endl;
    return 0;
}
