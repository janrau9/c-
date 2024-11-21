#include <chrono>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "usage: ./pmergeMe [sequence]" << std::endl;
    return 1;
  }
  PmergeMe pmergeMe;
  try {
    std::vector<int> vec = pmergeMe.setVectorSequence(argc, argv);
    std::deque<int> deq = pmergeMe.setDequeSequence(argc, argv);
    pmergeMe.printSequence("Before:", vec);
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVec = pmergeMe.sortVector(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationVector =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();
    pmergeMe.printSequence("After vector:", sortedVec);

    start = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeq = pmergeMe.sortdeque(deq);
    end = std::chrono::high_resolution_clock::now();
    auto durationDeque =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();
    pmergeMe.printSequence("After deque:", sortedDeq);
    std::cout << "Time to process range of " << vec.size() << " elements with std::vector: " << durationVector
              << " us" << std::endl;
    std::cout << "Time to process range of " << deq.size() << " elements with std::deque: " << durationDeque
              << " us" << std::endl;

    return 0;

  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
