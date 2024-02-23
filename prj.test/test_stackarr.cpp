#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarr/stackarr.hpp"

TEST_CASE("Constructor") {
  StackArr stack;
  CHECK(stack.isEmpty());
}

TEST_CASE("Push") {
  StackArr stack;
  Complex c(1, 2);
  stack.push(c);
  CHECK_FALSE(stack.isEmpty());
  CHECK_EQ(stack.top(), c);
}

TEST_CASE("Pop") {
  StackArr stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  CHECK(stack.isEmpty());
}

TEST_CASE("Copy constructor") {
  StackArr stack;
  Complex c(1, 2);
  stack.push(c);
  StackArr stack2(stack);
  CHECK_FALSE(stack.isEmpty());
  CHECK_FALSE(stack2.isEmpty());
  CHECK_EQ(stack.top(), c);
  CHECK_EQ(stack2.top(), c);
  stack.pop();
  CHECK(stack.isEmpty());
  CHECK_FALSE(stack2.isEmpty());
  CHECK_EQ(stack2.top(), c);
}

TEST_CASE("Assignment operator") {
  StackArr stack;
  Complex c(1, 2);
  stack.push(c);
  StackArr stack2;
  stack2 = stack;
  CHECK_FALSE(stack.isEmpty());
  CHECK_FALSE(stack2.isEmpty());
  CHECK_EQ(stack.top(), c);
  CHECK_EQ(stack2.top(), c);
  stack.pop();
  CHECK(stack.isEmpty());
  CHECK_FALSE(stack2.isEmpty());
  CHECK_EQ(stack2.top(), c);
}

TEST_CASE("Clear") {
  StackArr stack;
  Complex c(1, 2);
  stack.push(c);
  stack.clear();
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop") {
  StackArr stack;
  Complex c1(1, 2);
  Complex c2(3, 4);
  stack.push(c1);
  stack.push(c2);
  CHECK_EQ(stack.top(), c2);
  stack.pop();
  CHECK_EQ(stack.top(), c1);
  stack.pop();
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop with resizing") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.push(value);
  }
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.top(), Complex(i, i));
    stack.pop();
  }
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop with resizing and copy") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.push(value);
  }
  StackArr stack2(stack);
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.top(), Complex(i, i));
    CHECK_EQ(stack2.top(), Complex(i, i));
    stack.pop();
    stack2.pop();
  }
  CHECK(stack.isEmpty());
  CHECK(stack2.isEmpty());
}

TEST_CASE("Push and pop with resizing and assignment") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.push(value);
  }
  StackArr stack2;
  stack2 = stack;
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.top(), Complex(i, i));
    CHECK_EQ(stack2.top(), Complex(i, i));
    stack.pop();
    stack2.pop();
  }
  CHECK(stack.isEmpty());
  CHECK(stack2.isEmpty());
}

TEST_CASE("Push and pop with resizing and assignment and push") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.push(value);
  }
  StackArr stack2;
  stack2 = stack;
  for (ptrdiff_t i = 1000; i < 2000; ++i) {
    value = Complex(i, i);
    stack2.push(value);
  }
  for (ptrdiff_t i = 1999; i >= 0; --i) {
    CHECK_EQ(stack2.top(), Complex(i, i));
    stack2.pop();
  }
  CHECK(stack2.isEmpty());
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.top(), Complex(i, i));
    stack.pop();
  }
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop with resizing and copy and push") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.push(value);
  }
  StackArr stack2(stack);
  for (ptrdiff_t i = 1000; i < 2000; ++i) {
    value = Complex(i, i);
    stack2.push(value);
  }
  for (ptrdiff_t i = 1999; i >= 0; --i) {
    CHECK_EQ(stack2.top(), Complex(i, i));
    stack2.pop();
  }
  CHECK(stack2.isEmpty());
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.top(), Complex(i, i));
    stack.pop();
  }
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop with resizing and copy and push and pop") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.push(value);
  }
  StackArr stack2(stack);
  for (ptrdiff_t i = 1000; i < 2000; ++i) {
    value = Complex(i, i);
    stack2.push(value);
  }
  for (ptrdiff_t i = 1999; i >= 0; --i) {
    CHECK_EQ(stack2.top(), Complex(i, i));
    stack2.pop();
  }
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.top(), Complex(i, i));
    stack.pop();
  }
  CHECK(stack.isEmpty());
  CHECK(stack2.isEmpty());
}