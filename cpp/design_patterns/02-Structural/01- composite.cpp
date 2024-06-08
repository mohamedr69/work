#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
// Abstract class
class Graphic {
 public:
  virtual void draw() = 0;
  virtual void remove(Graphic *);
  virtual void add(Graphic *);
  virtual void getChild(int) {}

  virtual ~Graphic() {}
};

class Line : public Graphic {
 public:
  void draw() { std::cout << "Draw Line\n"; }
};

class Rectangle : public Graphic {
 public:
  void draw() { std::cout << "Draw Rectangle\n"; }
};

class Text : public Graphic {
 public:
  void draw() { std::cout << "Draw Text\n"; }
};

class Picture : public Graphic {
 public:
  void draw() {
    for (auto &graphic : gList) {
      graphic->draw();
    }
  }
  void remove(Graphic *g) {
    gList.erase(std::remove(gList.begin(), gList.end(), g), gList.end());
  }
  void add(Graphic *g) { gList.push_back(g); }

 private:
  std::vector<Graphic *> gList;
};

int main() {
  Line line;
  Rectangle rect;
  Text text;

  Picture picture;
  picture.add(&line);
  picture.add(&rect);
  picture.add(&text);

  picture.draw();
}