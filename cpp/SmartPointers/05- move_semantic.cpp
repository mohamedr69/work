#include <cstring>
#include <iostream>
class String {
 public:
  String() = default;
  String(const char* string) {
    printf("created\n");
    length = stringLength(string);
    str = new char[length];
    stringCopy(str, string);
  }

  String(const String& other) {
    printf("Copied\n");
    length = other.length;
    str = new char[length];
    stringCopy(str, other.str);
  }

  String(String&& other) {
    printf("moved\n");
    length = other.length;
    str = other.str;
    other.str = nullptr;
  }
  String& operator=(String&& other) {
    printf("moved\n");
    length = other.length;
    str = other.str;
    other.str = nullptr;
    return *this;
  }

  void print() {
    for (int i = 0; i < length; i++) {
      std::cout << str[i];
    }
    std::cout << '\n';
  }

  ~String() { delete str; }

 private:
  char* str;
  uint32_t length;
  uint32_t stringLength(const char* str) {
    uint32_t len = 0;
    while (str[len] != '\0') {
      len++;
    }
    return len;
  }
  void stringCopy(char* destination, const char* source) {
    while (*source != '\0') {
      *destination = *source;
      destination++;
      source++;
    }
    *destination = '\0';
  }
};

class Entity {
 public:
  Entity(const String& name) : data(name) {}

  Entity(String&& name) : data(std::move(name)) {
    std::cout << "move constructor";
  }

  void printName() { data.print(); }

 private:
  String data;
};

int main() {
  String s("MohamedRamadan");
  Entity e(s);

  Entity e2(String("EmbeddedC++"));

  e.printName();

  return 0;
}