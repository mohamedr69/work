#include <iostream>

// used for run time cast

// animal based class
// cat dog --> dervied

// Animal *bp = new cat();
// Animal *bp2 = new dog()

// Dog *pd = dynamic_cast<Dog *>(bp1) NULL
// Dog *pd = dynamic_cast<Dog *>(bp2)

// type cast from base to derived
class animal {
 public:
  virtual void sound() {}  // run time polymorphism

 private:
};
class dog : public animal {
  void sound() override {}
};
class cat : public animal {};

int main() {
  animal* a1 = new cat();
  animal* a2 = new dog();
  dog* d = dynamic_cast<dog*>(a1);   // return 0
  dog* d2 = dynamic_cast<dog*>(a2);  // return the address

  cat* c = dynamic_cast<cat*>(a1);   // return cat address
  cat* c2 = dynamic_cast<cat*>(a2);  // return 0
}