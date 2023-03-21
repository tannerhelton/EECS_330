#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

// #include "MyInfixCalculator_t984h395.h"
#include "rawCode.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "You have to provide one test instance file and output file name to run the test main!\n";
        return 0;
    }

    ifstream inFile;
    inFile.open(argv[1]);

    if (inFile.is_open())
    {
        string str;
        std::getline(inFile, str);
        MyInfixCalculator infix_calculator;
        double a = infix_calculator.calculate(str);
        std::cout.precision(3);
        cout << std::fixed << a << endl;
    }
    else
    {
        cout << "The instance.txt file cannot be opened";
    }
    inFile.close();

    return 0;
}
