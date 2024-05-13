
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
  Array(Array&& move) {
    ptr = move.ptr;
    size = move.size;
    move.ptr = nullptr;
  }

  Array& operator=(Array&& move) {
    if (this != &move) {  // prevent self assignment

      delete[] ptr;
      ptr = move.ptr;
      size = move.size;
      move.ptr = nullptr;
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

Array generate() {
  Array obj(1000);
  return obj;
}
int main() {
  int lvalue = 5;
  int& lvalueref = lvalue;
  int&& rvalueref = 5;  // c++11 rvalue ref

  Array obj1 = generate();
  Array obj2 = std::move(obj1);
}