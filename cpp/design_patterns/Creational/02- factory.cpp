#include <iostream>
#include <vector>
class Shape {
 public:
  virtual std::string getName() = 0;
  virtual ~Shape() = default;
};

class Triangle : public Shape {
 public:
  std::string getName() { return "Triangle"; }
};

class Square : public Shape {
 public:
  std::string getName() { return "Square"; }
};

class Circle : public Shape {
 public:
  std::string getName() { return "Circle"; }
};

enum Type { TRIANGLE, SQUARE, CIRCLE };

// responsible for creating, returning shape objects
class Factory {
 public:
  Shape* create(Type t) {  // factory method
    switch (t) {
      case TRIANGLE:
        return new Triangle();
      case SQUARE:
        return new Square();
      case CIRCLE:
        return new Circle();
      default:
        return new Circle();
    }
  }
};
int main() {
  std::vector<Shape*> shapes;
  // factory responsible for creating Shape objects
  Factory f;
  // creating three different object
  shapes.push_back(f.create(TRIANGLE));
  shapes.push_back(f.create(SQUARE));
  shapes.push_back(f.create(CIRCLE));

  // Iterate over shapes and get name
  for (Shape*& s : shapes) {
    std::cout << s->getName() << "\n";
  }
  // clean up
  for (Shape*& s : shapes) {
    delete s;
  }

  shapes.clear();
  return 0;
}