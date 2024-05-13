#include <iostream>
template <class T>

void swap(T& first, T& second) {
  T temp = first;
  first = second;
  second = temp;
}
template <class T>
bool max(T first, T second) {
  bool temp = first > second;
  return temp;
}

class Person {
 public:
  Person() {
    this->name = "no name";
    this->age = 0;
  }
  Person(std::string name, int age) : name(name), age(age) {}

  Person(const Person& p) {
    this->name = p.name;
    this->age = p.age;
  }

  Person& operator=(const Person& p) {
    this->name = p.name;
    this->age = p.age;
    return *this;
  }

  bool operator>(const Person& p) { return this->age > p.age; }

 private:
  std::string name;
  int age;
};

int main() {}