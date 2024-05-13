#include <iostream>

class Array {
 private:
  int size;
  int* ptr;

 public:
  Array() {
    ptr = nullptr;
    size = 0;
  }
  Array(int s) {
    if (s > 0) {
      size = s;
      ptr = new int[size];
      for (int i = 0; i < size; ++i) {
        ptr[i] = i;
      }
    } else {
      ptr = nullptr;
      size = 0;
    }
  }
  Array(const Array& copy) {
    ptr = new int[copy.size];
    size = copy.size;
    for (int i = 0; i < size; ++i) {
      ptr[i] = copy.ptr[i];
    }
  }
  Array& operator=(const Array& copy) {
    if (this != &copy) {  // prevent self assignment
      if (ptr != nullptr) {
        delete[] ptr;
      }
      ptr = new int[copy.size];
      size = copy.size;
      for (int i = 0; i < size; ++i) {
        ptr[i] = copy.ptr[i];
      }
    }
    return *this;
  }

  ~Array() { delete[] ptr; }

  void printArrayContent() {
    for (int i = 0; i < size; i++) {
      std::cout << ptr[i] << " ";
    }
    std::cout << "\n";
  }
  void changeValueAtIndex(int value, int index) {
    if (index < size) {
      ptr[index] = value;
    } else {
      throw "invalid index";
    }
  }
};

int main() {
  Array a1(5);
  Array a2(a1);

  a2.printArrayContent();
  a1.changeValueAtIndex(100, 2);  // a2 will not be affected too
  a2.printArrayContent();
}