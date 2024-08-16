#include <chrono>
#include <future>
#include <iostream>
#include <thread>
int getTemp() { return 25; }
void dis(std::future<int> future) {
  while (1) {
    auto status = future.wait_for(std::chrono::milliseconds(100));

    if (status == std::future_status::ready) {
      auto value = future.get();
      std::cout << value << std::endl;
    }
  }
}
int main() {
  std::future<int> future = std::async([]() { return getTemp(); });

  std::thread display(dis, std::move(future));

  return 0;
}