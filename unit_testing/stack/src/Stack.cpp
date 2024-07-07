#include "Stack.hpp"

stack::stack(int size) : m_size(size) {
  buffer = new int[size];
  m_top = 0;
}
state stack::push(int value) {
  if (isFull()) {
    return UNSUCCESSFUL;
  }
  buffer[m_top++] = value;
  return SUCCESSFUL;
}
state stack::pop(int &value) {
  if (isEmpty()) {
    return UNSUCCESSFUL;
  }
  value = buffer[m_top--];
  return SUCCESSFUL;
}
state stack::isEmpty() {
  if (m_top == 0) {
    return SUCCESSFUL;
  }
  return UNSUCCESSFUL;
}
state stack::isFull() {
  if (m_top == m_size) {
    return SUCCESSFUL;
  }
  return UNSUCCESSFUL;
}
state stack::Top(int &value) {
  if (isEmpty()) {
    return UNSUCCESSFUL;
  }
  value = buffer[m_top];
  return SUCCESSFUL;
}
