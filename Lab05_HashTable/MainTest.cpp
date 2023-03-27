#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "MyVector.h"
#include "MyHashTable.h"

using namespace std;

int main(int argc, char* argv[])
{
    //hash_table.preCalPrimes(100);
    //cout << hash_table.nextPrime(83) << endl;

    if (argc != 2)
    {
        std::cout << "Please provide the input file.\n";
        return 1;
    }
    
    ifstream inFile;
    inFile.open(argv[1]);
    MyHashTable<string, int> hash_table;
    MyVector<string> keys;
    if (inFile.is_open())
    {
        string str;
        while(std::getline(inFile, str))
        {
            size_t tp = str.find("\t");
            string k = str.substr(0, tp);
            int v = stoi(str.substr(tp + 1));

            HashedObj<string, int> data(k, v);
        
            bool istag = hash_table.insert(data);
            if(istag)
            {
                cout << "Data inserted: " << k << "\t" << v << endl;
                cout << "Table info: " << hash_table.size() << "\t" << hash_table.capacity() << endl;
            }
            else
            {
                cout << "Insertion failed: " << k << "\t" << v << endl;
            }

            keys.push_back(k);

            
        }

        for(auto itr = keys.begin(); itr != keys.end(); ++ itr)
        {
            int dtag = ((int) rand()) % 10;
            if(dtag)
            {
                bool dstag = hash_table.remove(*itr);
                if(dstag)
                {
                    cout << "Data deleted: " << *itr << endl;
                    cout << "Table info: " << hash_table.size() << "\t" << hash_table.capacity() << endl;
                }
                else
                {
                    cout << "Deletion failed: " << *itr << endl;
                }
            }
            
            HashedObj<string, int> data;
            bool rstag = hash_table.retrieve(*itr, data);
            if(rstag)
            {
                cout << "Data retrieved: " << data.key << "\t" << data.value << endl;
                cout << "Table info: " << hash_table.size() << "\t" << hash_table.capacity() << endl;
            }
            else
            {
                cout << "Retrieval failed: " << *itr << endl;
            }
            
        }
    }
    else
    {
        cout << "The instance.txt file cannot be opened.\n";
        return 1;
    }
    inFile.close();

    return 0;
}


