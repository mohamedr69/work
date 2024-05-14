#include <iostream>

template <typename T>
class templateArray {
 public:
  T array[10];

  void fill(T value) {
    for (int i = 0; i < 10; i++) {
      array[i] = value;
    }
  }
  T& at(int index) { return array[index]; }
};

int main() {
  templateArray<int> t;
  t.fill(0);
}