#include "MutantStack.hpp"
#include "list"


int main() {
  {
    std::cout << "========MUTANTSTACK==========" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Mstack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Mstack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::cout << "==Copy constructor==" << std::endl;
    std::stack<int> s(mstack);
    MutantStack<int>::iterator it2 = mstack.begin();
    MutantStack<int>::iterator ite2 = mstack.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
      std::cout << *it2 << std::endl;
      ++it2;
    }
    std::cout << "==Assignation operator==" << std::endl;
    MutantStack<int> mstack2;
    mstack2 = mstack;
    MutantStack<int>::iterator it3 = mstack2.begin();
    MutantStack<int>::iterator ite3 = mstack2.end();
    ++it3;
    --it3;
    while (it3 != ite3) {
      std::cout << *it3 << std::endl;
      ++it3;
    }
    std::cout << "==Range Constructor==" << std::endl;
    MutantStack<int>::iterator it4 = mstack2.begin();
    MutantStack<int>::iterator ite4 = mstack2.end();
    MutantStack<int> mstack3(it4, ite4);
    MutantStack<int>::iterator it5 = mstack3.begin();
    MutantStack<int>::iterator ite5 = mstack3.end();
    while (it5 != ite5) {
      std::cout << *it5 << std::endl;
      ++it5;
    }
    std::cout << "==Push 42==" << std::endl;
    mstack3.push(42);
    MutantStack<int>::iterator it6 = mstack3.begin();
    MutantStack<int>::iterator ite6 = mstack3.end();
    while (it6 != ite6) {
      std::cout << *it6 << std::endl;
      ++it6;
    }
  }
  {
    std::cout << "========LIST==========" << std::endl;
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << "Mstack top: " << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << "Mstack size: " << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::cout << "==Copy constructor==" << std::endl;
    std::list<int> s(mstack);
    std::list<int>::iterator it2 = mstack.begin();
    std::list<int>::iterator ite2 = mstack.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
      std::cout << *it2 << std::endl;
      ++it2;
    }
    std::cout << "==Assignation operator==" << std::endl;
    std::list<int> mstack2;
    mstack2 = mstack;
    std::list<int>::iterator it3 = mstack2.begin();
    std::list<int>::iterator ite3 = mstack2.end();
    ++it3;
    --it3;
    while (it3 != ite3) {
      std::cout << *it3 << std::endl;
      ++it3;
    }
    std::cout << "==Range Constructor==" << std::endl;
    std::list<int>::iterator it4 = mstack2.begin();
    std::list<int>::iterator ite4 = mstack2.end();
    std::list<int> mstack3(it4, ite4);
    std::list<int>::iterator it5 = mstack3.begin();
    std::list<int>::iterator ite5 = mstack3.end();
    while (it5 != ite5) {
      std::cout << *it5 << std::endl;
      ++it5;
    }
    std::cout << "==Push 42==" << std::endl;
    mstack3.push_back(42);
    std::list<int>::iterator it6 = mstack3.begin();
    std::list<int>::iterator ite6 = mstack3.end();
    while (it6 != ite6) {
      std::cout << *it6 << std::endl;
      ++it6;
    }

  }
  
    return 0;
}