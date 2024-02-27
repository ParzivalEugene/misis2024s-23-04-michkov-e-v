#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuearr/queuearr.hpp"

TEST_CASE("QueueArr constructor") {
  QueueArr queue;
  CHECK(queue.IsEmpty());

  Complex c1(1, 1);
  QueueArr queue1(c1);
  CHECK_FALSE(queue1.IsEmpty());

  QueueArr queue2(queue1);
  QueueArr queue3;
  queue3 = queue2;
  queue3.Print();
  CHECK_FALSE(queue3.IsEmpty());
}

TEST_CASE("QueueArr push/pop") {
  QueueArr queue;
  Complex c1(1, 1);
  Complex c2(2, 2);
  Complex c3(3, 3);
  queue.Push(c1);
  queue.Push(c2);
  queue.Push(c3);
  CHECK(queue.Top() == c1);
  CHECK(queue.Tail() == c3);
  queue.Pop();
  CHECK(queue.Top() == c2);
  queue.Pop();
  CHECK(queue.Top() == c3);
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("QueueArr 8 elements and cross push") {
  QueueArr queue;
  for (int i = 0; i < 8; ++i) {
    queue.Push(Complex(i, i));
  }
  CHECK(queue.Top() == Complex(0, 0));
  CHECK(queue.Tail() == Complex(7, 7));
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Push(Complex(8, 8));
  queue.Push(Complex(9, 9));
  queue.Push(Complex(10, 10));
  queue.Push(Complex(11, 11));
  CHECK(queue.Top() == Complex(4, 4));
  CHECK(queue.Tail() == Complex(11, 11));
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Pop();
  queue.Pop();
  CHECK(queue.IsEmpty());
}

TEST_CASE("QueueArr 33 elements") {
  QueueArr queue;
  for (int i = 0; i < 32; ++i) {
    queue.Push(Complex(i, i));
  }
  queue.Push(Complex(32, 32));
}