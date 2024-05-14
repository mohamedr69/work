#include <iostream>

template <class T>

class Stack {
 public:
  Stack(int s = 10) {
    if (s < 1 || s > 1000) {
      this->size = 10;
    } else {
      this->size = s;
    }
    top = -1;
    buffer = new T[size];
  }
  ~Stack() { delete[] buffer; }
  bool isEmpty() { return top == -1; }
  bool isFull() { return top == size - 1; }
  void push(const T& item) {
    if (isFull()) {
      throw "No space";
    } else {
      buffer[++top] = item;
    }
  }
  const T& pop() {
    if (isEmpty()) {
      throw "stack is Empty";
    }
    return buffer[top--];
  }

  const T& Top() {
    if (isEmpty()) {
      throw "stack is Empty";
    }
    return buffer[top];
  }

 private:
  int size;
  int top;
  T* buffer;
};

int main() {
  Stack<int> s1(5);
  Stack<float> s2(5);

  s1.push(1);
  s1.push(2);
  s1.push(3);
  std::cout << s1.Top() << "\n";
  std::cout << s2.pop() << "'n";
}