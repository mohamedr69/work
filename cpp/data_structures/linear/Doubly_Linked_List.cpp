#include <iostream>
#include <memory>

template <typename T>
struct Node {
  /* data */
  T data;
  std::shared_ptr<Node> next;
  std::shared_ptr<Node> prev;

  Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>

class DoublyLinkedList {
 private:
  /* data */
  std::shared_ptr<Node<T>> head;

 public:
  DoublyLinkedList() : head(nullptr) {}

  void insertAtHead(T value) {
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    if (head != nullptr) {
      head->prev = newNode;
    }
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
      newNode->next = nullptr;
      newNode->prev = current;
    }
  }

  void deleteNode(T value) {
    if (head == nullptr) {
      std::cout << "List is Empty \n";
      return;
    }

    std::shared_ptr<Node<T>> current = head;

    while (current != nullptr && current->data != value) {
      current = current->next;
    }
    if (current == nullptr) {
      std::cout << "Value not found!!! \n";
      return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }

  void display() {
    std::shared_ptr<Node<T>> current = head;
    while (current != nullptr) {
      std::cout << current->data << " -> ";
      current = current->next;
    }
    std::cout << "NULL \n";
  }
};

int main() {
  DoublyLinkedList<int> list;

  list.insertAtEnd(10);
  list.insertAtEnd(20);
  list.insertAtEnd(30);
  list.insertAtHead(5);

  std::cout << "Doubly Linked List in forward order: " << std::endl;
  list.display();

  list.deleteNode(20);
  std::cout << "Doubly Linked List after deleting 20: " << std::endl;
  list.display();

  return 0;
}
