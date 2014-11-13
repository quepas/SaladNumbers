#include "math_method.h"

#include <cmath>

namespace Salad {

unsigned long ModPowNaive(unsigned long base, unsigned long exponent, unsigned long modulus)
{
  return static_cast<unsigned long>(pow(base, exponent)) % modulus;
}

unsigned long ModPow(unsigned long base, unsigned long exponent, unsigned long modulus)
{
  unsigned long result = 1;
  for (unsigned idx = 0; idx < exponent; ++idx) {
    result = (result * base) % modulus;
  }
  return result;
}

}
// ~~ Salad::math_method
