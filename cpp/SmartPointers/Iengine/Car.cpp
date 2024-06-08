#include "Car.hpp"

#include "v7Engine.hpp"
#include "v8Engine.hpp"

Car::Car(std::unique_ptr<IEngine>&& engine) : m_engine(std::move(engine)) {}

void Car::Drive() { m_engine->Start(); }

void Car::StopCar() { m_engine->Stop(); }

int main() {
  auto eng_v7 = std::make_unique<v7_Engine>();
  Car BMW(std::move(eng_v7));
  BMW.Drive();
  auto eng_v8 = std::make_unique<v8_Engine>();
  Car Toyota(std::move(eng_v8));
  Toyota.Drive();
  Toyota.StopCar();
}