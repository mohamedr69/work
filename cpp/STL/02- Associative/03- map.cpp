#include <iostream>
#include <map>
#include <unordered_map>
template <class T1, class T2>
class Pair {
 private:
  T1 first;
  T2 second;
  Pair() {}
  Pair(T1 first, T2 second) : first(first), second(second) {}
  // Factory DP
 public:
  static Pair Make_Pair(T1 first, T2 second) { return Pair(first, second); }
};

int main() {
  std::map<int, int> quiz;
  quiz.insert(std::pair<int, int>(1, 15));
  quiz.insert(std::pair<int, int>(2, 20));
  quiz.insert(std::pair<int, int>(3, 25));
  quiz.insert(std::pair<int, int>(4, 30));
  quiz.insert(std::pair<int, int>(5, 35));
  quiz.insert(std::pair<int, int>(6, 40));

  for (auto& pair : quiz) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }
  std::cout << "---------------------"
            << "\n";
  for (auto& [key, value] : quiz) {
    std::cout << key << ": " << value << "\n";
  }
  std::cout << "---------------------"
            << "\n";
  quiz.erase(6);
  for (auto& [key, value] : quiz) {
    std::cout << key << ": " << value << "\n";
  }
}