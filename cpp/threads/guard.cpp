#include <chrono>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>
std::mutex mutex;
// resource aquisition is initiallization raii
class Guard {
 public:
  Guard(std::mutex &m) : _mutex(m) { _mutex.lock(); }
  ~Guard() { _mutex.unlock(); }

 private:
  std::mutex &_mutex;
};
std::list<int> myList;
void addToList(int max, int interval) {
  std::lock_guard<std::mutex> guard(mutex);
  for (int i = 0; i < max; i++) {
    if ((i % interval) == 0) myList.push_back(i);
  }
}

void printList() {
  std::lock_guard<std::mutex> guard(mutex);
  for (auto it = myList.begin(); it != myList.end(); it++) {
    std::cout << *it << ", ";
  }
}

int main() {
  int max = 100;
  std::thread t1(addToList, max, 1);
  std::thread t2(printList);
  t1.join();
  t2.join();
  return 0;
}
