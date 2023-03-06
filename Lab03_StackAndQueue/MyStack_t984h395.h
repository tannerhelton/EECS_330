#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include <algorithm>

#include "MyVector.h"

template <typename DataType>
class MyStack : private MyVector<DataType>
{  
  public:

    // default constructor
    explicit MyStack(size_t initSize = 0)
    {
        // code begins

        // code ends
    }

    // copy constructor
    MyStack(const MyStack & rhs)
    {
        // code begins

        // code ends
    }

    // move constructor
    MyStack(MyStack && rhs)
    {
        // code begins

        // code ends
    }

    // destructor
    ~MyStack()
    {
        ;    
    }

    // copy assignment
    MyStack & operator= (const MyStack & rhs)
    {
        // code begins

        // code ends
    }

    // move assignment
    MyStack & operator= (MyStack && rhs)
    {
        // code begins

        // code ends
    }

    // insert x to the stack
    void push(const DataType & x)
    {
        // code begins

        // code ends
    }

    // insert x to the stack
    void push(DataType && x)
    {
        // code begins

        // code ends
    }

    // remove the last element from the stack
    void pop(void)
    {
        // code begins

        // code ends
    }

    // access the last element of the stack
    const DataType & top(void) const
    {
        // code begins

        // code ends
    }

    // check if the stack is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins

        // code ends
    }

    // access the size of the stack
    size_t size() const
    {
        // code begins

        // code ends
    }

    // access the capacity of the stack
    size_t capacity(void) const 
    {
        // code begins

        // code ends
    }

};


#endif // __MYSTACK_H__