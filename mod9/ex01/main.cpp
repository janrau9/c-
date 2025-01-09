#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./rpn [RPN sequence]" << std::endl;
        return 1;
    }
    RPN rpn;
    try {
        int result = rpn.evalRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}