#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        bool isOperator(const std::string& str);
        int evalRPN(const std::string& str);
        void calculate(int a, int b, const std::string& op);
    private:
        std::stack<int> _stack;
};