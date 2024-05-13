#include <iostream>

template <class T>
class smartPtr {
  T* ptr;

 public:
  smartPtr(T* p = nullptr) : ptr(p) {}
  ~smartPtr() { delete ptr; }
  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }
};
/*
    Automatic clean up
    Automatic initialization --> avoid Wild pointer
    avoid Dangling pointer
    Exception safety
*/