#include <iostream>

// compile time cast

int main() {
  float f = 10.5;
  int i;
  // i = f; implicit casing
  i = static_cast<int>(f);

  char c;
  int *p1 = (int *)(&c);
  *p1 = 3;  // pass at compile time, fail at run time
  // int *p2 = static_cast<int *>(&c); compile time error
  int j = 10;
  void *v = static_cast<void *>(&j);
  int *p = static_cast<int *>(v);
}