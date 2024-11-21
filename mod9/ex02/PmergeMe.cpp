#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::setVectorSequence(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    try {
      vectorSequence.push_back(std::stoi(argv[i]));
    } catch (const std::invalid_argument& e) {
      throw std::invalid_argument("Invalid input: '" + std::string(argv[i]) +
                                  "' is not a valid integer.");
    } catch (const std::out_of_range& e) {
      throw std::out_of_range("Out of range error: '" + std::string(argv[i]) +
                              "' is too large to be an integer.");
    }
  }
  return vectorSequence;
}

std::vector<int> PmergeMe::generateJacobsthalVector(int n) {
  if (n < 0) throw std::invalid_argument("n must be positive");
  std::vector<int> vectorJacobsthal = {0, 1};
  while (true) {
    int next = vectorJacobsthal[vectorJacobsthal.size() - 1] +
               2 * vectorJacobsthal[vectorJacobsthal.size() - 2];
    if (next > n) break;
    vectorJacobsthal.push_back(next);
  }
  return std::vector<int>(vectorJacobsthal.begin(), vectorJacobsthal.end());
}

std::vector<int> PmergeMe::mergeSortVector(
    const std::vector<int>& vecSequence) {
  if (vecSequence.size() <= 1) return vecSequence;
  size_t middle = vecSequence.size() / 2;
  std::vector<int> left(vecSequence.begin(), vecSequence.begin() + middle);
  std::vector<int> right(vecSequence.begin() + middle, vecSequence.end());
  left = mergeSortVector(left);
  right = mergeSortVector(right);
  std::vector<int> result;
  std::merge(left.begin(), left.end(), right.begin(), right.end(),
             std::back_inserter(result));
  return result;
}

std::vector<int> PmergeMe::sortVector(const std::vector<int>& vecSequence) {
  if (vecSequence.size() <= 1) return vecSequence;
  std::vector<int> a, b;
  for (int i = 0; i < (int)vecSequence.size(); i += 2) {
    if (i + 1 < (int)vecSequence.size()) {
      a.push_back(std::max(vecSequence[i], vecSequence[i + 1]));
      b.push_back(std::min(vecSequence[i], vecSequence[i + 1]));
    } else {
      a.push_back(vecSequence[i]);
    }
  }
  // recursive call to sortVector a
  a = mergeSortVector(a);
  auto jacobsthal = generateJacobsthalVector(b.size());
  for (int i : jacobsthal) {
    if (i < (int)b.size()) {
      if (!a.empty()) {
        auto pos = std::lower_bound(a.begin(), a.end(), b[i]);
        if (pos == a.end() || *pos != b[i]) {
          a.insert(pos, b[i]);
        }
      } else {
        a.push_back(b[i]);
      }
    }
  }
  return a;
}

std::deque<int> PmergeMe::setDequeSequence(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) dequeSequence.push_back(std::stoi(argv[i]));
  return dequeSequence;
}

std::deque<int> PmergeMe::generateJacobsthaldeque(int n) {
  if (n < 0) throw std::invalid_argument("n must be positive");
  std::deque<int> dequeJacobsthal = {0, 1};
  while (true) {
    int next = dequeJacobsthal[dequeJacobsthal.size() - 1] +
               2 * dequeJacobsthal[dequeJacobsthal.size() - 2];
    if (next > n) break;
    dequeJacobsthal.push_back(next);
  }
  return std::deque<int>(dequeJacobsthal.begin(), dequeJacobsthal.end() - 1);
}

std::deque<int> PmergeMe::mergeSortdeque(const std::deque<int>& dequeSequence) {
  if (dequeSequence.size() <= 1) return dequeSequence;
  size_t middle = dequeSequence.size() / 2;
  std::deque<int> left(dequeSequence.begin(), dequeSequence.begin() + middle);
  std::deque<int> right(dequeSequence.begin() + middle, dequeSequence.end());
  left = mergeSortdeque(left);
  right = mergeSortdeque(right);
  std::deque<int> result;
  std::merge(left.begin(), left.end(), right.begin(), right.end(),
             std::back_inserter(result));
  return result;
}

std::deque<int> PmergeMe::sortdeque(const std::deque<int>& dequeSequence) {
  if (dequeSequence.size() <= 1) return dequeSequence;

  std::deque<int> a, b;
  for (int i = 0; i < (int)dequeSequence.size(); i += 2) {
    if (i + 1 < (int)dequeSequence.size()) {
      a.push_back(std::max(dequeSequence[i], dequeSequence[i + 1]));
      b.push_back(std::min(dequeSequence[i], dequeSequence[i + 1]));
    } else {
      a.push_back(dequeSequence[i]);
    }
  }
  // recursive call to sortdeque a
  a = mergeSortdeque(a);
  auto jacobsthal = generateJacobsthaldeque(b.size());
  for (int i : jacobsthal) {
    if (i < (int)b.size()) {
      if (!a.empty()) {
        auto pos = std::lower_bound(a.begin(), a.end(), b[i]);
        if (pos == a.end() || *pos != b[i]) {
          a.insert(pos, b[i]);
        }
      } else {
        a.push_back(b[i]);
      }
    }
  }
  return a;
}