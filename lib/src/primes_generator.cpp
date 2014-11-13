#include "primes_generator.h"

using std::vector;

namespace Salad {

void SieveOfEratosthenes(const unsigned long limit_inclusive, vector<unsigned long>& primes_out)
{
  unsigned long max_idx = limit_inclusive + 1;
  bool* not_a_prime = new bool[max_idx]();

  for (unsigned idx = 2; idx * idx < max_idx; ++idx) {
    if (not_a_prime[idx])
      continue;
    for (unsigned jdx = 2 * idx; jdx < max_idx; jdx += idx) {
      not_a_prime[jdx] = true;
    }
  }
  for (unsigned idx = 2; idx < max_idx; ++idx) {
    if (!not_a_prime[idx])
      primes_out.push_back(idx);
  }
}

}
// ~~ Salad::primes_generator
