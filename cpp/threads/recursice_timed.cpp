#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

/*
std::recursive_timed_mutex in C++ is a variant of std::recursive_mutex that also
supports timed locking operations. This means that a thread can attempt to lock
the mutex for a certain amount of time or until a specific point in time, just
like with std::timed_mutex, but it also allows the same thread to lock the mutex
multiple times (recursive locking). Key Features of std::recursive_timed_mutex

    Recursive Locking:
        Similar to std::recursive_mutex, the same thread can lock the
std::recursive_timed_mutex multiple times. Each lock must be matched by a
corresponding unlock.

    Timed Locking:
        try_lock_for(duration): Attempts to lock the mutex, waiting for up to
the specified duration. If the mutex is successfully locked within this time, it
returns true; otherwise, it returns false. try_lock_until(time_point): Attempts
to lock the mutex until the specified time point is reached. If the mutex is
successfully locked before the time point, it returns true; otherwise, it
returns false.

    Thread Ownership:
        Like other mutexes, std::recursive_timed_mutex only allows the thread
that currently owns the lock to unlock it.
*/

std::recursive_timed_mutex rec_timed_mutex;

void func(int count) {
  if (count < 0) {
    return;
  }

  if (rec_timed_mutex.try_lock_for(std::chrono::seconds(1))) {
    std::cout << "Lock acquired " << count << "\n";

    func(count - 1);

    rec_timed_mutex.unlock();

    std::cout << "Lock released " << count << "\n";
  } else {
    std::cout << "faild to aquire within 1 sec"
              << "\n";
  }
}

int main() {
  std::thread t1(func, 3);
  t1.join();
  return 0;
}