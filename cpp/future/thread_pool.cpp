#include <future>
#include <iostream>
#include <mutex>
#include <thread>

int get_acc(std::promise<int>& promise) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  promise.set_value(22);
}

void Acceleration_thread(std::future<int>& future) {
  while (1) {
    auto value = future.get();
    std::cout << "Value " << value << "\n";
  }
}
void Acc_thread() {
  while (1) {
    std::future<int> future = std::async([]() { return 22; });

    // connect();

    auto value = future.get();

    // send(value);
    // close();
  }
}
int main() {
  std::promise<int> promise;
  std::future<int> future = promise.get_future();

  std::thread acc(Acc_thread, std::move(promise));

  acc.join();
  return 0;
}