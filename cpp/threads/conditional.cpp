#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::mutex mutex;
std::queue<int> my_queue;
std::condition_variable data_cond;

void consume_data(int data) { std::cout << data << std::endl; }

int produce_data() {
  static int var = 0;
  var++;
  return var;
}

void producer() {
  while (1) {
    const int data = produce_data();
    std::lock_guard<std::mutex> prod_lock(mutex);
    my_queue.push(data);
    data_cond.notify_all();
  }
}
void consumer() {
  while (1) {
    std::unique_lock<std::mutex> uni_lock(mutex);
    data_cond.wait(uni_lock, [] { return !my_queue.empty(); });

    int data = my_queue.front();
    my_queue.pop();
    uni_lock.unlock();
    consume_data(data);
  }
}
int main() {
  std::thread consumer_thread(consumer);
  std::thread producer_thread(producer);
  consumer_thread.join();
  producer_thread.join();
  return 0;
}
