#include <iostream>
#include <mutex>
/*

    std::lock_guard<>
    std::unique_quard<>
    std::shared_lock<>

*/

std::mutex mutex;

std::timed_mutex t_mutex;
void f() { std::lock_guard<std::mutex> guard(mutex); }

std::unique_lock<std::mutex> g() {
  std::unique_lock<std::mutex> guard(mutex);
  return std::move(guard);
}

void g2() {
  std::unique_lock<std::mutex> guard(mutex);
  guard.unlock();
}

std::shared_time_mutex m;

void reader() { std::shared_lock<std::shared_time_mutex> guard(m); }
void writer() { std::lock_guard<std::shared_time_mutex> guard(m); }