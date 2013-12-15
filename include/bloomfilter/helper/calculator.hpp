#ifndef _BLOOMFILTER_HELPER_CALCULATOR_HPP_
#define _BLOOMFILTER_HELPER_CALCULATOR_HPP_
/**
  @file calculator.hpp
  @author Wolfhead
*/
#include <stdint.h>
#include <math.h>

namespace blf { namespace helper {

class Calculator {
 public:

  /**
    * Get the optiomal number of bits and hash functions 
    * for the given element and false-positive rate
    * @param n number of items in the filter
    * @param p false-positive rate
    * @param m number of bits in the filter
    * @param k number of hash functions
    */
  static void Optimal(uint64_t n, double p, uint64_t* m, uint64_t* k) {
    *m = ceil((n * log(p)) / log(1.0 / (pow(2.0, log(2.0)))));
    *k = round(log(2.0) * *m / n);
  }

  /**
    * Get the false-positive rate
    * @param m number of bits
    * @param k number of hash functions
    * @param n number if items
    * @return false-positive rate
    */
  static double FalsePositiveRate(uint64_t m, uint64_t k, uint64_t n) {
    return pow(1.0 - pow(1.0 - (1.0 / m), k * n), k);
  }

  /**
    * Get the false-positive rate by approximation
    * @param m number of bits
    * @param k number of hash functions
    * @param n number if items
    * @return false-positive rate
    */
  static double FalsePositiveRateApprox(uint64_t m, uint64_t k, uint64_t n) {
    return pow(1.0 - exp(-1.0 * (k * n) / m), k);
  }
};

} //namespace helper
} //namespace blf

#endif // _BLOOMFILTER_HELPER_CALCULATOR_HPP_

