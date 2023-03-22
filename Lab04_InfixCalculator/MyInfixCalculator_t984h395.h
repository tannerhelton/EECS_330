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
        MyVector<std::string> infix_tokens;
        tokenize(s, infix_tokens);

        MyVector<std::string> postfix_tokens;
        infixToPostfix(infix_tokens, postfix_tokens);

        return calPostfix(postfix_tokens);
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
        std::string current_token;
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (isspace(s[i]))
                continue;

            if (isDigit(s[i]) || s[i] == '.' || (s[i] == '-' && (i == 0 || !isDigit(s[i - 1])) && i < s.length() - 1 && isDigit(s[i + 1])))
            {
                current_token += s[i];
            }
            else
            {
                if (!current_token.empty())
                {
                    tokens.push_back(current_token);
                    current_token.clear();
                }

                if (isValidParenthesis(s[i]) || operatorPrec(s[i]) != -1)
                {
                    tokens.push_back(std::string(1, s[i]));
                }
            }
        }

        if (!current_token.empty())
        {
            tokens.push_back(current_token);
        }
        // code ends
    }

    // converts a set of infix tokens to a set of postfix tokens
    void infixToPostfix(MyVector<std::string> &infix_tokens, MyVector<std::string> &postfix_tokens)
    {
        // code begins
        MyStack<std::string> operator_stack;

        for (const auto &token : infix_tokens)
        {
            if (isDigit(token[0]) || (token.length() > 1 && isDigit(token[1]))) // Operand
            {
                postfix_tokens.push_back(token);
            }
            else if (isValidParenthesis(token[0]))
            {
                if (token[0] == '(')
                {
                    operator_stack.push(token);
                }
                else
                {
                    while (!operator_stack.empty() && operator_stack.top() != "(")
                    {
                        postfix_tokens.push_back(operator_stack.top());
                        operator_stack.pop();
                    }
                    operator_stack.pop(); // Remove the open parenthesis
                }
            }
            else // Operator
            {
                while (!operator_stack.empty() && (operator_stack.top() != "(" && operatorPrec(token[0]) >= operatorPrec(operator_stack.top()[0])))
                {
                    postfix_tokens.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                operator_stack.push(token);
            }
        }

        while (!operator_stack.empty())
        {
            postfix_tokens.push_back(operator_stack.top());
            operator_stack.pop();
        }
        // code ends
    }

    // calculates the final result from postfix tokens
    double calPostfix(const MyVector<std::string> &postfix_tokens) const
    {
        // code begins
        MyStack<double> operandStack;

        for (const auto &token : postfix_tokens)
        {
            if (isDigit(token[0]) || (token.size() > 1 && token[0] == '-' && isDigit(token[1])))
            {
                operandStack.push(std::stod(token));
            }
            else
            {
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();
                double result = computeBinaryOperation(std::to_string(operand1), std::to_string(operand2), token);
                operandStack.push(result);
            }
        }

        return operandStack.top();
        // code ends
    }
};

#endif // __MYINFIXCALCULATOR_H__