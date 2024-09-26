#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() { std::cout << "Base destructor" << std::endl; }

Base* Base::generate(void) {
  srand(time(NULL));
  int random = rand() % 3;
  if (random == 0) {
    return new A();
  } else if (random == 1) {
    return new B();
  } else {
    return new C();
  }
}

void Base::identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Unknown" << std::endl;
  }
}

void Base::identify(Base& p) {
    identify(&p);
}