#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <utility>
#include <vector>

template <typename DataType>
class MyVector
{
  private:
    /* data */
    size_t theSize;                         // the number of data elements the vector is currently holding
    size_t theCapacity;                     // maximum data elements the vector can hold
    DataType *data;                         // address of the data storage

  public:
    
    static const size_t SPARE_CAPACITY = 16;   // initial capacity of the vector

    // default constructor
    explicit MyVector(size_t initSize = 0) : 
        theSize{initSize},
        theCapacity{initSize + SPARE_CAPACITY}
    {
        // code begins

        // code ends
    }

    // copy constructor
    MyVector(const MyVector & rhs) : 
        theSize{rhs.theSize},
        theCapacity{rhs.theCapacity}
    {
        // code begins
        
        // code ends
    }

    // move constructor
    MyVector(MyVector&& rhs):
        theSize{rhs.theSize},
        theCapacity{rhs.theCapacity},
        data{rhs.data}
    {
        // code begins
        
        // code ends
    }

    // copy constructor from STL vector implementation
    MyVector(const std::vector<DataType> & rhs) :
        theSize{rhs.size()},
        theCapacity{rhs.size() + SPARE_CAPACITY}
    {
        // code begins
        
        // code ends 
    }

    // destructor
    ~MyVector(){
        // code begins
        
        // code ends
    };

    // copy assignment
    MyVector & operator= (const MyVector& rhs)
    {
        // code begins
        
        // code ends
    }

    // move assignment
    MyVector & operator= (MyVector && rhs)
    {
        // code begins
        
        // code ends
    }

    // change the size of the array
    void resize(size_t newSize)
    {
        // code begins
        
        // code ends
    }

    // allocate more memory for the array
    void reserve(size_t newCapacity)
    {
        // code begins
        
        // code ends       
    }

    // data access operator (without bound checking)
    DataType & operator[] (size_t index)
    {
        // code begins
        
        // code ends
    }

    const DataType & operator[](size_t index) const
    {
        // code begins
        
        // code ends
    }

    // check if the vector is empty; return TURE if the vector is empty
    bool empty() const
    {
        // code begins
        
        // code ends
    }

    // returns the size of the vector
    size_t size() const 
    {
        // code begins
        
        // code ends
    }

    // returns the capacity of the vector
    size_t capacity() const 
    {
        // code begins
        
        // code ends
    }

    // insert an data element to the end of the vector
    void push_back(const DataType & x)
    {
        // code begins
        
        // code ends
    }

    void push_back(DataType && x)
    {
        // code begins
        
        // code ends
    }

    // append a vector as indicated by the parameter to the current vector
    MyVector<DataType>& append(MyVector<DataType> && rhs)
    {
        // code begins
        
        // code ends
    }

    // remove the last data element from the array
    void pop_back()
    {
        // code begins
        
        // code ends
    }

    // returns the last data elemtn from the array
    const DataType& back() const 
    {
        // code begins
        
        // code ends
    }

    // iterator implementation

    typedef DataType* iterator;
    typedef const DataType* const_iterator;

    iterator begin()
    {
        // code begins
        
        // code ends
    }

    const_iterator begin() const
    {
        // code begins
        
        // code ends
    }

    iterator end()
    {
        // code begins
        
        // code ends
    }

    const_iterator end() const 
    {
        // code begins
        
        // code ends
    }

};


#endif // __MYVECTOR_H__