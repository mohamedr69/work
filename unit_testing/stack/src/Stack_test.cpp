#include "Stack.hpp"

#include <gtest/gtest.h>
using namespace ::testing;
TEST(stack, push_method) {
  stack s(2);
  ASSERT_EQ(s.push(2), SUCCESSFUL);
}
TEST(stack, pop_method) {
  stack s(2);
  s.push(1);
  int val;
  ASSERT_EQ(s.pop(val), SUCCESSFUL);
}
TEST(stack, empty_method) {
  stack s(2);

  ASSERT_EQ(s.isEmpty(), SUCCESSFUL);
}

TEST(stack, full_method) {
  stack s(2);
  ASSERT_EQ(s.isFull(), UNSUCCESSFUL);
}

TEST(stack, multiple_push) {
  stack s(5);
  for (int i = 0; i < 5; i++) {
    ASSERT_EQ(s.push(i), SUCCESSFUL);
  }
}