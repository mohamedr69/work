#include <chrono>
#include <iostream>
#include <thread>

void thread_func() {
  while (1) {
    auto no_threads = std::thread::hardware_concurrency();
    std::cout << "no of threads " << no_threads << "\n";
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
  }
}

int main() {
  std::thread thread1(thread_func);

  std::thread thread2(std::move(thread1));

  thread2.join();
  return 0;
}