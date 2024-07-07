#include <iostream>

enum state { UNSUCCESSFUL, SUCCESSFUL };

class stack {
 public:
  stack(int size);
  state push(int);
  state pop(int &);
  state isEmpty();
  state isFull();
  state Top(int &);

 private:
  int *buffer;
  int m_top;
  int m_size;
};