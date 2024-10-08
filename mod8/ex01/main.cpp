#include <iostream>

#include "Span.hpp"

int main() {
  {
    std::cout << "==Default test==" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    std::cout << "==Test with 10000 numbers==" << std::endl;
    Span sp = Span(10000);
    try {
      sp.addNumbers(10000);
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "==Test with 1 number==" << std::endl;
    Span sp = Span(1);
    try {
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << "==Test with overflow==" << std::endl;
  Span sp = Span(5);
  try {
    sp.addNumbers(6);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "==Test with 5 numbers==" << std::endl;
  try {
    sp.addNumbers(5);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "==Test with copy constructor==" << std::endl;
  Span sp1(sp);
  try {
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}