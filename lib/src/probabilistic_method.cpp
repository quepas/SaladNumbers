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

}
// ~~ Salad::probabilistic_method
