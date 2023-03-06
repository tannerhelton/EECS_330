#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include <iostream>

template <typename DataType>
class MyVector
{
public:
  MyVector(const int init_capacity = 16) : theCapacity{init_capacity},
                                           theSize{0}
  {
    data = new DataType[init_capacity];
  }

  ~MyVector()
  {
    delete[] data;
  }

  int size(void)
  {
    return theSize;
  }

  int capacity(void)
  {
    return theCapacity;
  }

  void print(void)
  {
    std::cout << "Printing the vector" << std::endl;
    for (int i = 0; i < theSize; ++i)
    {
      std::cout << data[i] << std::endl;
      // std::cout << *(data + i) << std::endl;
    }
  }

  void insert(const DataType &value, const int index)
  {
    if (index <= theSize)
    {
      if (theSize >= theCapacity)
      {
        resize(theSize + 1);
      }
      else
      {
        ++theSize;
      }

      for (int i = theSize - 2; i >= index; --i)
      {
        data[i + 1] = std::move(data[i]);
      }
      data[index] = value;
    }
    return;
  }

  void push_back(const DataType &value)
  {
    insert(value, theSize);
  }

  void reserve(const int newCapacity)
  {
    if (newCapacity > theCapacity)
    {
      theCapacity = newCapacity;
      DataType *tmp = new DataType[newCapacity];
      for (int i = 0; i < theSize; ++i)
      {
        tmp[i] = std::move(data[i]);
      }
      std::swap(data, tmp);
      delete[] tmp;
    }
    return;
  }

  void resize(const int newSize)
  {
    theSize = newSize;
    reserve(2 * newSize);
    return;
  }

  void remove(const int index)
  {
    if (index >= 0 && index <= theSize - 1)
    {
      for (int i = index; i < theSize - 1; ++i)
      {
        data[i] = std::move(data[i + 1]);
      }
      --theSize;
    }
    return;
  }

  void pop_back(void)
  {
    remove(theSize - 1);
    return;
  }

private:
  DataType *data = nullptr;
  int theSize;     // the num of elements we have
  int theCapacity; // the num of elements we can hold
};

#endif
