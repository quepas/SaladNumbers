#include "probabilistic_method.h"
#include "math_method.h"

#include <random>

using Salad::ModPow;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

namespace Salad {

bool IsPrime_Fermat(unsigned long number, unsigned test_runs)
{
  if (number < 2 || test_runs == 0) return false;
  unsigned long exponent = number - 1;
  random_device device;
  mt19937 generator(device());
  uniform_int_distribution<> distribution(1, exponent);

  for (unsigned idx = 0; idx < test_runs; ++idx) {
    if (ModPow(distribution(generator), exponent, number) != 1) return false;
  }
  return true;
}

// tells wheather or not given number is composite by checking random possible_witness
static bool IsWitness(unsigned long possible_witness, unsigned long number, unsigned exponent, unsigned long reminder)
{
  possible_witness = ModPow(possible_witness, reminder, number);
  if (possible_witness == 1 || possible_witness == number - 1) {
    return false;
  }

  for (unsigned i = 0; i < exponent; ++i) {
    possible_witness = ModPow(possible_witness, 2, number);
    if (possible_witness == number - 1) {
      return false;
    }
  }
  return true;
}

bool IsPrime_MillerRabin(unsigned long number, unsigned test_runs)
{
  if (number < 2 || test_runs == 0) return false;

  random_device device;
  mt19937 generator(device());
  uniform_int_distribution<> distribution(2, number - 2);

  unsigned long reminder = number - 1;
  unsigned exponentOfTwo = 0;
  while (reminder % 2 == 0)
  {
    reminder = reminder >> 1;
    exponentOfTwo++;
  }

  for (unsigned idx = 0; idx < test_runs; ++idx) {
    unsigned long witness = ModPow(distribution(generator), exponentOfTwo, reminder);
    if (IsWitness(distribution(generator), number, exponentOfTwo, reminder)) {
      return false;
    }
  }

  return true;
}

}
// ~~ Salad::probabilistic_method
