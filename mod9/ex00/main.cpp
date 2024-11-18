#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./bitcoin_exchange [file]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    try {
        exchange.setExchangeRate("data.csv");
        exchange.convertInput(argv[1]);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}