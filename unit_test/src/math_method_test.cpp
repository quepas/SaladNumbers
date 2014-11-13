#include <catch.hpp>

#include "math_method.h"

using Salad::ModPowNaive;
using Salad::ModPow;

TEST_CASE("Functions that compute modular exponentiation") {
  SECTION("ModPowNaive function test") {
    REQUIRE(ModPowNaive(5, 3, 13) == 8);
    REQUIRE(ModPowNaive(4, 13, 497) == 445);
    // problem with variable capacity
    REQUIRE(ModPowNaive(38, 220, 221) != 1);
  }

  SECTION("Standard ModPow function test") {
    REQUIRE(ModPow(5, 3, 13) == 8);
    REQUIRE(ModPow(4, 13, 497) == 445);
    REQUIRE(ModPow(26, 220, 221) == 169);
    REQUIRE(ModPow(38, 220, 221) == 1);
  }
}
