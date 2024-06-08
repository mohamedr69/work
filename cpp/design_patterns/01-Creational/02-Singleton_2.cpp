#include <iostream>

class Singleton {
 private:
  Singleton() = default;
  int data;

 public:
  Singleton& getInstance() {
    static Singleton singleton;
    return singleton;
  }
  Singleton(Singleton&) = delete;
  Singleton& operator=(Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;
};

int main() {}