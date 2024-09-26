#include "Serializer.hpp"

int main() {
  Data data;
  data.n = 42;
  data.s2 = "Hello, World!";
  data.ptr = &data.n;

  uintptr_t raw = Serializer::serialize(&data);
  Data *data2 = Serializer::deserialize(raw);

  std::cout << "=== Data ===" << std::endl;
  std::cout << "data.n: " << data.n << std::endl;
  std::cout << "data.s2: " << data.s2 << std::endl;
  std::cout << "data.ptr value: " << *static_cast<int *>(data.ptr) << std::endl;
  std::cout << "data.ptr address: " << data.ptr << std::endl;

  std::cout << "=== Data2 ===" << std::endl;
  std::cout << "data.n: " << data2->n << std::endl;
  std::cout << "data.s2: " << data2->s2 << std::endl;
  std::cout << "data.ptr value: " << *static_cast<int *>(data2->ptr)
            << std::endl;
  std::cout << "data.ptr address: " << data2->ptr << std::endl;

  return 0;
}