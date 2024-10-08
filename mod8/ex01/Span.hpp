#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Span {
 private:
  unsigned int _n;
  std::vector<int> _vec;

 public:
  Span() = delete;
  Span(unsigned int n);
  Span(Span const &src);
  ~Span();
  Span &operator=(Span const &rhs);

  void addNumber(int n);
  void addNumbers(unsigned int n);
  int shortestSpan();
  int longestSpan();
};