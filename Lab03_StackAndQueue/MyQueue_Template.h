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

        // code ends
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity)
    {
        // code begins

        // code ends
    }

  public:

    // default constructor
    explicit MyQueue(size_t initSize = 0)
    {
        // code begins

        // code ends
    }

    // copy constructor
    MyQueue(const MyQueue & rhs)
    {
        // code begins

        // code ends
    }

    // move constructor
    MyQueue(MyQueue && rhs)
    {
        // code begins

        // code ends
    }

    // destructor
    ~MyQueue()
    {
        // code begins

        // code ends
    }

    // copy assignment
    MyQueue & operator= (const MyQueue & rhs)
    {
        // code begins

        // code ends
    }

    // move assignment
    MyQueue & operator= (MyQueue && rhs)
    {
        // code begins

        // code ends
    }

    // insert x into the queue
    void enqueue(const DataType & x)
    {
        // code begins

        // code ends
    }

    // insert x into the queue
    void enqueue(DataType && x)
    {
        // code begins

        // code ends
    }

    // remove the first element from the queue
    void dequeue(void)
    {
        // code begins

        // code ends
    }

    // access the first element of the queue
    const DataType & front(void) const
    {
        // code begins

        // code ends
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const
    {
        // code begins

        // code ends
    }

    // access the size of the queue
    size_t size() const
    {
        // code begins

        // code ends
    }

    // access the capacity of the queue
    size_t capacity(void) const 
    {
        // code begins

        // code ends
    }

};


#endif // __MYQUEUE_H__