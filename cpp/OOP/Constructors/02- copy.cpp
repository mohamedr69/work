#include <iostream>

class Foo {
 private:
  int* x;

 public:
  Foo() {
    x = new int;
    *x = 0;
  }
  Foo(const Foo& p) {  // copy constructor
    x = new int;
    *x = p.get();
  }
  // overloading assignment operator

  void operator=(const Foo& g) {
    delete x;
    x = new int;
    *x = g.get();
  }
  void set(int i) { *x = i; }
  int get() const { return *x; }
  ~Foo() { delete x; }
};

int main() {
  Foo f;

  f.set(88);
  Foo f2 = f;
  f.set(80);  // both objects pointing to the same variable
  std::cout << f2.get() << "\n";

  Foo f1, g;
  f1.set(10);
  g = f1;
  std::cout << g.get() << "\n";
}