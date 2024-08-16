#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

void display(std::future<int>& future) {
  while (1) {
    auto status = future.wait_for(std::chrono::milliseconds(100));

    if (status == std::future_status::ready) {
      auto var = future.get();
      std::cout << "Value: " << var << std::endl;
    }
  }
}

int main() {
  std::future<int> future = std::async([]() { return 10; });

  std::thread dis(display, std::move(future));

  return 0;
}