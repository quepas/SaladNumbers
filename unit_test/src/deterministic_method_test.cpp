#include <catch.hpp>
#include <climits>

#include "primes.h"
#include "deterministic_method.h"

using Salad::M_COUNT;
using Salad::MEDIUM_PRIMES;
using Salad::IsPrime_Naive1;
using Salad::IsPrime_Naive2;
using Salad::IsPrime_Naive3;

TEST_CASE("Basic primality tests with naive methods") {
  SECTION("Naive method - first version") {
    REQUIRE(IsPrime_Naive1(0) == false);
    REQUIRE(IsPrime_Naive1(1) == false);
    REQUIRE(IsPrime_Naive1(1111111111) == false);
    REQUIRE(IsPrime_Naive1(2147483647));
    for (unsigned idx = 0; idx < M_COUNT; ++idx) {
      REQUIRE(IsPrime_Naive1(MEDIUM_PRIMES[idx]));
    }
  }

  SECTION("Naive method - second version") {
    REQUIRE(IsPrime_Naive2(0) == false);
    REQUIRE(IsPrime_Naive2(1) == false);
    REQUIRE(IsPrime_Naive2(1111111111) == false);
    REQUIRE(IsPrime_Naive2(2147483647));
    for (unsigned idx = 0; idx < M_COUNT; ++idx) {
      REQUIRE(IsPrime_Naive2(MEDIUM_PRIMES[idx]));
    }
  }

  SECTION("Naive method - third version") {
    REQUIRE(IsPrime_Naive3(0) == false);
    REQUIRE(IsPrime_Naive3(1) == false);
    REQUIRE(IsPrime_Naive3(1111111111) == false);
    REQUIRE(IsPrime_Naive3(2147483647));
    for (unsigned idx = 0; idx < M_COUNT; ++idx) {
      REQUIRE(IsPrime_Naive3(MEDIUM_PRIMES[idx]));
    }
  }
}
