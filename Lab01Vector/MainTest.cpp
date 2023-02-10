#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "MyVector_t984h395.h"

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
    // store_data.push_back(line_data.substr(pos, front - pos));
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

            // testing constructor with std::vector
            MyVector<string> m_vector1(data);
            cout << m_vector1.empty() << endl;
            cout << m_vector1[m_vector1.size() / 2] << endl;
            // print the input in reverse order

            for (size_t i = (m_vector1.size()) / 2; i >= 0; --i)
            {
                cout << m_vector1[i] << " ";
                if (i == 0)
                    break;
            }
            cout << endl;

            // testing push_back()
            MyVector<string> m_vector2;
            for (size_t i = data.size() - 1; i >= 0; --i)
            {
                m_vector2.push_back(data[i]);
                if (i == 0)
                    break;
            }
            // testing iterator
            for (MyVector<string>::const_iterator x = m_vector2.begin(); x != m_vector2.end(); ++x)
            {
                cout << *x << " ";
            }
            cout << endl;

            // testing pop_back() and append()
            MyVector<string> m_vector3(m_vector1);
            for (size_t i = 0; i < m_vector3.size() / 2; ++i)
            {
                m_vector3.pop_back();
            }
            m_vector3.append(std::move(m_vector1));
            m_vector3.append(std::move(m_vector2));
            for (MyVector<string>::const_iterator x = m_vector3.begin(); x != m_vector3.end(); ++x)
            {
                cout << *x << " ";
            }
            cout << endl;
        }
    }

    return 1;
}