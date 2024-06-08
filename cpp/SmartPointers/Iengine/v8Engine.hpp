#pragma once
#include "IEngine.hpp"

struct v8_Engine : public IEngine {
  void Start() override { std::cout << "V8 Engine start \n"; }
  void Stop() override { std::cout << "V8 Engine Stop \n"; }
};
