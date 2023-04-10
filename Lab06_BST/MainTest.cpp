#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "MyBST.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Please provide the input file." << endl;
        exit(1);
    }
    
    ifstream inFile;
    inFile.open(argv[1]);

    MyBST<int> bst;
    
    if (inFile.is_open())
    {
        vector<int> data;
        string str;

        // testing insert
        while(std::getline(inFile, str))
        {
            int num = stoi(str);
            data.push_back(num);
            bst.insert(num);            
        }
        bst.printTree();

        // testing lowest common ancestor
        for(size_t i = 0; i < 100; ++ i)
        {
            size_t idx = ((int) rand()) % data.size();
            size_t idy = ((int) rand()) % data.size();
            int lca;
            bool ltag = bst.lowestCommonAncestor(data[idx], data[idy], lca);
            if(ltag)
                cout << "The LCA of " << data[idx] << " and " << data[idy] << " is " << lca << "." << endl;
        }

        // testing print
        bst.print(PreOrder);
        bst.print(InOrder);
        bst.print(PostOrder);

        // testing delete
        for(size_t i = 0; i < data.size(); ++ i)
        {
            bst.remove(data[i]);
            cout << "Tree info: " << bst.size() << "\t" << bst.depth() << endl;
        }
    }
    else
    {
        cout << "Input file cannot be opened" << endl;
        exit(1);
    }
    inFile.close();
    return 0;
}




