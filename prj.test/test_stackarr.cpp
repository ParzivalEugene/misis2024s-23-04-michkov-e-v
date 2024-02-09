#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarr/stackarr.hpp"

TEST_CASE("Constructor") {
  StackArr s1;
  CHECK(s1.isEmpty());
}