#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dynarr/dynarr.hpp"

TEST_CASE("Testing DynArr class") {
  DynArr arr(5);

  SUBCASE("Testing Size method") { CHECK(arr.Size() == 5); }

  SUBCASE("Testing Resize method") {
    arr.Resize(10);
    CHECK(arr.Size() == 10);
  }

  SUBCASE("Testing operator[]") {
    for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
      arr[i] = i;
    }
    for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
      CHECK(arr[i] == doctest::Approx(i));
    }
  }

  SUBCASE("Testing out of range") {
    CHECK_THROWS_AS(arr[arr.Size()], std::out_of_range);
    CHECK_THROWS_AS(arr[-1], std::out_of_range);
    CHECK_THROWS_AS(arr[arr.Size() + 1], std::out_of_range);
  }

  SUBCASE("Testing copy constructor") {
    DynArr arr2(arr);
    CHECK(arr2.Size() == arr.Size());
    for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
      CHECK(arr2[i] == doctest::Approx(arr[i]));
    }
  }

  SUBCASE("Testing copy assignment") {
    DynArr arr2(10);
    arr2 = arr;
    CHECK(arr2.Size() == arr.Size());
    for (ptrdiff_t i = 0; i < arr.Size(); ++i) {
      CHECK(arr2[i] == doctest::Approx(arr[i]));
    }
  }
}