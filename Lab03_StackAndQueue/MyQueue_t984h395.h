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
        if (newSize <= this->size())
        {
            dataEnd = dataStart + newSize - 1;
            this->truncate(dataEnd + 1);
        }
        else
        {
            size_t newCapacity = std::max(this->capacity() * 2, newSize);
            reserve(newCapacity);
            dataEnd = dataStart + this->size() - 1;
        }
        // code ends
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity)
    {
        // code begins
        if (newCapacity > this->capacity())
        {
            MyVector<DataType> temp(newCapacity);
            size_t n = this->size();
            for (size_t i = 0; i < n; i++)
            {
                temp[i] = (*this)[dataStart + i];
            }
            dataEnd = dataStart + n - 1;
            std::swap(*this, temp);
        }
        // code ends
    }

public:
    // default constructor
    explicit MyQueue(size_t initSize = 0)
    {
        // code begins
        dataStart = 0;
        dataEnd = initSize - 1;
        // code ends
    }

    // copy constructor
    MyQueue(const MyQueue &rhs)
    {
        // code begins
        dataStart = 0;
        dataEnd = this->size() - 1;
        // code ends
    }

    // move constructor
    MyQueue(MyQueue &&rhs)
    {
        // code begins
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
        dataStart = 0;
        dataEnd = 0;
        this->clear();
        // code ends
    }

    // copy assignment
    MyQueue &operator=(const MyQueue &rhs)
    {
        // code begins
        if (this != &rhs)
        {
            MyVector<DataType>::operator=(rhs);
            dataStart = 0;
            dataEnd = this->size() - 1;
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
            MyVector<DataType>::operator=(std::move(rhs));
            dataStart = rhs.dataStart;
            dataEnd = rhs.dataEnd;
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
        if (this->size() == this->capacity())
        {
            resize(this->size() + 1);
        }
        dataEnd++;
        (*this)[dataEnd] = x;
        // code ends
    }

    // insert x into the queue
    void enqueue(DataType &&x)
    {
        // code begins
        if (this->size() == this->capacity())
        {
            resize(this->size() + 1);
        }
        dataEnd++;
        (*this)[dataEnd] = std::move(x);
        // code ends
    }

    // remove the first element from the queue
    void dequeue(void)
    {
        // code begins
        if (empty())
        {
            throw std::out_of_range("queue is empty");
        }
        dataStart++;
        if (empty())
        {
            dataStart = 0;
            dataEnd = -1;
        }
        // code ends
    }

    // access the first element of the queue
    const DataType &front(void) const
    {
        // code begins
        if (empty())
        {
            throw std::out_of_range("queue is empty");
        }
        return (*this)[dataStart];
        // code ends
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins
        return dataStart > dataEnd;

        // code ends
    }

    // access the size of the queue
    size_t size() const
    {
        // code begins
        return dataEnd - dataStart + 1;
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

#endif // __MYQUEUE_H__