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
        this->resize(initSize);
        // code ends
    }

    // copy constructor
    MyStack(const MyStack &rhs)
    {
        // code begins
        this->reserve(rhs.size());
        std::copy(rhs.begin(), rhs.end(), this->begin());
        // code ends
    }

    // move constructor
    MyStack(MyStack &&rhs)
    {
        // code begins
        this->swap(rhs);
        // code ends
    }

    // destructor
    ~MyStack()
    {
    }

    // copy assignment
    MyStack &operator=(const MyStack &rhs)
    {
        // code begins
        if (this != &rhs)
        {
            // Copy the underlying vector from the input object
            this->clear();
            this->reserve(rhs.size());
            std::copy(rhs.begin(), rhs.end(), this->begin());
        }
        return *this;
        // code ends
    }

    // move assignment
    MyStack &operator=(MyStack &&rhs)
    {
        // code begins
        if (this != &rhs)
        {
            // Move the underlying vector from the input object
            this->clear();
            this->swap(rhs);
        }
        return *this;
        // code ends
    }

    // insert x to the stack
    void push(const DataType &x)
    {
        // code begins
        this->push_back(x);
        // code ends
    }

    // insert x to the stack
    void push(DataType &&x)
    {
        // code begins
        this->emplace_back(std::move(x));
        // code ends
    }

    // remove the last element from the stack
    void pop(void)
    {
        // code begins
        this->pop_back();
        // code ends
    }

    // access the last element of the stack
    const DataType &top(void) const
    {
        // code begins
        return this->back();
        // code ends
    }

    // check if the stack is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        return this->MyVector<DataType>::empty();
        // code ends
    }

    // access the size of the stack
    size_t size() const
    {
        // code begins
        return this->MyVector<DataType>::size();
        // code ends
    }

    // access the capacity of the stack
    size_t capacity(void) const
    {
        // code begins
        return this->MyVector<DataType>::capacity();
        // code ends
    }
};

#endif // __MYSTACK_H__