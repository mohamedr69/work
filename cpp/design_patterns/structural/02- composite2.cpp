/*
    1- create PageObject is a component for a composite
    includes addItem,removeItem and deleteItem

    2- Inherit page from pageObject
    3- Create Composite class copy (inheritance and compositon )
        contains list of PageObjects also inherits PageOfObject
    item is a string
*/

#include <algorithm>
#include <iostream>
#include <vector>
class pageObject {
 public:
  virtual void addItem(const std::string& item);
  virtual void removeItem(const std::string& item);
  virtual void deleteItem();
};

class page : public pageObject {
 public:
  void addItem(const std::string& item) override { items.push_back(item); }
  void removeItem(const std::string& item) override {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
  }
  void deleteItem() override { items.clear(); }

  std::vector<std::string> getItem() { return items; }

 private:
  std::vector<std::string> items;
};
class copy : public pageObject {
 public:
  void addItem(const std::string& item) override {
    for (auto& pg : pgs) {
      pg->addItem(item);
    }
  }
  void removeItem(const std::string& item) override {
    for (auto& pg : pgs) {
      pg->removeItem(item);
    }
  }
  void deleteItem() override {
    for (auto& pg : pgs) {
      pg->deleteItem();
    }
  }
  void addPage(pageObject* page) { pgs.push_back(page); }

 private:
  std::vector<pageObject*> pgs;
};

int main() {
  page p1;
  page p2;
  copy c;

  c.addPage(&p1);
  c.addPage(&p1);

  c.addItem("Item 1");
  c.addItem("Item 2");

  c.removeItem("Item 1");
}