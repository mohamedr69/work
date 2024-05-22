#include <iostream>

template <typename T>
class BST {
 public:
  BST();
  ~BST();

 private:
  T data;
  BST* right;
  BST* left;
};