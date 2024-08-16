#include <future>
#include <iostream>
#include <mutex>
#include <thread>
void consumer(std::future<int>& future) {
  std::cout << "waiting .... \n";
  int result = future.get();
  std::cout << "Value: " << result << "\n";
}

void producer(std::promise<int>& promise) {
  std::this_thread::sleep_for(std::chrono::seconds(2));
  int value = 22;
  promise.set_value(value);
}

int main() {
  std::promise<int> promise;
  std::future<int> future = promise.get_future();

  std::thread prod(producer, std::move(promise));
  std::thread cons(consumer, std::move(future));

  prod.join();
  cons.join();

  return 0;
}
