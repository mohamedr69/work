#include <iostream>
#include <memory>

#include "IEngine.hpp"
struct Car {
  Car(std::unique_ptr<IEngine>&& engine);
  void Drive();
  void StopCar();

 private:
  std::unique_ptr<IEngine> m_engine;
};