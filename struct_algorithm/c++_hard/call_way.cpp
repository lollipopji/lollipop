/*
 * 说明：主要验证c++中几种函数调用方式：包括_cdecl 和_stdcall 和 _thiscall
 * 理论区别：_cdecl是c/c++的默认调用方式（普通的函数调用都是使用它），参数从右向左入栈，由调用者清栈
 * __stdcall是c++标准的调用方式,参数由右向左入栈，由函数本身清栈
 * __thiscall主要是类成员函数的调用方式,会使用一个默认的寄存器来存放this指针。
 * 貌似在gun的编译器下得到的结果没有在visual studio里面运行结果直观。
 */
#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
    public:
        A(){};
        A(int n):num(n){};
        ~A(){};
        void get_num();
        static void get_static_num();
        static int static_num;
        int num;
};
int A::static_num=20;

void A::get_num()
{
    cout<<num<<endl;
}

void A::get_static_num()
{
    cout<<"hello world"<<endl;
    cout<<A::static_num<<endl;
}

void func()
{
    cout<<"I am just a func!"<<endl;
}

int main()
{
    A*a=new A(2);
    cout<<typeid(&A::get_num).name()<<endl;
    cout<<typeid(&A::get_static_num).name()<<endl;
    cout<<typeid(&func).name()<<endl;
    a->get_num();
    A::get_static_num();
    func();
    cout<<typeid(a->num).name()<<endl;
    cout<<typeid(A::static_num).name()<<endl;
    return 0;
}
