#include <iostream>

template <class T>

class Stack {
 public:
  Stack() {}
  ~Stack() {}
  bool isEmpty() {}
  bool isFull() {}
  int push(const T& item) {}
  int pop(const T& item) {}

 private:
  int size;
  int top;
  T* buffer;
};