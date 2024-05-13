#include <iostream>
#include <memory>
#include <string>
/*
    1- shared ownership

    last remaining shared will be destroyed
    last remining shred ptr is assigned to another
    last remining shared ptr is reset

    use_cout --> no of bjects
    use_count == 0 --> destroyed

*/

class Company {
 private:
  std::string name;
  int value;

 public:
  Company(std::string name) {
    this->name = name;
    std::cout << "constructor of class " << this->name << '\n';
  }
  ~Company() { std::cout << "destructor of class " << this->name << '\n'; }
  void printName() { std::cout << "The company name is" << name << "\n"; }
};

class customer {
 private:
  std::string name;
  std::shared_ptr<Company> SharedPtr;

 public:
  customer(std::string name) {
    this->name = name;
    this->SharedPtr = nullptr;
  }
  ~customer() = default;
  void setCustomerPtr(std::shared_ptr<Company> ptr) { this->SharedPtr = ptr; }
  void printSharedPtrData() {
    std::cout << "\n"
              << this->name << "/n" << SharedPtr.get() << "\n"
              << SharedPtr.use_count() << "\n";
  }
  void useThePtr() { this->SharedPtr->printName(); }
};

int main() {
  std::shared_ptr<Company> ptr = std::make_shared<Company>("my company");
  std::cout << "\n" << ptr.get() << "\n" << ptr.use_count() << "\n";
  customer bmw("bmw");
  bmw.setCustomerPtr(ptr);
  bmw.printSharedPtrData();

  customer ford("ford");
  ford.setCustomerPtr(ptr);
  ford.printSharedPtrData();

  ptr.reset();

  bmw.printSharedPtrData();
  ford.printSharedPtrData();
}
