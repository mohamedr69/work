#include <iostream>
#include <mutex>
#include <thread>
int num = 0;
std::mutex mutex;

void increment() {
  mutex.lock();
  for (int i = 0; i < 100000; i++) {
    num++;
  }
  mutex.unlock();
}

void t1() { increment(); }
void t2() { increment(); }

int main() {
  std::thread thread1(t1);
  std::thread thread2(t2);

  thread1.join();
  thread2.join();

  return 0;
}