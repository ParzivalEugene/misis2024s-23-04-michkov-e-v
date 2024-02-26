#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stacklst/stacklst.hpp"

TEST_CASE("Constructor") {
  StackLst stack;
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  CHECK_FALSE(stack.IsEmpty());
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE("Pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Copy constructor") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  StackLst stack2(stack);
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
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  StackLst stack2;
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
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Clear();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Top") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE("Push and Pop and Top") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  CHECK_THROWS(stack.Top());
}

TEST_CASE("Push and Pop and Top and Push") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE("Push and Pop and Top and Push and Pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop and Top and Push and Pop and Push") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  CHECK_EQ(stack.Top(), c);
}

TEST_CASE("Push and Pop and Top and Push and Pop and Push and Pop") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop and Top and Push and Pop and Push and Pop and Push") {
  StackLst stack;
  Complex c(1, 2);
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  stack.Pop();
  stack.Push(c);
  CHECK_EQ(stack.Top(), c);
}