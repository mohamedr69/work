#include <iostream>
#include <mutex>
#include <thread>
class Singleton {
 public:
  static Singleton* getInstance() {
    if (!instance) {
      instance = new Singleton();
      std::cout << "new Instance\n";
      return instance;
    } else {
      std::cout << "previous Instance\n";
      return instance;
    }
  }
  void send(std::string data) {
    //_mutex.lock();
    std::lock_guard<std::mutex> guard(_mutex);
    std::cout << data << "\n";
    //_mutex.unlock();
  }

  Singleton(Singleton& s) = delete;
  Singleton(Singleton&& s) = delete;

  Singleton operator=(Singleton& m) = delete;
  Singleton operator=(Singleton&& m) = delete;

 private:
  Singleton() {}
  static Singleton* instance;
  std::mutex _mutex;
};

void firstConsumer() {
  Singleton* ble = Singleton::getInstance();
  while (1) {
    /* code */
    ble->send("Temp is 43");
  }
}

void secondConsumer() {
  Singleton* ble = Singleton::getInstance();
  while (1) {
    /* code */
    ble->send("Temp is 50");
  }
}

int main() {
  std::thread t1(firstConsumer);
  std::thread t2(secondConsumer);

  t1.join();
  t2.join();
  return 0;
}
