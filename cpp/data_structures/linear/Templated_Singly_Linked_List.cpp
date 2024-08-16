#include <iostream>
#include <memory>

template <typename T>
struct Node {
  T data;
  std::shared_ptr<Node> next;

  Node(T value) : data(value), next(nullptr) {}
};

template <typename T>

class SinglyLinkedList {
 private:
  std::shared_ptr<Node<T>> head;

 public:
  SinglyLinkedList() : head(nullptr) {}

  void insertAtHead(T value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(T value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    if (head == nullptr) {
      head = newNode;
    } else {
      std::shared_ptr<Node<T>> current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
  }
  void deleteNode(T value) {
    if (head == nullptr) {
      std::cout << "Linked list is Empty!!! \n";
      return;
    }

    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> prev = nullptr;
    while (current != nullptr && current->data != value) {
      prev = current;
      current = current->next;
    }
    if (current == nullptr) {
      std::cout << "Value not found!!! \n";
      return;
    }
    prev = current->next;
  }
  void display() {
    std::shared_ptr<Node<T>> current = head;
    while (current != nullptr) {
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "NULL\n";
  }
};

int main() {
  SinglyLinkedList<int> list1;
  list1.insertAtHead(1);
  list1.insertAtEnd(2);
  list1.insertAtEnd(3);
  list1.insertAtEnd(4);
  list1.display();

  SinglyLinkedList<std::string> list2;
  list2.insertAtHead("Mohamed");
  list2.insertAtEnd("Ramadan");
  list2.display();
}