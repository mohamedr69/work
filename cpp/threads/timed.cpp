#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::timed_mutex t_mutex;

void func(int thread_ID) {
  if (t_mutex.try_lock_for(std::chrono::seconds(1))) {
    std::cout << "Thread " << thread_ID << "Acquied the lock \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    t_mutex.unlock();
    std::cout << "Thread " << thread_ID << "released \n";
  } else {
    std::cout << "Thread " << thread_ID << " failed to aquire\n";
  }
}

int main() {
  std::thread t1(func, 1);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::thread t2(func, 2);

  t1.join();
  t2.join();
  return 0;
}