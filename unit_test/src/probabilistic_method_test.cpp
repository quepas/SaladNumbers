#include <catch.hpp>

#include "probabilistic_method.h"

using Salad::IsPrime_Fermat;

TEST_CASE("Primality tests with probabilistic methods") {
  SECTION("Fermat primality test") {
    REQUIRE(IsPrime_Fermat(1, 10) == false);
    REQUIRE(IsPrime_Fermat(1341341, 0) == false);
  }
}