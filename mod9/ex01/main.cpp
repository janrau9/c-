#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./rpn 1 1 +" << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        int result = rpn.evalRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}