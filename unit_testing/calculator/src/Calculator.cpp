#include "Calculator.hpp"

int calculator::calc_add(int a, int b) { return a + b; }
int calculator::calc_sub(int a, int b) { return a - b; }
int calculator::calc_mul(int a, int b) { return a * b; }
int calculator::calc_div(int a, int b) {
  if (b == 0) {
    return Undefined;
  }
  return a / b;
}
