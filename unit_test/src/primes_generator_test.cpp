#include <catch.hpp>

#include "primes.h"
#include "primes_generator.h"

using std::vector;
using Salad::MEDIUM_PRIMES;
using Salad::M_COUNT;

namespace Salad {

TEST_CASE("Testing generation of prime numbers") {
  SECTION("Sieve of Eratosthenes") {
    vector<unsigned long> primes;
    SieveOfEratosthenes(MEDIUM_PRIMES[M_COUNT - 1], primes);

    REQUIRE(primes.size() == M_COUNT);
    for (unsigned idx = 0; idx < M_COUNT; ++idx) {
      REQUIRE(primes[idx] == MEDIUM_PRIMES[idx]);
    }

    primes.clear();
    SieveOfEratosthenes(0, primes);
    REQUIRE(primes.size() == 0);
    primes.clear();
    SieveOfEratosthenes(2, primes);
    REQUIRE(primes.size() == 1);
  }
}

}
// ~~ Salad::primes_generator_test
