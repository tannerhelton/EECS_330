#ifndef __MYINFIXCALCULATOR_H__
#define __MYINFIXCALCULATOR_H__

#include <algorithm>
#include <string>

#include "MyStack_t984h395.h"
#include "MyVector_t984h395.h"

class MyInfixCalculator
{

public:
    MyInfixCalculator()
    {
    }

    ~MyInfixCalculator()
    {
    }

    double calculate(const std::string &s)
    {
        // code begins

        // code ends
    }

private:
    // returns operator precedance; the smaller the number the higher precedence
    // returns -1 if the operator is invalid
    // does not consider parenthesis
    int operatorPrec(const char c) const
    {
        switch (c)
        {
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 3;
        case '-':
            return 3;
        default:
            return -1;
        }
    }

    // checks if a character corresponds to a valid parenthesis
    bool isValidParenthesis(const char c) const
    {
        switch (c)
        {
        case '(':
            return true;
        case ')':
            return true;
        default:
            return false;
        }
    }

    // checks if a character corresponds to a valid digit
    bool isDigit(const char c) const
    {
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }

    // computes binary operation given the two operands and the operator in their string form
    double computeBinaryOperation(const std::string &ornd1, const std::string &ornd2, const std::string &opt) const
    {
        double o1 = std::stod(ornd1);
        double o2 = std::stod(ornd2);
        switch (opt[0])
        {
        case '+':
            return o1 + o2;
        case '-':
            return o1 - o2;
        case '*':
            return o1 * o2;
        case '/':
            return o1 / o2;
        default:
            std::cout << "Error: unrecognized operator: " << opt << std::endl;
            return 0.0;
        }
    }

    // tokenizes an infix string s into a set of tokens (operands or operators)
    void tokenize(const std::string &s, MyVector<std::string> &tokens)
    {
        // code begins

        // code ends
    }

    // converts a set of infix tokens to a set of postfix tokens
    void infixToPostfix(MyVector<std::string> &infix_tokens, MyVector<std::string> &postfix_tokens)
    {
        // code begins

        // code ends
    }

    // calculates the final result from postfix tokens
    double calPostfix(const MyVector<std::string> &postfix_tokens) const
    {
        // code begins

        // code ends
    }
};

#endif // __MYINFIXCALCULATOR_H__