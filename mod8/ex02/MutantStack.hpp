#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() : std::stack<T>() {}
  MutantStack(MutantStack const &src) : std::stack<T>(src) {}
  ~MutantStack() {}
  MutantStack &operator=(MutantStack const &rhs) {
    if (this != &rhs) {
      std::stack<T>::operator=(rhs);
    }
    return *this;
  }

	template <typename iterator>
	MutantStack(iterator first, iterator last) : std::stack<T>() {
		while (first != last) {
			std::stack<T>::push(*first);
			++first;
		}
	}

  typedef typename std::stack<T>::container_type::iterator iterator;

  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }
};