#include <chrono>
#include <iostream>
#include <thread>
/*
    Types of threads
    1- Continous
    2- Periodic
    3- Sparodic
*/

/*
    Continous --> allaways running
    Peridic --> comes every time
    Sparodic --> based on resource
*/
void LCD_Screen_temp(std::string message, int temp) {
  while (1) {
    std::cout << message << ": " << temp << "\n";
    // sleep

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void LCD_Screen_humidy(std::string message, int humidty) {
  while (1) {
    std::cout << message << ": " << humidty << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

int main() {
  std::string display_temp = "Temp";
  std::string display_humidity = "humidity";
  int temp = 43;
  int humidity = 10;
  std::thread t1(LCD_Screen_temp, display_temp, temp);
  std::thread t2(LCD_Screen_humidy, display_humidity, humidity);
  t1.join();
  t2.join();
  return 0;
}
