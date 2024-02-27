#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuearr/queuearr.hpp"

TEST_CASE("QueueArr") {
  QueueArr q;
  CHECK(q.IsEmpty());
  q.Push(Complex(1, 2));
  CHECK(!q.IsEmpty());

  CHECK_EQ(q.Top(), Complex(1, 2));
  CHECK_EQ(q.Tail(), Complex(1, 2));

  q.Push(Complex(3, 4));
  CHECK_EQ(q.Top(), Complex(1, 2));
  CHECK_EQ(q.Tail(), Complex(3, 4));

  q.Pop();
  CHECK_EQ(q.Top(), Complex(3, 4));
  CHECK_EQ(q.Tail(), Complex(3, 4));

  q.Pop();
  q.Print();
  CHECK(q.IsEmpty());

  q.Push(Complex(5, 6));
  CHECK_EQ(q.Top(), Complex(5, 6));

  q.Clear();
  CHECK(q.IsEmpty());

  q.Push(Complex(7, 8));
  CHECK_EQ(q.Top(), Complex(7, 8));
  CHECK_EQ(q.Tail(), Complex(7, 8));
  q.Push(Complex(9, 10));
  CHECK_EQ(q.Top(), Complex(7, 8));
  CHECK_EQ(q.Tail(), Complex(9, 10));
  q.Pop();
  CHECK_EQ(q.Top(), Complex(9, 10));
  CHECK_EQ(q.Tail(), Complex(9, 10));

  q.Pop();
  CHECK(q.IsEmpty());
}