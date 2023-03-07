#include "MyVector.h"
#include <iostream>

void printStats(MyVector<int> &v)
{
    std::cout << "Back: " << v.back() << std::endl;
    std::cout << "Is empty: " << ((v.empty() == 1) ? "true" : "false") << std::endl;
    std::cout << "Size: " << v.size() << std::endl;
}

int main()
{
    MyVector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    printStats(v1);
    return 0;
}