#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
std::atomic<bool> flag;
std::mutex m;
float temp;

void producer() {
  while (1) {
    /* code */
    m.lock();
    temp += 10;
    flag.store(true);
    m.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void consumer() {
  while (1) {
    /* code */
    m.lock();
    bool ready = flag.load();
    if (ready) {
      auto t = temp;
      std::cout << "Temp" << t << std::endl;
    }

    m.unlock();
  }
}

int main() {
  std::thread prod(producer);
  std::thread cons(consumer);
  prod.join();
  cons.join();
  return 0;
}