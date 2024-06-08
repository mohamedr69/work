#include <iostream>
#include <memory>

std::weak_ptr<int> weak_ptr;
// Cyclic Dependency solution
/*
    class A --> shared pointer --> class B
    class B --> shared pointer --> Class A

*/
void observe() {
  std::cout << "count: " << weak_ptr.use_count() << "\n";
  if (auto shared_ptr = weak_ptr.lock()) {
    std::cout << "Successful: " << *shared_ptr << "\n";
  } else {
    std::cout << "UnSuccessful \n";
  }
}

int main() {
  {
    auto shared_ptr = std::make_shared<int>(8);
    // auto shared_ptr_2 = std::make_shared<int>(10);

    weak_ptr = shared_ptr;
    // weak_ptr = shared_ptr_2;

    observe();
  }
  observe();
}