#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "MyLinkedList_t984h395.h"

using namespace std;

void readInstances(const string &line_data, vector<string> &store_data)
{
    int pos = 0;
    int front = 0;
    while (front < line_data.size())
    {
        if (line_data[front] == ' ')
        {
            store_data.push_back(line_data.substr(pos, front - pos));
            pos = front + 1;
        }
        front++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Please provide a test instance file!" << endl;
        return 0;
    }

    ifstream f_input;
    f_input.open(argv[1]);
    vector<string> data;
    if (0 == f_input.is_open())
    {
        cout << "Error for opening the test instance file!" << endl;
        return 0;
    }
    else
    {
        string line;
        while (getline(f_input, line))
        {
            readInstances(line, data);
            MyLinkedList<string> ml_1;

            //  Test push front function
            for (int i = 0; i < data.size(); i++)
            {
                ml_1.push_front(data[i]);
            }

            // Test empty, size, front, back, and push back functions
            cout << "" << ml_1.empty() << endl;
            cout << "" << ml_1.size() << endl;
            cout << "" << ml_1.front() << endl;
            cout << "" << ml_1.back() << endl;

            MyLinkedList<string> ml_2;
            for (int i = data.size() / 2; i < data.size(); i++)
            {
                ml_2.push_back(data[i]);
            }

            // Test the Construction function
            MyLinkedList<string> ml_3 = MyLinkedList<string>(MyLinkedList<string>(ml_1));
            for (MyLinkedList<string>::iterator itr = ml_2.end(); itr != ml_2.begin(); --itr)
            {
                ml_3.push_back(*itr);
            }

            // Test the ++operation --operation
            for (MyLinkedList<string>::iterator itr = ml_3.begin(); itr != ml_3.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
            for (MyLinkedList<string>::iterator itr = ml_3.end(); itr != ml_3.begin(); itr--)
            {
                cout << *itr << " ";
            }
            cout << endl;

            // Test the swapAdjElements function
            MyLinkedList<string>::iterator it = ml_3.begin();
            ml_3.swapAdjElements(it);
            for (MyLinkedList<string>::iterator itr = ml_3.begin(); itr != ml_3.end(); itr++)
            {
                cout << *itr << " ";
            }
            cout << endl;

            // Test the reverselist function
            ml_3.reverseList();
            for (MyLinkedList<string>::iterator itr = ml_3.begin(); itr != ml_3.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;

            // Test appendList, pop_back functions
            ml_3.appendList(std::move(ml_2));
            ml_3.pop_back();
            for (MyLinkedList<string>::iterator itr = ml_3.begin(); itr != ml_3.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
            ml_3.clear();
            cout << "" << ml_3.size();
        }
    }

    return 0;
}