#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setExchangeRate(std::string data) {
  std::ifstream file(data);
  if (!file.is_open()) {
    throw std::invalid_argument("Invalid file");
  }
  std::string dateAndValue, date;
  float rate;
  std::getline(file, dateAndValue);
  while (std::getline(file, dateAndValue)) {
    std::istringstream ss(dateAndValue);
    std::getline(ss, date, ',');
    if (date.empty()) {
      throw std::invalid_argument("Data.csv: Invalid syntax in file" + date);
    }
    if (isValidDate(date) == false) {
      throw std::invalid_argument("Data.csv: Invalid date in file" + date);
    }
    ss >> rate;
    if (ss.fail()) {
      throw std::invalid_argument("Data.csv: Invalid rate in file" + date);
    }
    _exchangeRate[date] = rate;
  }
  file.close();
}

void BitcoinExchange::convertInput(char* input) {
  if (input == nullptr) {
    throw std::invalid_argument("Invalid input");
  }
  std::ifstream file(input);
  if (!file.is_open()) {
    throw std::invalid_argument("Invalid file");
  }
  std::string dateAndValue, date;
  float amount;
  std::getline(file, dateAndValue);
  while (std::getline(file, dateAndValue)) {
    std::istringstream ss(dateAndValue);
    std::getline(ss, date, '|');
    if (date.empty()) {
      std::cerr << "Error: Invalid syntax in file" << date << std::endl;
      continue;
    }
    if (isValidDate(date) == false) {
      std::cerr << "Error: bad input => " << date << std::endl;
        continue;
    }
    ss >> amount;
    if (ss.fail()) {
      std::cerr << "Error: bad input => " << date << std::endl;
    } else if (amount < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
    } else if (amount > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
    } else {
      convertToBitcoin(date, amount);
    }
  }
  file.close();
}

float BitcoinExchange::getExchangeRate(std::string date, float amount) {
  auto it = _exchangeRate.lower_bound(date);
  if (it->first != date)
    if (it-- == _exchangeRate.begin()) return (0);
  return (it->second * amount);
}

void BitcoinExchange::convertToBitcoin(std::string date, float amount) {
  std::cout << date << " => " << amount << " = "
            << getExchangeRate(date, amount) << std::endl;
}

void BitcoinExchange::printExchangeRate() {
  for (auto it = _exchangeRate.begin(); it != _exchangeRate.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
}

bool BitcoinExchange::isValidDate(std::string& date) {
  std::tm tm = {};
  std::istringstream ss(date);
  ss >> std::get_time(&tm, "%Y-%m-%d");
  if (ss.fail()) {
    return false;
  }
  return true;
}