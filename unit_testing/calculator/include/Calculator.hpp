#include <iostream>

enum STATE { Undefined = 0xffff, Successful };

class calculator {
 public:
  static int calc_add(int, int);
  static int calc_sub(int, int);
  static int calc_mul(int, int);
  static int calc_div(int, int);
};