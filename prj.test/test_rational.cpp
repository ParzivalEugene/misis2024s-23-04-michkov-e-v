#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "rational/rational.hpp"

TEST_CASE("Constructor with move semantics") {
  Rational r1(2, 3);
  Rational r2(std::move(r1));
  CHECK(r2 == Rational(2, 3));

  Rational r3(3, 4);
  r2 = std::move(r3);
  CHECK(r2 == Rational(3, 4));

  Rational&& r4 = Rational(4, 5);
  CHECK(r4 == Rational(4, 5));
}

TEST_CASE("Testing Rational class") {
  Rational r1(2, 3);
  Rational r2(3, 4);

  SUBCASE("Testing equality operator") {
    CHECK_FALSE(r1 == r2);
    CHECK(r1 == Rational(2, 3));
  }

  SUBCASE("Testing inequality operator") {
    CHECK(r1 != r2);
    CHECK_FALSE(r1 != Rational(2, 3));
  }

  SUBCASE("Testing less than operator") {
    CHECK(r1 < r2);
    CHECK_FALSE(r2 < r1);
  }

  SUBCASE("Testing less than or equal to operator") {
    CHECK(r1 <= r2);
    CHECK_FALSE(r2 <= r1);
    CHECK(Rational(2, 3) <= r1);
  }

  SUBCASE("Testing greater than operator") {
    CHECK(r2 > r1);
    CHECK_FALSE(r1 > r2);
  }

  SUBCASE("Testing greater than or equal to operator") {
    CHECK(r2 >= r1);
    CHECK_FALSE(r1 >= r2);
    CHECK(r1 >= Rational(2, 3));
  }

  SUBCASE("Testing addition operator") {
    Rational r3 = r1 + r2;
    CHECK(r3 == Rational(17, 12));
  }

  SUBCASE("Testing subtraction operator") {
    Rational r3 = r1 - r2;
    CHECK(r3 == Rational(-1, 12));
  }

  SUBCASE("Testing multiplication operator") {
    Rational r3 = r1 * r2;
    CHECK(r3 == Rational(1, 2));
  }

  SUBCASE("Testing division operator") {
    Rational r3 = r1 / r2;
    CHECK(r3 == Rational(8, 9));
  }

  SUBCASE("Testing addition assignment operator") {
    r1 += r2;
    CHECK(r1 == Rational(17, 12));
  }

  SUBCASE("Testing subtraction assignment operator") {
    r1 -= r2;
    CHECK(r1 == Rational(-1, 12));
  }

  SUBCASE("Testing multiplication assignment operator") {
    r1 *= r2;
    CHECK(r1 == Rational(1, 2));
  }

  SUBCASE("Testing division assignment operator") {
    r1 /= r2;
    CHECK(r1 == Rational(8, 9));
  }

  SUBCASE("Testing operator>>") {
    std::istringstream istrm("4/6");
    istrm >> r1;
    CHECK(r1 == Rational(2, 3));
  }

  SUBCASE("Testing operator<<") {
    std::ostringstream ostrm;
    ostrm << r1;
    CHECK(ostrm.str() == "2/3");
  }
}

TEST_CASE("Testing Rational class with int64_t") {
  Rational r1(2, 3);
  int64_t i1 = 3;

  SUBCASE("Testing addition operator") {
    Rational r2 = r1 + i1;
    CHECK(r2 == Rational(11, 3));
  }

  SUBCASE("Testing subtraction operator") {
    Rational r2 = r1 - i1;
    CHECK(r2 == Rational(-7, 3));
  }

  SUBCASE("Testing division operator") {
    Rational r2 = r1 / i1;
    CHECK(r2 == Rational(2, 9));
  }

  SUBCASE("Testing addition assignment operator") {
    r1 += i1;
    CHECK(r1 == Rational(11, 3));
  }

  SUBCASE("Testing subtraction assignment operator") {
    r1 -= i1;
    CHECK(r1 == Rational(-7, 3));
  }

  SUBCASE("Testing multiplication assignment operator") {
    r1 *= i1;
    CHECK(r1 == Rational(2, 1));
  }

  SUBCASE("Testing division assignment operator") {
    r1 /= i1;
    CHECK(r1 == Rational(2, 9));
  }

  SUBCASE("Testing addition operator with int64_t on the left") {
    Rational r2 = i1 + r1;
    CHECK(r2 == Rational(11, 3));
  }

  SUBCASE("Testing subtraction operator with int64_t on the left") {
    Rational r2 = i1 - r1;
    CHECK(r2 == Rational(7, 3));
  }

  SUBCASE("Testing multiplication operator with int64_t on the left") {
    Rational r2 = i1 * r1;
    CHECK(r2 == Rational(2, 1));
  }

  SUBCASE("Testing division operator with int64_t on the left") {
    Rational r2 = i1 / r1;
    CHECK(r2 == Rational(9, 2));
  }
}