#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
  std::cout << "Span constructor" << std::endl;
}

Span::~Span() { std::cout << "Span destructor" << std::endl; }

Span::Span(Span const &src) {
  *this = src;
}

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    _n = rhs._n;
    _vec = rhs._vec;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (_vec.size() >= _n) {
    throw std::out_of_range("Span is full");
  }
  _vec.push_back(n);
}

void Span::addNumbers(unsigned int n) {
  srand(time(NULL));
  if (_vec.size() + n > _n) {
    throw std::out_of_range("Span is full");
  }
  for (unsigned int i = 0; i < n; i++) {
    addNumber(rand());
  }
}

int Span::shortestSpan() {
  if (_vec.size() < 2) {
    throw std::out_of_range("Not enough elements");
  }
  std::sort(_vec.begin(), _vec.end());
  int min = _vec[1] - _vec[0];
  for (unsigned int i = 2; i < _vec.size(); i++) {
    int diff = _vec[i] - _vec[i - 1];
    if (diff < min) {
      min = diff;
    }
  }
  return min;
}

int Span::longestSpan() {
  if (_vec.size() < 2) {
    throw std::out_of_range("Not enough elements");
  }
  std::sort(_vec.begin(), _vec.end());
  return _vec[_vec.size() - 1] - _vec[0];
}