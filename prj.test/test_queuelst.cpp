#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuelst/queuelst.hpp"

TEST_CASE("QueueLst - default ctor") {
  QueueLst queue;
  CHECK(queue.IsEmpty());
}

TEST_CASE("QueueLst - copy ctor") {
  QueueLst queue;
  queue.Push(Complex{1, 1});
  queue.Push(Complex{2, 2});
  queue.Push(Complex{3, 3});
  QueueLst copy(queue);
  CHECK(queue.Top() == copy.Top());
  queue.Pop();
  CHECK(queue.Top() != copy.Top());
}

TEST_CASE("QueueLst - copy assignment") {
  QueueLst queue;
  queue.Push(Complex{1, 1});
  queue.Push(Complex{2, 2});
  queue.Push(Complex{3, 3});
  QueueLst copy;
  copy.Push(Complex{4, 4});
  copy.Push(Complex{5, 5});
  copy.Push(Complex{6, 6});
  copy = queue;
  CHECK(queue.Top() == copy.Top());
  queue.Pop();
  CHECK(queue.Top() != copy.Top());
}

TEST_CASE("QueueLst - IsEmpty") {
  QueueLst queue;
  CHECK(queue.IsEmpty());
  queue.Push(Complex{1, 1});
  CHECK(!queue.IsEmpty());
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("QueueLst - Pop") {
  QueueLst queue;
  queue.Push(Complex{1, 1});
  queue.Push(Complex{2, 2});
  queue.Push(Complex{3, 3});
  queue.Pop();
  CHECK(queue.Top() == Complex{2, 2});
  queue.Pop();
  CHECK(queue.Top() == Complex{3, 3});
  queue.Pop();
  CHECK(queue.IsEmpty());
}