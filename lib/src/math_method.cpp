#include "math_method.h"

#include <cmath>

namespace Salad {

unsigned long ModPowNaive(unsigned base, unsigned exponent, unsigned modulus)
{
  return static_cast<unsigned long>(pow(base, exponent)) % modulus;
}

unsigned long ModPow(unsigned base, unsigned exponent, unsigned modulus)
{
  unsigned long result = 1;
  for (unsigned idx = 0; idx < exponent; ++idx) {
    result = (result * base) % modulus;
  }
  return result;
}

}
// ~~ Salad::math_method
