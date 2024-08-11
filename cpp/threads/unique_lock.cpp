#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

/*
std::unique_lock is a versatile and powerful locking mechanism in C++ that
provides more flexibility than std::lock_guard. While both std::unique_lock and
std::lock_guard are used for managing mutexes, std::unique_lock offers
additional features such as deferred locking, manual unlocking, and the ability
to move the lock to another std::unique_lock instance. Key Features of
std::unique_lock

    Deferred Locking:
        You can construct a std::unique_lock without immediately locking the
associated mutex. This is useful in scenarios where you need to perform other
operations before acquiring the lock.

    Manual Locking and Unlocking:
        Unlike std::lock_guard, std::unique_lock allows you to lock and unlock
the mutex manually. This provides more control over when the mutex is locked and
unlocked.

    Ability to Move:
        A std::unique_lock can be moved to another std::unique_lock instance,
transferring ownership of the mutex. This is useful in certain design patterns,
such as condition variables or transferring locks between different parts of a
program.

    Timed Locking:
        std::unique_lock supports timed locking operations (try_lock_for and
try_lock_until), allowing you to attempt to acquire the lock for a specified
duration or until a specific time point.

    Conditional Locking:
        You can choose whether to lock the mutex when constructing a
std::unique_lock. This is useful in situations where the decision to lock
depends on runtime conditions.
*/

std::mutex mtx;

void func(bool do_lock) {
  std::unique_lock<std::mutex> lock(mtx);
  if (do_lock) {
    lock.lock();  // manully lock the mutex
    std::cout << "Mutex locked by thread \n";
  } else {
    if (lock.try_lock_for(std::chrono::milliseconds(100))) {
      std::cout << "Mutex locked after waiting by thread \n";
    } else {
      std::cout << "Failed to lock mutex after waiting\n";
    }
  }
  // mutex will automatically unlocked
}

int main() {
  std::thread t1(func, true);
  std::thread t2(func, false);

  t1.join();
  t2.join();

  return 0;
}