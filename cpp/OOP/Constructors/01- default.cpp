#include <iostream>
#include <string>
class Human {
 private:
  std::string name;
  int age;

 public:
  Human() {
    std::cout << "default constructor" << '\n';
    name = "no name";
    age = 0;
  }
  /*Human(std::string name, int age) {
    std::cout << "overloaded constructor" << '\n';
    this->name = name;
    this->age = age;
  }*/
  Human(std::string name, int age) : name(name), age(age) {}
  void speakUp() {
    std::cout << this->name << "\n";
    std::cout << this->age << "\n";
  }
};

int main() {
  Human mohamed("mohamed", 24);
  mohamed.speakUp();
}