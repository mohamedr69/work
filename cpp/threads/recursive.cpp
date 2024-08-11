#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
/*
A std::recursive_mutex in C++ is a type of mutex that allows the same thread to
lock the mutex multiple times without causing a deadlock. This is useful in
situations where a function that locks a mutex might call another function that
also tries to lock the same mutex. Key Features of std::recursive_mutex

    Recursive Locking:
        The same thread can lock a std::recursive_mutex multiple times.
        For every lock() call, there must be a corresponding unlock() call. The
mutex is only actually unlocked when the last unlock() call is made.

    Thread Ownership:
        Only the thread that owns the mutex (i.e., the one that has successfully
locked it) can unlock it. If a different thread attempts to unlock it, the
behavior is undefined.

    Similar Interface:
        The interface of std::recursive_mutex is similar to std::mutex, with
lock(), try_lock(), and unlock() methods.
*/
std::recursive_mutex rec_mutex;

void func(int count) {
  if (count < 0) {
    return;
  }
  rec_mutex.lock();
  std::cout << "Lock aquired, count " << count << "\n";
  func(count - 1);
  rec_mutex.unlock();
  std::cout << "Lock released, count " << count << "\n";
}

int main() {
  std::thread t1(func, 3);
  t1.join();
  return 0;
}
