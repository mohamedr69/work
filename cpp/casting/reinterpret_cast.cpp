#include <iostream>
// allow any pointer to be converted to any pointer

int main() {
  int a = 70;
  int *p1 = &a;
  char *pc = reinterpret_cast<char *>(p1);  // convert pointer to another

  int *p2 = reinterpret_cast<int *>(a);  // conver int to pointer

  // int b = reinterpret_cast<int>(p2); // loss information
  int b = reinterpret_cast<long>(p2);  // pointer to long
  // one class* to unrelated_class*
}