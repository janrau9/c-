#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <limits.h>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        std::vector<int> mergeSortVector(const std::vector<int>& vecSequence);
        std::deque<int> mergeSortdeque(const std::deque<int>& dequeSequence);
        std::vector<int> sortVector(const std::vector<int>& vecSequence);
        std::deque<int> sortdeque(const std::deque<int>& dequeSequence);
        std::vector<int> setVectorSequence(int argc, char **argv);
        std::deque<int> setDequeSequence(int argc, char **argv);
        std::vector<int> generateJacobsthalVector(int n);
        std::deque<int> generateJacobsthaldeque(int n);
        template <typename T>
        void printSequence(std::string str, const T& sequence) {
            std::cout << str << " ";
            for (int i : sequence) std::cout << i << " ";
            std::cout << std::endl;
        }
    private:
        std::vector<int> vectorSequence;
        std::deque<int> dequeSequence;
};