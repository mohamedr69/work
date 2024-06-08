#pragma once
#include "IEngine.hpp"

struct v7_Engine : public IEngine {
  void Start() override { std::cout << "V7 Engine start \n"; }
  void Stop() override { std::cout << "V7 Engine Stop \n"; }
};
