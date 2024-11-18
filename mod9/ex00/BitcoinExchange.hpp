#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange {
    private:
        std::map<std::string, double> _exchangeRate;
        bool isValidDate(std::string& date);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void setExchangeRate(std::string data);
        void convertInput(char *input);
        float getExchangeRate(std::string date, float amount);
        void convertToBitcoin(std::string date, float amount);
        void printExchangeRate();
};