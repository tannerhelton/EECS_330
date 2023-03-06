#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "MyLinkedList.h"

void printStats(MyLinkedList<int> &list)
{
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    std::cout << "Is empty: " << ((list.empty() == 1) ? "true" : "false") << std::endl;
    std::cout << "Size: " << list.size() << std::endl;
}

void printLots(MyLinkedList<int> L, MyLinkedList<int> P)
{
    int size = P.size();
    int posArr[size];
    for (int i = 0; i < size; i++)
    {
        posArr[i] = P.back();
        P.pop_back();
    }

    int i = 0;
    int pIter = 0;
    while (!L.empty())
    {
        if (i == posArr[pIter])
        {
            std::cout << L.back() << std::endl;
            pIter++;
        }
        L.pop_back();
        i++;
    }
}

void printList(MyLinkedList<int> list)
{
    while (!list.empty())
    {
        std::cout << list.front() << std::endl;
        list.pop_front();
    }
}

int main()
{
    MyLinkedList<int> list;
    list.push_back(98);
    list.push_back(99);
    list.push_back(100);
    MyLinkedList<int> test;
    test.push_back(1);
    test.push_back(2);
    list.appendList(MyLinkedList<int>(test));

    printStats(list);
    printList(list);
    // list.reverseList();
    // printStats(list);

    // MyLinkedList<int> l;
    // MyLinkedList<int> p;
    // p.push_front(0);
    // p.push_front(1);
    // p.push_front(2);

    // l.push_front(10);
    // l.push_front(11);
    // l.push_front(12);
    // l.push_front(13);
    // printLots(l, p);
    // printStats(l);

    return 0;
}
