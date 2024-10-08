
#include <iostream>
#include <vector>

#include "EasyFind.hpp"

int main(void) {
  std::vector<int> vec;
  std::cout << " Testing with non const vector<int> " << std::endl;
  for (int i = 0; i < 10; i++) vec.push_back(i);
  try {
    std::cout << "Found: " << *easyfind(vec, 5) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "Found: " << *easyfind(vec, 42) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << " Testing with const vector<int> " << std::endl;
  const std::vector<int> cvec(vec);
  try {
    std::cout << "Found: " << *easyfind(cvec, 5) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "Found: " << *easyfind(cvec, 42) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}