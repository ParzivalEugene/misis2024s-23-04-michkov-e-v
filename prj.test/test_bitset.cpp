#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "bitset/bitset.hpp"
#include "doctest.h"

TEST_CASE("BitSet Constructor") {
  BitSet bs;
  CHECK(bs.Size() == 0);
  CHECK(bs.toString() == "");

  BitSet bs2(10);
  CHECK(bs2.Size() == 10);
  CHECK(bs2.toString() == "0000000000");
  bs2.Fill(true);
  CHECK(bs2.toString() == "1111111111");
  bs2.Fill(false);
  CHECK(bs2.toString() == "0000000000");

  BitSet bs3(bs2);
  CHECK(bs3.Size() == 10);
  CHECK(bs3.toString() == "0000000000");

  BitSet bs4(std::move(bs3));
  CHECK(bs4.Size() == 10);
  CHECK(bs4.toString() == "0000000000");
  CHECK(bs3.Size() == 0);
  CHECK(bs3.toString() == "");

  bs3 = bs2;
  CHECK(bs3.Size() == 10);
  CHECK(bs3.toString() == "0000000000");
  CHECK(bs2.Size() == 10);
  CHECK(bs2.toString() == "0000000000");

  bs3 = std::move(bs2);
  CHECK(bs3.Size() == 10);
  CHECK(bs3.toString() == "0000000000");
  CHECK(bs2.Size() == 0);
  CHECK(bs2.toString() == "");
}

TEST_CASE("BitSet Operators") {
  BitSet bs0;
  BitSet bs1(10);

  bs1.Set(0, true);
  bs1.Set(1, true);
  bs1.Set(2, true);
  bs1.Set(3, false);
  bs1.Set(4, false);
  bs1.Set(5, false);
  bs1.Set(6, true);
  bs1.Set(7, true);
  bs1.Set(8, false);
  bs1.Set(9, false);
  CHECK(bs1.toString() == "1110001100");

  BitSet bs2(~bs1);
  CHECK(bs2.toString() == "0001110011");

  BitSet bs3("1010101010");
  CHECK(bs3.toString() == "1010101010");

  BitSet bs4 = bs1 & bs3;
  CHECK(bs4.toString() == "1010001000");

  BitSet bs5 = bs1 | bs3;
  CHECK(bs5.toString() == "1110101110");

  BitSet bs6 = bs1 ^ bs3;
  CHECK(bs6.toString() == "0100100110");

  BitSet bs7 = bs1;
  bs0 = bs7 &= bs3;
  CHECK(bs0.toString() == "1010001000");

  BitSet bs8 = bs1;
  bs0 = bs8 |= bs3;
  CHECK(bs0.toString() == "1110101110");

  BitSet bs9 = bs1;
  bs0 = bs9 ^= bs3;
  CHECK(bs0.toString() == "0100100110");

  BitSet bs10("111");

  CHECK(bs1 == bs1);
  CHECK(bs1 != bs2);
  CHECK_THROWS(bs0 = bs1 &= bs10);
  CHECK_THROWS(bs0 = bs1 |= bs10);
  CHECK_THROWS(bs0 = bs1 ^= bs10);
  CHECK_THROWS(bs0 = bs1 ^ bs10);
  CHECK_THROWS(bs0 = bs1 | bs10);
  CHECK_THROWS(bs0 = bs1 & bs10);
}

TEST_CASE("BitSet Resize") {
  BitSet bs(10);
  bs.Resize(20);
  CHECK(bs.Size() == 20);
  CHECK(bs.toString() == "00000000000000000000");

  BitSet bs2("11111");
  bs2.Resize(5);
  CHECK(bs2.Size() == 5);
  CHECK(bs2.toString() == "11111");
  bs2.Resize(10);
  CHECK(bs2.Size() == 10);
  CHECK(bs2.toString() == "1111100000");
  bs2.Resize(3);
  CHECK(bs2.Size() == 3);
  CHECK(bs2.toString() == "111");
}

TEST_CASE("BitSet Get/Set") {
  BitSet bs(10);
  bool b0;

  bs.Set(0, true);
  bs.Set(1, true);
  bs.Set(2, true);
  bs.Set(3, false);
  bs.Set(4, false);
  bs.Set(5, false);
  bs.Set(6, true);
  bs.Set(7, true);
  bs.Set(8, false);
  bs.Set(9, false);
  CHECK(bs.toString() == "1110001100");

  CHECK(bs.Get(0) == true);
  CHECK(bs[0] == 1);
  CHECK(bs.Get(1) == true);
  CHECK(bs[1] == 1);
  CHECK(bs.Get(2) == true);
  CHECK(bs[2] == 1);
  CHECK(bs.Get(3) == false);
  CHECK(bs[3] == 0);
  CHECK(bs.Get(4) == false);
  CHECK(bs[4] == 0);
  CHECK(bs.Get(5) == false);
  CHECK(bs[5] == 0);
  CHECK(bs.Get(6) == true);
  CHECK(bs[6] == 1);
  CHECK(bs.Get(7) == true);
  CHECK(bs[7] == 1);
  CHECK(bs.Get(8) == false);
  CHECK(bs[8] == 0);
  CHECK(bs.Get(9) == false);
  CHECK(bs[9] == 0);

  CHECK_THROWS(bs.Set(10, true));
  CHECK_THROWS(b0 = bs.Get(10));
  CHECK_THROWS(b0 = bs[10]);

  CHECK_THROWS(bs.Set(-1, true));
  CHECK_THROWS(b0 = bs.Get(-2));
  CHECK_THROWS(b0 = bs[-25]);
}