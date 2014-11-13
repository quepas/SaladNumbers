#include "deterministic_method.h"
#include "primes_generator.h"

#include <cmath>
#include <vector>

using std::vector;

namespace Salad {

bool IsPrime_Naive1(unsigned long int number)
{
  if (number < 2) return false;
  for (unsigned divider = 2; divider < number; ++divider)
    if (number % divider == 0) return false;
  return true;
}

bool IsPrime_Naive2(unsigned long int number)
{
  if (number < 2) return false;
  for (unsigned divider = 2; divider <= sqrt(number); ++divider)
    if (number % divider == 0) return false;
  return true;
}

bool IsPrime_Naive3(unsigned long int number)
{
  if (number < 2) return false;
  vector<unsigned long> primes;
  SieveOfEratosthenes(sqrt(number), primes);
  for (auto prime : primes) {
    if (number % prime == 0) return false;
  }
  return true;
}

}
// ~~ Salad::deterministic_method
