#ifndef DEQUE_STACK_H
#define DEQUE_STACK_H
#include <deque>
#include <exception>

using namespace std;
class ReadEmptyStack:public exception
{
    public:
        virtual const char* what() const throw()
        {
            return "read empty stack";
        }
};

template <typename T>
class Stack
{
    protected:
        deque<T> c;
    public:
        typename deque<T>::size_type size() const
        {
            return c.size();
        }
        bool empty() const
        {
            return c.empty();
        }
        void push(const T& elem)
        {
            c.push_back(elem);
        }
        T pop()
        {
            if(c.empty())
            {
                throw ReadEmptyStack();
            }
            else
            {
                T elem(c.back());
                c.pop_back();
                return elem;
            }
        }
        T& top()
        {
            if(c.empty())
            {
                throw ReadEmptyStack();
            }
            else
            {
                return (c.back());
            }
        }
};
#endif

