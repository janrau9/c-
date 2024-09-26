#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#define CHAR_MIN -128
#define CHAR_MAX 127

enum class ScalarType { CHAR, INT, FLOAT, DOUBLE, INVALID };

class ScalarConverter {
 private:
  ScalarType _type;
  static char _char;
  static int _int;
  static float _float;
  static double _double;

 public:
  ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter &obj) = delete;
  ~ScalarConverter() = delete;
  ScalarConverter &operator=(const ScalarConverter &obj) = delete;

  static void convert(const std::string &str);
  static ScalarType getTypeFromStr(const std::string &str);
  static bool isChar(const std::string &str);
  static bool isInt(const std::string &str);
  static bool isFloat(const std::string &str);
  static bool isDouble(const std::string &str);
  static void print();
};

#endif