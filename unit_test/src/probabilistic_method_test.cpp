#include <catch.hpp>

#include "probabilistic_method.h"

using Salad::IsPrime_Fermat;
using Salad::IsPrime_MillerRabin;

TEST_CASE("Primality tests with probabilistic methods") {
  SECTION("Fermat primality test") {
    REQUIRE(IsPrime_Fermat(1, 10) == false);
    REQUIRE(IsPrime_Fermat(1341341, 0) == false);
  }

	SECTION("Miller-Rabin primality test") {
		REQUIRE(IsPrime_MillerRabin(1, 10) == false);
		REQUIRE(IsPrime_MillerRabin(5, 10) == true);
		REQUIRE(IsPrime_MillerRabin(12, 10) == false);
		REQUIRE(IsPrime_MillerRabin(1341341, 0) == false);
  }
}