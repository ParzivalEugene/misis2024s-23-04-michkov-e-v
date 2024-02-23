#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stacklst/stacklst.hpp"

TEST_CASE("Constructor") {
  StackLst stack;
  CHECK(stack.isEmpty());
}

TEST_CASE("Push") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  CHECK_FALSE(stack.isEmpty());
  CHECK_EQ(stack.top(), c);
}

TEST_CASE("Pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  CHECK(stack.isEmpty());
}

TEST_CASE("Copy constructor") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  StackLst stack2(stack);
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
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  StackLst stack2;
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
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.clear();
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and top") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  CHECK_EQ(stack.top(), c);
}

TEST_CASE("Push and pop and top") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  CHECK_THROWS(stack.top());
}

TEST_CASE("Push and pop and top and push") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  stack.push(c);
  CHECK_EQ(stack.top(), c);
}

TEST_CASE("Push and pop and top and push and pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  stack.push(c);
  stack.pop();
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop and top and push and pop and push") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  stack.push(c);
  stack.pop();
  stack.push(c);
  CHECK_EQ(stack.top(), c);
}

TEST_CASE("Push and pop and top and push and pop and push and pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  stack.push(c);
  stack.pop();
  stack.push(c);
  stack.pop();
  CHECK(stack.isEmpty());
}

TEST_CASE("Push and pop and top and push and pop and push and pop and push") {
  StackLst stack;
  Complex c(1, 2);
  stack.push(c);
  stack.pop();
  stack.push(c);
  stack.pop();
  stack.push(c);
  stack.pop();
  stack.push(c);
  CHECK_EQ(stack.top(), c);
}