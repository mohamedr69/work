#include <iostream>
#include <memory>
/*
        does not have ownership
        it does not increase use_count

*/

std::weak_ptr<int> weakPtr;

void observe() {
  std::cout << weakPtr.use_count() << "\n";
  if (weakPtr.expired()) {
    std::cout << "expired"
              << "\n";
  } else {
    auto sharedPtr = weakPtr.lock();
    std::cout << sharedPtr.use_count() << "\n";
    std::cout << *sharedPtr << "\n";
  }
}

int main() {
  {
    auto sharedPtr = std::make_shared<int>(42);
    weakPtr = sharedPtr;
    observe();
  }
  observe();
}