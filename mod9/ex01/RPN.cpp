#include "RPN.hpp"

RPN::RPN() : _stack(std::stack<int>()) {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
  if (this != &other)
    _stack = other._stack;
  return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token)
{
  return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::calculate(int a, int b, const std::string &op)
{
  if (op == "+")
    _stack.push(a + b);
  else if (op == "-")
    _stack.push(a - b);
  else if (op == "*")
    _stack.push(a * b);
  else if (op == "/")
  {
    if (b == 0)
      throw std::invalid_argument("Division by zero");
    _stack.push(a / b);
  }
  else
    throw std::invalid_argument("Invalid operator");
}

int RPN::evalRPN(const std::string &str)
{
  std::string token;
  std::istringstream iss(str);
  while (iss >> token)
  {
    if (isOperator(token))
    {
      if (_stack.size() < 2)
        throw std::invalid_argument("Invalid RPN expression");
      int b = _stack.top();
      _stack.pop();
      int a = _stack.top();
      _stack.pop();
      calculate(a, b, token);
    }
    else
    {
      if (!isdigit(token[0]) || token.length() != 1)
        throw std::invalid_argument("Invalid RPN expression");
      _stack.push(std::stoi(token));
    }
  }
  if (_stack.size() != 1)
    throw std::invalid_argument("Invalid RPN expression");
  return _stack.top();
}