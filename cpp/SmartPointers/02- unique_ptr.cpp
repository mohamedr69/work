#include <iostream>
#include <memory>
#include <string>
/*
    the managing unique_ptr object is destroued
    the managing unique_ptr object is assigned to another pointer
    the managing unique_ptr reset is called
*/

/*
Several unique pointers cant share ownership of a dma
to transfer ownership std::move()
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

void useUniquePtr(std::unique_ptr<Company> ptr) {
  std::cout << "\n"
            << "use UNique Ptr function "
            << "\n";

  ptr->printName();
}
void legacyFunction(Company* ptr) {
  std::cout << "\n"
            << "legacy function "
            << "\n";

  ptr->printName();
}
int main() {
  std::unique_ptr<Company> myUnique(new Company("my company"));
  // c++14
  // std::unique_ptr<Company> myUnique = make_unique<Company>("new Company");

  legacyFunction(myUnique.get());
  useUniquePtr(std::move(myUnique));
}