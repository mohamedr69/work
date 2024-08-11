#include <chrono>
#include <future>
#include <iostream>
#include <thread>

void producer(std::promise<int> &promise) { promise.set_value(0); }

void consumer(std::promise<int> &promise) {
  std::future<int> future = promise.get_future();
  auto value = future.get();
  std::cout << "value " << value << std::endl;
}

int main() {
  std::promise<int> promise;
  std::thread consumer_thread(consumer, std::ref(promise));
  std::thread producer_thread(producer, std::ref(promise));

  consumer_thread.join();
  producer_thread.join();
  return 0;
}