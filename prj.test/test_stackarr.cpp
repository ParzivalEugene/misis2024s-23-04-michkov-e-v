#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarr/stackarr.hpp"

TEST_CASE("Constructor") {
  StackArr stack;
  CHECK(stack.IsEmpty());
}

TEST_CASE("Move constructor") {
  Complex c(1, 2);
  StackArr stack1(c);
  StackArr stack2(std::move(stack1));
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
  CHECK(stack1.IsEmpty());
}

TEST_CASE("Push") {
  StackArr stack;
  Complex c(1, 2);
  stack.Push(c);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE("Pop") {
  StackArr stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Copy constructor") {
  StackArr stack;
  Complex c(1, 2);
  stack.Push(c);
  StackArr stack2(stack);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack.Top(), c);
  CHECK_EQ(stack2.Top(), c);
  stack.Pop();
  CHECK(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
}

TEST_CASE("Assignment operator") {
  StackArr stack;
  Complex c(1, 2);
  stack.Push(c);
  StackArr stack2;
  stack2 = stack;
  CHECK_FALSE(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack.Top(), c);
  CHECK_EQ(stack2.Top(), c);
  stack.Pop();
  CHECK(stack.IsEmpty());
  CHECK_FALSE(stack2.IsEmpty());
  CHECK_EQ(stack2.Top(), c);
}

TEST_CASE("Clear") {
  StackArr stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Clear();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop") {
  StackArr stack;
  Complex c1(1, 2);
  Complex c2(3, 4);
  stack.Push(c1);
  stack.Push(c2);
  CHECK_EQ(stack.Top(), c2);
  stack.Pop();
  CHECK_EQ(stack.Top(), c1);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop with resizing") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.Push(value);
  }
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.Top(), Complex(i, i));
    stack.Pop();
  }
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop with resizing and copy") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.Push(value);
  }
  StackArr stack2(stack);
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.Top(), Complex(i, i));
    CHECK_EQ(stack2.Top(), Complex(i, i));
    stack.Pop();
    stack2.Pop();
  }
  CHECK(stack.IsEmpty());
  CHECK(stack2.IsEmpty());
}

TEST_CASE("Push and Pop with resizing and assignment") {
  StackArr stack;
  Complex value;
  for (ptrdiff_t i = 0; i < 1000; ++i) {
    value = Complex(i, i);
    stack.Push(value);
  }
  StackArr stack2;
  stack2 = stack;
  for (ptrdiff_t i = 999; i >= 0; --i) {
    CHECK_EQ(stack.Top(), Complex(i, i));
    CHECK_EQ(stack2.Top(), Complex(i, i));
    stack.Pop();
    stack2.Pop();
  }
  CHECK(stack.IsEmpty());
  CHECK(stack2.IsEmpty());
}
