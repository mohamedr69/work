#include <iostream>
#include <memory>
// Node

struct Node {
  int data;
  // Node *next;
  std::shared_ptr<Node> next;

  Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
 private:
  std::shared_ptr<Node> head;

 public:
  SinglyLinkedList() { head = nullptr; }
  void insertAtHead(int value) {  // O(1)
    /*Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;*/
    std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
    newNode->next = head;
    head = newNode;
  }
  void insertAtEnd(int value) {
    /*Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    Node *current = head;
    if (head == nullptr) {
      head = newNode;
    } else {
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }*/
    std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
      head = newNode;
    } else {
      std::shared_ptr<Node> current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
  }
  void deleteNode(int value) {
    if (head == nullptr) {
      std::cout << "Linked list is Empty!!!\n";
      return;
    }
    // Node *current = head;
    std::shared_ptr<Node> current = head;
    // Node *prev = nullptr;
    std::shared_ptr<Node> prev = nullptr;
    while (current != nullptr && current->data != value) {
      prev = current;
      current = current->next;
    }
    if (current == nullptr) {
      std::cout << "Value not found!!!\n";
      return;
    }

    prev->next = current->next;
    // delete current;
  }
  void display() {
    // Node *current = head;
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
      /* code */
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "NULL\n";
  }
  ~SinglyLinkedList() {
    /*Node *current = head;
    while (current->next != nullptr) {
      Node *temp = current->next;
      delete current;
      current = temp;
    }
  }*/
  }
};

int main() {
  SinglyLinkedList list;

  list.insertAtHead(1);
  list.insertAtEnd(2);
  list.insertAtEnd(3);

  list.display();
  return 0;
}