#ifndef __MYNUMBER_H__
#define __MYNUMBER_H__

#include <algorithm>
#include <iostream>
using namespace std;

template <typename DataType>
class MyNumber
{
public:
    explicit MyNumber(DataType rhs = 0) // default constructor
    {
        // code begins
        num = new DataType{rhs}; // allocate memory for num
        // code ends
    }

    MyNumber(const MyNumber<DataType> &rhs) // copy constructor with a MyNumber instance
    {
        // code begins
        num = new DataType{*rhs.num}; // allocate memory for num
        // code ends
    }

    MyNumber(MyNumber<DataType> &&rhs) // move constructor with a MyNumber instance
    {
        // code begins
        rhs.num = nullptr; // set rhs.num to nullptr
        // code ends
    }

    MyNumber &operator=(const MyNumber<DataType> &rhs) // copy assignment with a MyNumber instance
    {
        // code begins
        MyNumber copy = rhs; // copy rhs
        swap(*this, copy);   // swap *this and copy
        return *this;        // return *this
        // code ends
    }

    MyNumber &operator=(MyNumber<DataType> &&rhs) // move assignment with a MyNumber instance
    {
        // code begins
        swap(num, *rhs.num); // swap num and *rhs.num
        return *this;        // return *this
        // code ends
    }

    ~MyNumber(void) // destructor
    {
        // code begins
        delete num; // delete num
        // code ends
    }

    DataType read(void) const
    {
        // code begins
        return *num; // return *num
        // code ends
    }

    void write(DataType rhs)
    {
        // code begins
        *num = rhs; // set *num to rhs
        // code ends
    }

private:
    /* data */
    DataType *num;
};

#endif // __MYVECTOR_H__