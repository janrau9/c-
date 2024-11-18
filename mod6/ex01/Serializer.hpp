#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <string>
#include <cstdint>


class Serializer {
 public:
  Serializer() = delete;
  Serializer(const Serializer &obj) = delete;
  ~Serializer() = delete;
  Serializer &operator=(const Serializer &obj) = delete;

  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};


#endif