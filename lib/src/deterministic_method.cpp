#include "deterministic_method.h"

#include <cmath>

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

}
// ~~ Salad::deterministic_method
