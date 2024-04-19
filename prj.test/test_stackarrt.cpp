#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "stackarrt/stackarrt.hpp"
#include "doctest.h"


TEST_CASE_TEMPLATE("constructor", T, int, double, char) {
  StackArrT<T> stack;
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("push", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  CHECK(stack.Top() == 1);
  stack.Push(2);
  CHECK(stack.Top() == 2);
  stack.Push(3);
  CHECK(stack.Top() == 3);
}

TEST_CASE_TEMPLATE("pop", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Pop();
  CHECK(stack.Top() == 2);
  stack.Pop();
  CHECK(stack.Top() == 1);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("top", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  CHECK(stack.Top() == 1);
  stack.Push(2);
  CHECK(stack.Top() == 2);
  stack.Push(3);
  CHECK(stack.Top() == 3);
}

TEST_CASE_TEMPLATE("copy constructor", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  StackArrT<T> stack_copy(stack);
  CHECK(stack_copy.Top() == 3);
  stack_copy.Pop();
  CHECK(stack_copy.Top() == 2);
  stack_copy.Pop();
  CHECK(stack_copy.Top() == 1);
  stack_copy.Pop();
  CHECK(stack_copy.IsEmpty());
}

TEST_CASE_TEMPLATE("move constructor", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  StackArrT<T> stack_move(std::move(stack));
  CHECK(stack_move.Top() == 3);
  stack_move.Pop();
  CHECK(stack_move.Top() == 2);
  stack_move.Pop();
  CHECK(stack_move.Top() == 1);
  stack_move.Pop();
  CHECK(stack_move.IsEmpty());
}

TEST_CASE_TEMPLATE("lifo", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  CHECK(stack.Top() == 3);
  stack.Pop();
  CHECK(stack.Top() == 2);
  stack.Pop();
  CHECK(stack.Top() == 1);
  stack.Pop();
  CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("assignment operator", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  StackArrT<T> stack_copy;
  stack_copy = stack;
  CHECK(stack_copy.Top() == 3);
  stack_copy.Pop();
  CHECK(stack_copy.Top() == 2);
  stack_copy.Pop();
  CHECK(stack_copy.Top() == 1);
  stack_copy.Pop();
  CHECK(stack_copy.IsEmpty());
}

TEST_CASE_TEMPLATE("move assignment operator", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  StackArrT<T> stack_move;
  stack_move = std::move(stack);
  CHECK(stack_move.Top() == 3);
  stack_move.Pop();
  CHECK(stack_move.Top() == 2);
  stack_move.Pop();
  CHECK(stack_move.Top() == 1);
  stack_move.Pop();
  CHECK(stack_move.IsEmpty());
}

TEST_CASE_TEMPLATE("copy constructor self assignment", T, int, double, char) {
  StackArrT<T> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack = stack;
  CHECK(stack.Top() == 3);
  stack.Pop();
  CHECK(stack.Top() == 2);
  stack.Pop();
  CHECK(stack.Top() == 1);
  stack.Pop();
  CHECK(stack.IsEmpty());
}