#ifndef __MYBINARYHEAP_H__
#define __MYBINARYHEAP_H__

#include <iostream>
#include <cstdlib>

#include "MyVector.h"

// ComparableType should be comparable (<, >, ==, >=, <= operators implemented)
// ComparableType should also have +, +=, -, -= operators implemented to support priority adjustment

template <typename ComparableType>
class MyBinaryHeap
{
private:
    MyVector<ComparableType> data; // the array that holds the data elements

    // moves the data element at the pth position of the array up
    void percolateUp(const size_t p)
    {
        // code begins

        // code ends
    }

    // moves the data element at the pth position of the array down
    void percolateDown(const size_t p)
    {
        // code begins

        // code ends
    }

    // reorders the data elements in the array to ensure heap property
    void buildHeap()
    {
        // code begins

        // code ends
    }

public:
    // default constructor
    explicit MyBinaryHeap() : data(1) // reserve data[0]
    {
        // code begins

        // code ends
    }

    // constructor from a set of data elements
    MyBinaryHeap(const MyVector<ComparableType> &items) : data(1) // reserve data[0]
    {
        // code begins

        // code ends
    }

    // copy constructor
    MyBinaryHeap(const MyBinaryHeap<ComparableType> &rhs)
    {
        // code begins

        // code ends
    }

    // move constructor
    MyBinaryHeap(MyBinaryHeap<ComparableType> &&rhs)
    {
        // code begins

        // code ends
    }

    // copy assignment
    MyBinaryHeap &operator=(const MyBinaryHeap<ComparableType> &rhs)
    {
        // code begins

        // code ends
    }

    // move assignment
    MyBinaryHeap &operator=(MyBinaryHeap<ComparableType> &&rhs)
    {
        // code begins

        // code ends
    }

    // inserts x into the priority queue (copy)
    void enqueue(const ComparableType &x)
    {
        // code begins

        // code ends
    }

    // inserts x into the priority queue (move)
    void enqueue(ComparableType &&x)
    {
        // code begins

        // code ends
    }

    // accesses the data element with the highest priority
    const ComparableType &front()
    {
        // code begins

        // code ends
    }

    // deletes the data element with the highest priority from the queue
    void dequeue()
    {
        // code begins

        // code ends
    }

    // verifies whether the array satisfies the heap property
    bool verifyHeapProperty(void)
    {
        // code begins

        // code ends
    }

    // disrupts heap property by random shuffling
    void disruptHeapProperty(void)
    {
        if (data.size() <= 3)
            return;
        for (size_t i = 0; i < 1000; ++i)
        {
            size_t p = 1 + ((int)rand()) % (data.size() - 1);
            size_t q = 1 + ((int)rand()) % (data.size() - 1);
            std::swap(data[p], data[q]);
        }
        return;
    }

    // merges two heaps; the second heap can be destructed after the merge
    MyBinaryHeap &merge(MyBinaryHeap<ComparableType> &&rhs)
    {
        // code begins

        // code ends
    }

    // increases the priority measure of an element at a specific position and reorder the heap
    void increaseKey(const size_t p, const unsigned int d)
    {
        // code begins

        // code ends
    }

    // decreases the priority measure of an element at a specific position and reorder the heap
    // if the current priority is smaller than the requested decrement, assign priority 0
    void decreaseKey(const size_t p, const unsigned int d)
    {
        // code begins

        // code ends
    }

    // checks whether the heap is empty
    bool empty()
    {
        // code begins

        // code ends
    }

    // removes all data elements from the heap
    void clear()
    {
        // code begins

        // code ends
    }

    // returns the size of the heap
    size_t size()
    {
        // code begins

        // code ends
    }

    // prints the data in the array
    void print()
    {
        const char delim = '\t';
        for (size_t i = 1; i < data.size(); ++i)
        {
            std::cout << data[i] << delim;
        }
        std::cout << std::endl;
        return;
    }
};

#endif // __MYBINARYHEAP_H__