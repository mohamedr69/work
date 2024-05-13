#include <iostream>

/*Singleton --> create only one instance from object*/

/*Advantages --> save memory, compatibility be
tween developers*/

/*Creation --> we need to have static memver of class, private constructor and
 * static factory methods */

class Singleton {
 protected:
  Singleton() = default;

 public:
  int data;
  static Singleton& get_instance() {
    static Singleton instance;
    return instance;
  }
  Singleton(const Singleton&) = delete;  // copy constructor
  Singleton(Singleton&&) = delete;       // move constructor
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;
};

int main() {
  // Singleton error; private constructor

  Singleton& singleton = Singleton::get_instance();
  singleton.data = 20;

  std::cout << "Sigleton.data -->" << singleton.data << "\n";

  Singleton& singleton2 = Singleton::get_instance();

  std::cout << "Sigleton2.data -->" << singleton2.data << "\n";

  Singleton::get_instance().data = 50;

  std::cout << "Sigleton3.data -->" << Singleton::get_instance().data << "\n";
  /*Copy constructor */
  // Singleton singletonN = singleton;

  // singletonN.data = 100;
  singleton.data = 50;

  std::cout << "Singleton1.data --> " << singleton.data << "\n";
  // std::cout << "SingletonN.data --> " << singletonN.data << "\n";

  return 0;
}