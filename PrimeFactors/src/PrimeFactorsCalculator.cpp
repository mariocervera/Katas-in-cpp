#include "PrimeFactorsCalculator.hpp"

vector<unsigned> PrimeFactorsCalculator::getPrimeFactors(unsigned num) {
  vector<unsigned> factors;

  for (int divisor = 2; num > 1; ++divisor)
    for (; num % divisor == 0; num /= divisor)
      factors.emplace_back(divisor);

  return factors;
}