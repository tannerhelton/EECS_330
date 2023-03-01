#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "MyQueue.h"
#include "MyStack.h"

using namespace std;

void readInstances(const string& line_data, vector<string>& store_data)
{
    size_t pos = 0; 
    size_t front = 0;
    while(front < line_data.size())
    {
        if(line_data[front] == ' ')
        {
            store_data.push_back(line_data.substr(pos,front-pos));
            pos = front + 1;
        }
        ++ front;
    }
}

int main(int argc, char* argv[])
{

    if(argc != 2)
    {
        cout << "Please provide a test instance file!" <<endl;
        return 0;
    }
    
    ifstream f_input;
    f_input.open(argv[1]);	
    vector<string> data;
    if (0 == f_input.is_open())	    
    {
        cout << "Error for opening the test instance file!"<<endl;
        return 0;
    }
    else
    {
        string line;
        while(getline(f_input, line))
        {
            readInstances(line, data);
            MyStack<string> my_stack;
            MyQueue<string> my_queue;
            
            // for debugging purpose, you can reduce the number of iterations from 100 to a smaller number
            // but remember to change it back before testing
            for (size_t i = 0, j = 0; i < 100; ++ i)
            {
                bool add = ((int) rand()) % 2;
                if(add) 
                {
                    if(j < data.size())
                    {
                        cout << "add:\t" << data[j] << endl;
                        my_stack.push(data[j]);
                        my_queue.enqueue(std::move(data[j]));
                        ++ j;
                        cout << my_stack.top() << "\t" << my_stack.size() << "\t" << my_stack.capacity() << endl;
                        cout << my_queue.front() << "\t" << my_queue.size() << "\t" << my_queue.capacity() << endl;
                    }
                    else
                    {
                        cout << "No more data to add!!!" << endl;
                    }
                }   
                else
                {
                    
                    if(!my_stack.empty() && !my_queue.empty())
                    {
                        cout << "remove:" << endl;
                        cout << my_stack.top() << "\t" << my_stack.size() << "\t" << my_stack.capacity() << endl;
                        cout << my_queue.front() << "\t" << my_queue.size() << "\t" << my_queue.capacity() << endl;
                        my_stack.pop();
                        my_queue.dequeue();
                        
                    }
                    else
                    {
                        cout << "No more data to remove!!!" << endl;
                    }
                }

            }

            MyStack<string> my_stack_2 = std::move(my_stack);
            cout << "remaining stack size:\t" << my_stack_2.size() << endl;
            while(!my_stack_2.empty())
            {
                cout << my_stack_2.top() << endl;
                my_stack_2.pop();
            }
            MyQueue<string> my_queue_2 = std::move(my_queue);
            cout << "remaining queue size:\t" << my_queue_2.size() << endl;
            while(!my_queue_2.empty())
            {
                cout << my_queue_2.front() << endl;
                my_queue_2.dequeue();
            }
        }
    }

    return 1;
}
