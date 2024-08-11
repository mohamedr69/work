#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

/*
std::lock_guard is a C++ utility that provides a convenient way to manage the
locking and unlocking of a mutex within a scoped block. It is part of the C++
Standard Library and is designed to ensure that a mutex is properly unlocked
even if an exception is thrown or if the function exits prematurely. Key
Features of std::lock_guard

    RAII (Resource Acquisition Is Initialization):
        std::lock_guard automatically locks the mutex when it is created and
unlocks it when it goes out of scope (i.e., when the block in which it was
declared ends).

    No Explicit Unlocking:
        You do not need to manually unlock the mutex. std::lock_guard takes care
of unlocking the mutex when it is destroyed, which helps prevent bugs related to
forgetting to unlock a mutex.

    Simple Interface:
        It only requires a mutex to be passed to its constructor. There are no
additional parameters or options, making it a straightforward tool for basic
mutex management.
*/

std::mutex mutex;

void print_message(const std::string &msg) {
  std::lock_guard<std::mutex> lock(mutex);
  std::cout << msg << std::endl;
  // automatically unlock
}
int main() {
  std::thread t1(print_message, "Hello from t1");
  std::thread t2(print_message, "Hello from t2");
  t1.join();
  t2.join();
  return 0;
}
