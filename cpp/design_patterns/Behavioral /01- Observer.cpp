#include "01- Observer.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

void Subject::addObserver(Observer& observer) {
  Subject::observers.push_back(&observer);
}
void Subject::removeObserver(Observer& Observer) {
  observers.erase(std::remove(observers.begin(), observers.end(), &Observer));
}
void Subject::notifyAllObservers() {
  for (auto* observer : Subject::observers) {
    observer->Update(*this);
  }
}

int Time::getHour() { return Time::hour; }
int Time::getMinute() { return Time::minute; }
int Time::getSecond() { return Time::second; }

void Time::setTime(int hour, int minute, int second) {
  this->hour = hour;
  this->minute = minute;
  this->second = second;
  Subject::notifyAllObservers();
}

Digital::Digital(Time& t) : time(t) { time.addObserver(*this); }

Digital::~Digital() { time.removeObserver(*this); }

void Digital::Draw() {
  std::cout << "Digital: " << Digital::time.getHour() << ":"
            << Digital::time.getMinute() << ":" << Digital::time.getSecond()
            << "\n";
}

void Digital::Update(Subject& s) { Digital::Draw(); }

//--------------------------------------

Analog::Analog(Time& t) : time(t) { time.addObserver(*this); }

Analog::~Analog() { time.removeObserver(*this); }

void Analog::Draw() {
  std::cout << "Analog: " << Analog::time.getHour() << ":"
            << Analog::time.getMinute() << ":" << Analog::time.getSecond()
            << "\n";
}

void Analog::Update(Subject& s) { Analog::Draw(); }
void Subject::Update(Subject& s) {}
int main() {
  Time timer;
  Digital d(timer);
  Analog a(timer);

  timer.setTime(10, 50, 32);
}