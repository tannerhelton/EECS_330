#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include <algorithm>

#include "MyVector_t984h395.h"
template <typename DataType>
class MyQueue : private MyVector<DataType>
{
private:
    size_t dataStart, dataEnd;

    // changes the size of the array to newSize
    void resize(size_t newSize)
    {
        // code begins
        MyVector<DataType>::resize();
        if (MyVector<DataType>::size == newSize)
        {
            dataEnd = newSize;
        }
        // code ends
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity)
    {
        // code begins
        MyVector<DataType>::reserve(newCapacity);
        // code ends
    }

public:
    // default constructor
    explicit MyQueue(size_t initSize = 0)
    {
        // code begins
        MyVector<DataType>::reserve(initSize + MyVector<DataType>::SPARE_CAPACITY);
        dataStart = 0;
        dataEnd = 0;
        // code ends
    }

    // copy constructor
    MyQueue(const MyQueue &rhs)
    {
        // code begins
        dataStart = 0;
        dataEnd = 0;
        MyVector<DataType>::reserve(rhs.size());
        MyVector<DataType>::insert(MyVector<DataType>::end(), rhs.begin(), rhs.end());
        dataEnd = rhs.size();
        // code ends
    }

    // move constructor
    MyQueue(MyQueue &&rhs)
    {
        // code begins
        MyVector<DataType>::operator=(std::move(rhs));
        dataStart = rhs.dataStart;
        dataEnd = rhs.dataEnd;
        rhs.dataStart = 0;
        rhs.dataEnd = 0;
        // code ends
    }

    // destructor
    ~MyQueue()
    {
        // code begins
        // Base class destructor is called
        // code ends
    }

    // copy assignment
    MyQueue &operator=(const MyQueue &rhs)
    {
        // code begins
        if (this != &rhs)
        {
            MyVector<DataType>::operator=(rhs);
            dataStart = rhs.dataStart;
            dataEnd = rhs.dataEnd;
        }
        return *this;
        // code ends
    }

    // move assignment
    MyQueue &operator=(MyQueue &&rhs)
    {
        // code begins
        if (this != &rhs)
        {
            // base move assignment
            MyVector<DataType>::operator=(std::move(rhs));

            // fill queue with data from other queue
            dataStart = rhs.dataStart;
            dataEnd = rhs.dataEnd;

            // empty other queue
            rhs.dataStart = 0;
            rhs.dataEnd = 0;
        }
        return *this;
        // code ends
    }

    // insert x into the queue
    void enqueue(const DataType &x)
    {
        // code begins
        push_back(x);
        ++dataEnd;
        // code ends
    }
    // insert x into the queue
    void enqueue(DataType &&x)
    {
        // code begins
        MyVector<DataType>::push_back(x);
        ++dataEnd;
        // code ends
    }

    // remove the first element from the queue
    void dequeue(void)
    {
        // code begins
        for (size_t i = 0; i < dataEnd; i++)
        {
            MyVector<DataType>::operator[](i) = MyVector<DataType>::operator[](i + 1);
        }
        MyVector<DataType>::pop_back();
        dataEnd--;
        // code ends
    }

    // access the first element of the queue
    const DataType &front(void) const
    {
        // code begins
        if (empty())
        {

            throw std::out_of_range("Queue is empty");
        }
        return (*this)[dataStart];
        // code ends
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        return (size() == 0);
        // code ends
    }

    // access the size of the queue
    size_t size() const
    {
        // code begins
        return (dataEnd - dataStart);
        // code ends
    }

    // access the capacity of the queue
    size_t capacity(void) const
    {
        // code begins
        return MyVector<DataType>::capacity();
        // code ends
    }
};

#endif // MYQUEUE_H