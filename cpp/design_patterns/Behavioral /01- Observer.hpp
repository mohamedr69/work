#pragma once
#include <iostream>
#include <vector>
class Subject;
class Observer;
class Observer {
 public:
  virtual void Update(Subject&) = 0;
  virtual ~Observer() = default;
};

class Subject : public Observer {
 public:
  void addObserver(Observer& observer);
  void removeObserver(Observer& observer);
  void notifyAllObservers();
  void Update(Subject&);

 private:
  std::vector<Observer*> observers;
};
class Time : public Subject {
 public:
  int getHour();
  int getMinute();
  int getSecond();
  void setTime(int, int, int);

 private:
  int hour;
  int minute;
  int second;
};

class Digital : public Observer {
 public:
  Digital(Time&);
  ~Digital();
  void Update(Subject&);
  void Draw();

 private:
  Time& time;
};

class Analog : public Observer {
 public:
  Analog(Time& t);
  ~Analog();
  void Update(Subject&);
  void Draw();

 private:
  Time& time;
};