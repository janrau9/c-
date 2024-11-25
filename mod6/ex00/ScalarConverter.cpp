#include "ScalarConverter.hpp"

char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;

void ScalarConverter::print()
{
  std::cout << "char: ";
  if (std::isprint(_char))
  {
    std::cout << "'" << _char << "'" << std::endl;
  }
  else if (std::isnan(_double) || std::isinf(_double))
  {
    std::cout << "impossible" << std::endl;
  }
  else if (_double < CHAR_MIN || _double > CHAR_MAX)
  {
    std::cout << "overflow" << std::endl;
  }
  else
  {
    std::cout << "Non displayable" << std::endl;
  }

  std::cout << "int: ";
  if (std::isnan(_double) || std::isinf(_double))
  {
    std::cout << "impossible" << std::endl;
  }
  else if (_double < INT_MIN || _double > INT_MAX)
  {
    std::cout << "overflow" << std::endl;
  }
  else
  {
    std::cout << _int << std::endl;
  }

  std::cout << "float: " << _float << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << _double
            << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
  try
  {
    switch (getTypeFromStr(str))
    {
    case ScalarType::CHAR:
      _char = str[0];
      _int = static_cast<int>(_char);
      _float = static_cast<float>(_char);
      _double = static_cast<double>(_char);
      break;
    case ScalarType::INT:
      _int = std::stoi(str);
      _float = static_cast<float>(_int);
      _double = static_cast<double>(_int);
      if (_int < CHAR_MIN || _int > CHAR_MAX)
      {
        throw std::out_of_range("Out of range");
      }
      _char = static_cast<char>(_int);
      break;
    case ScalarType::FLOAT:
      _float = std::stof(str);
      _int = static_cast<int>(_float);
      _double = static_cast<double>(_float);
            if (_float < CHAR_MIN || _float > CHAR_MAX)
      {
        throw std::out_of_range("Out of range");
      }
      _char = static_cast<char>(_float);
      break;
    case ScalarType::DOUBLE:
      _double = std::stod(str);
      _int = static_cast<int>(_double);
      _float = static_cast<float>(_double);
           if (_double < CHAR_MIN || _double > CHAR_MAX)
      {
        throw std::out_of_range("Out of range");
      }
      _char = static_cast<char>(_double);
      break;
    case ScalarType::INVALID:
      throw std::invalid_argument(
          "please enter a valid scalar type");
      break;
    }
  }
  catch (std::out_of_range &e)
  {
    std::cerr << "Out of Range Error: " << e.what() << std::endl;
    return;
  }
  catch (std::invalid_argument &e)
  {
    std::cerr << "Invalid argument Error: " << e.what() << std::endl;
    return;
  }
  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return;
  }
  print();
}

ScalarType ScalarConverter::getTypeFromStr(const std::string &str)
{
  if (isChar(str))
  {
    return ScalarType::CHAR;
  }
  else if (isInt(str))
  {
    return ScalarType::INT;
  }
  else if (isFloat(str) || str == "+inff" || str == "-inff" || str == "nanf")
  {
    return ScalarType::FLOAT;
  }
  else if (isDouble(str) || str == "+inf" || str == "-inf" || str == "nan")
  {
    return ScalarType::DOUBLE;
  }
  else
  {
    return ScalarType::INVALID;
  }
}

bool ScalarConverter::isChar(const std::string &str)
{
  if (str.length() == 1 && !std::isdigit(str[0]))
  {
    return true;
  }
  return false;
}

bool ScalarConverter::isInt(const std::string &str)
{
  size_t i = 0;
  if (str[i] == '+' || str[i] == '-')
  {
    i = 1;
  }
  while (i < str.length())
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
    i++;
  }
  return str.back() != '-' && str.back() != '+' && str.length() > 0;
}

bool ScalarConverter::isFloat(const std::string &str)
{
  size_t i = 0;
  bool decimal_seen = false;
  if (str[i] == '+' || str[i] == '-')
  {
    i = 1;
  }
  while (i < str.length())
  {
    if (str[i] == '.')
    {
      if (decimal_seen)
      {
        return false;
      }
      decimal_seen = true;
    }
    else if (!std::isdigit(str[i]))
    {
      if ((str[i] == 'f' || str[i] == 'F') && str[i + 1] == '\0')
      {
        break;
      }
      return false;
    }
    i++;
  }
  return str.back() != '-' && str.back() != '+' && str.back() != '.' &&
         (str.back() == 'f' || str.back() == 'F') && str.length() > 0;
}

bool ScalarConverter::isDouble(const std::string &str)
{
  size_t i = 0;
  bool decimal_seen = false;
  if (str[i] == '+' || str[i] == '-')
  {
    i = 1;
  }
  while (i < str.length())
  {
    if (str[i] == '.')
    {
      if (decimal_seen)
      {
        return false;
      }
      decimal_seen = true;
    }
    else if (!std::isdigit(str[i]))
    {
      return false;
    }
    i++;
  }
  return str.back() != '-' && str.back() != '+' && str.back() != '.' &&
         str.length() > 0;
}