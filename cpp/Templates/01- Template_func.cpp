#include <iostream>

template <typename T>

T max(T n1, T n2) {
  return n1 > n2 ? n1 : n2;
}

int main() {
  // done by compiler
  int n1 = 3;
  int n2 = 5;
  std::cout << "max is " << max(n1, n2) << '\n';

  float n3 = 2.2;
  float n4 = 3.8;
  std::cout << "max is " << max<float>(n3, n4) << '\n';
}