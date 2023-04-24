#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MyBinaryHeap.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Please provide the input file." << endl;
        exit(1);
    }

    MyBinaryHeap<unsigned int> bh;
    ifstream inFile;
    inFile.open(argv[1]);

    if (inFile.is_open())
    {
        // testing insert
        string str;
        while(getline(inFile, str))
        {
            int num = stoi(str);
            bh.enqueue(static_cast<unsigned int>(num));
            cout << "Data inserted." << "\t";
            cout << "Highest priority:" << bh.front() << endl;            
        }

        // testing heap property
        if(bh.verifyHeapProperty())
            cout << "Heap property checked." << endl;
        else
            cout << "Heap property violated." << endl;

        // testing increaseKey and decreaseKey
        MyBinaryHeap<unsigned int> bh2 = bh;
        
        for(size_t i = 0; i < 5000; ++ i)
        {
            size_t p = 1 + ((int) rand()) % bh2.size();
            unsigned int d = ((int) rand()) % 999999;
            int inc_tag = ((int) rand()) % 2;
            if(inc_tag)
                bh2.increaseKey(p, d);
            else
                bh2.decreaseKey(p, d);
        }
        if(bh2.verifyHeapProperty())
            cout << "Heap property checked." << endl;
        else
            cout << "Heap property violated." << endl;

        // testing merge
        bh.disruptHeapProperty();
        if(bh.verifyHeapProperty())
            cout << "Heap property checked." << endl;
        else
            cout << "Heap property violated." << endl;
        bh2.disruptHeapProperty();
        if(bh2.verifyHeapProperty())
            cout << "Heap property checked." << endl;
        else
            cout << "Heap property violated." << endl;

        bh.merge(move(bh2));
        if(bh.verifyHeapProperty())
            cout << "Heap property checked." << endl;
        else
            cout << "Heap property violated." << endl;

        // testing front and dequeue
        while(!bh.empty())
        {
            unsigned int v = bh.front();
            cout << "Highest priority: " << v << endl;
            bh.dequeue();
        }
    }
    else
    {
            cout << "The input file cannot be opened." << endl;
    }
    inFile.close();
    return 0;
}