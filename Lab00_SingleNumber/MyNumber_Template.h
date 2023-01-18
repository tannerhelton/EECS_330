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

        // code ends
    }
    
    MyNumber(const MyNumber<DataType> & rhs)	// copy constructor with a MyNumber instance
    {
        // code begins

        // code ends
    }
    
    MyNumber(MyNumber<DataType> && rhs)	// move constructor with a MyNumber instance
    {
        // code begins

        // code ends
    }
    
    MyNumber & operator= (const MyNumber<DataType> &rhs)	// copy assignment with a MyNumber instance
    {
        // code begins

        // code ends
    }

    MyNumber & operator= (MyNumber<DataType> && rhs)	// move assignment with a MyNumber instance 
    {
        // code begins

        // code ends
    }

    ~MyNumber(void) // destructor
    {
        // code begins

        // code ends
    }
    
    DataType read(void) const
    {   
        // code begins

        // code ends
    }

    void write(DataType rhs)
    {
        // code begins

        // code ends
    }

  private:
    /* data */
    DataType *num;
};


#endif // __MYVECTOR_H__