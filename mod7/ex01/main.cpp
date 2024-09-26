#include <iostream>

#include "Iter.hpp"

template <typename T>
void print(T const &x) {
  std::cout << x << std::endl;
}

template <typename T>
void addOne(T &x) {
  x++;
}

template <typename T>
class Awesome {
 public:
  Awesome(T const &x) : _n(x) {}
  T const &get() const { return _n; }
  T operator++(int) {
    T tmp = _n;
    _n++;
    return tmp;
  }
  T operator++() {
    _n++;
    return _n;
  }

 private:
  T _n;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Awesome<T> const &i) {
  return o << i.get();
}

int main(void) {
  std::cout << "====CREATING ARRAYS====" << std::endl;
  int tab[] = {0, 1, 2, 3, 4};
  int len = sizeof(tab) / sizeof(tab[0]);
  Awesome<int> tab2(42);
  Awesome<int> tab3[] = {tab2, tab2, tab2, tab2, tab2};
  int len2 = sizeof(tab3) / sizeof(tab3[0]);
  char tab4[] = {'a', 'b', 'c', 'd', 'e'};
  int len3 = sizeof(tab4) / sizeof(tab4[0]);
  std::cout << "====ITERATING OVER INT ARRAY====" << std::endl;
  iter(tab, len, print<const int>);
  iter(tab3, len2, print<Awesome<int>>);
  iter(tab4, len3, print<const char>);
  std::cout << "====ITERATING OVER INT ARRAY AND ADDING ONE====" << std::endl;
  iter(tab, len, addOne<int>);
  iter(tab, len, print<const int>);
  iter(tab3, len2, addOne<Awesome<int>>);
  iter(tab3, len2, print<Awesome<int>>);
  iter(tab4, len3, addOne<char>);
  iter(tab4, len3, print<const char>);
  return 0;
}