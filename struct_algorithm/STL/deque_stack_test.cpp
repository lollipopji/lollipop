#include <iostream>
#include "deque_stack.h"

using namespace std;
/*
 *在这个程序中主要是针对异常捕获的一些流程的熟悉
 *主要是在.h中编写自己的异常类（需要从exception中进行继承）
 *然后在try语句块中进行包含，之后再在catch语句中捕获后进行处理。
 */
int main()
{
    try
    {
        Stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        cout<<st.pop()<<" ";
        cout<<st.pop()<<" ";
        st.top()=77;
        st.push(4);
        st.push(5);
        st.pop();
        cout<<st.pop()<<" ";
        cout<<st.pop()<<endl;
        cout<<st.pop()<<endl;//throw the ReadEmptyStack exception
        cout<<"Can I be done?"<<endl;// This is one can not be output.
    }
    catch(const ReadEmptyStack &e)
    {
        cout<<"ReadEmptyStack Exception:"<<e.what()<<endl;
    }
    return 0;
}
