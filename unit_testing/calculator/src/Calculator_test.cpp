#include "Calculator.hpp"

#include <gtest/gtest.h>

// ZOMBIES

using namespace ::testing;
TEST(calculator, add_method_zero_case) {
  ASSERT_EQ(0, calculator::calc_add(0, 0));
}

TEST(calculator, add_method_one_case) {
  ASSERT_EQ(2, calculator::calc_add(1, 1));
}

TEST(calculator, add_method_many_case) {
  ASSERT_EQ(10, calculator::calc_add(5, 5));
}

TEST(calculator, add_method_boundries) {
  ASSERT_EQ(1, calculator::calc_add(-1, 2));
}
//---------------------------------------------------------------------------------------//

TEST(calculator, sub_method_zero_case) {
  ASSERT_EQ(0, calculator::calc_sub(0, 0));
}

TEST(calculator, sub_method_one_case) {
  ASSERT_EQ(0, calculator::calc_sub(1, 1));
}

TEST(calculator, sub_method_many_case) {
  ASSERT_EQ(5, calculator::calc_sub(10, 5));
}

TEST(calculator, sub_method_boundries) {
  ASSERT_EQ(-3, calculator::calc_sub(-1, 2));
}

//---------------------------------------------------------------------------------------//

TEST(calculator, mul_method_zero_case) {
  ASSERT_EQ(0, calculator::calc_mul(0, 0));
}

TEST(calculator, mul_method_one_case) {
  ASSERT_EQ(1, calculator::calc_mul(1, 1));
}

TEST(calculator, mul_method_many_case) {
  ASSERT_EQ(25, calculator::calc_mul(5, 5));
}

TEST(calculator, mul_method_boundries) {
  ASSERT_EQ(-2, calculator::calc_mul(-1, 2));
}

//---------------------------------------------------------------------------------------//

TEST(calculator, div_method_zero_case) {
  ASSERT_EQ(Undefined, calculator::calc_div(0, 0));
}

TEST(calculator, div_method_one_case) {
  ASSERT_EQ(1, calculator::calc_div(1, 1));
}

TEST(calculator, div_method_many_case) {
  ASSERT_EQ(1, calculator::calc_div(5, 5));
}

TEST(calculator, div_method_boundries) {
  ASSERT_EQ(-1 / 2, calculator::calc_div(-1, 2));
}