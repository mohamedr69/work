#include <iostream>

namespace Container {
struct Data {
  std::string name;
  int address;
};
struct Node {
  Data data;
  Node *next;

  void Traverse(Node *head, void *(funcCallBack)(Container::Node *)) {}

  void print(Container::Node *node) {
    std::cout << node->data.name << " " << node->data.address << "\n";
  };
  void Searching(Container::Node *Head, std::string key, std::string &result) {}

  Container::Node *InsertAtFront(Container::Node *Head, Container::Data data) {}
}  // namespace Container