#include <iostream>

// change from const pointer to not

int func(int *ptr) {}
int main() {
  const int val = 5;
  const int *ptr = &val;

  int *ptr1 = const_cast<int *>(ptr);
  func(ptr1);
}