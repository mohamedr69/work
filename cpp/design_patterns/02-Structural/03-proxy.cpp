#include <iostream>

class Protocol {
 public:
  virtual void defineProtocol() = 0;
  virtual void request() = 0;
  virtual ~Protocol() {}
};

class VehicleToVehichle : public Protocol {
 public:
  virtual void defineProtocol() {}
  virtual void request() { std::cout << "VehicleToVehichle\n"; }
};

class VehicleToInfrastructure : public Protocol {
 public:
  virtual void defineProtocol() {}
  virtual void request() { std::cout << "VehicleToInfrastructure\n"; }
};

class VehicleToX : public Protocol {
 public:
  virtual void defineProtocol() {}
  virtual void request() { std::cout << "VehicleToX\n"; }
};

class Proxy : Protocol {
 private:
  Protocol* protocol;

 public:
  Proxy(Protocol* p) : protocol(p) {}
  virtual void defineProtocol() { protocol->defineProtocol(); }
  virtual void request() { protocol->request(); }
};

int main() {
  Proxy p1(new VehicleToVehichle);
  Proxy p2(new VehicleToInfrastructure);
  Proxy p3(new VehicleToX);

  p1.request();
  p2.request();
  p3.request();
}