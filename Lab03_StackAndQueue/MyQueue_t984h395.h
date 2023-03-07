#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include <algorithm>

#include "MyVector.h"
template <typename DataType>
class MyQueue : private MyVector<DataType>
{
private:
    size_t dataStart, dataEnd;

    // changes the size of the array to newSize
    void resize(size_t newSize)
    {
        // code begins
        MyVector<DataType>::resize(newSize);
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
    explicit MyQueue(size_t initSize = 0) : MyVector<DataType>(initSize), dataStart(0), dataEnd(0)
    {
        // code begins

        // code ends
    }

    // copy constructor
    MyQueue(const MyQueue &rhs) : MyVector<DataType>(rhs.capacity()), dataStart(0), dataEnd(rhs.size())
    {
        // code begins
        for (size_t i = 0; i < rhs.size(); ++i)
        {
            this->operator[](i) = rhs[i];
        }
        // code ends
    }

    // move constructor
    MyQueue(MyQueue &&rhs) : MyVector<DataType>(std::move(rhs)), dataStart(rhs.dataStart), dataEnd(rhs.dataEnd)
    {
        // code begins
        rhs.dataStart = 0;
        rhs.dataEnd = 0;
        // code ends
    }

    // destructor
    ~MyQueue()
    {
        // code begins
        // There's no need to call `delete` here
        // The base class destructor will be called automatically
        // code ends
    }

    // copy assignment
    MyQueue &operator=(const MyQueue &rhs)
    {
        // code begins
        if (this != &rhs)
        {
            // Free up the memory used by the current dynamic array
            this->~MyVector();

            // Copy the content of the other queue to this queue
            this->operator=(rhs);
            dataStart = 0;
            dataEnd = rhs.size();
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
            // Free up the memory used by the current dynamic array
            this->~MyVector();

            // Move the content of the other queue to this queue
            this->operator=(std::move(rhs));
            dataStart = rhs.dataStart;
            dataEnd = rhs.dataEnd;

            // Set the other queue to be empty
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
        if (dataEnd == MyVector<DataType>::size())
        {
            // The dynamic array is full, resize it
            reserve(2 * MyVector<DataType>::capacity());
        }
        MyVector<DataType>::operator=(x);
        ++dataEnd;
        // code ends
    }
    // insert x into the queue
    void enqueue(DataType &&x)
    {
        // code begins
        if (dataEnd == MyVector<DataType>::size())
        {
            // The dynamic array is full, resize it
            reserve(2 * MyVector<DataType>::capacity());
        }
        MyVector<DataType>::operator[](dataEnd) = std::move(x);
        ++dataEnd;
        // code ends
    }

    // remove the first element from the queue
    void dequeue(void)
    {
        // code begins
        if (empty())
        {
            // The queue is empty, cannot dequeue
            throw std::underflow_error("Queue is empty");
        }
        ++dataStart;
        if (dataStart > dataEnd)
        {
            // The queue is now empty, reset the indices
            dataStart = 0;
            dataEnd = 0;
        }
        // code ends
    }

    // access the first element of the queue
    const DataType &front(void) const
    {
        // code begins
        if (empty())
        {
            // The queue is empty, cannot return front element
            throw std::underflow_error("Queue is empty");
        }
        return MyVector<DataType>::operator[](0);
        // code ends
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        return dataStart == dataEnd;
        // code ends
    }

    // access the size of the queue
    size_t size() const
    {
        // code begins
        return dataEnd - dataStart;
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