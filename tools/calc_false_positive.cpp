/**
  @file tools/calc_false_positive.cpp
  @author Wolfhead
*/
#include <iostream>
#include <bloomfilter/helper/calculator.hpp>

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "usage:" << argv[0] << " [bits] [hashes] [items]" << std::endl;
    std::cerr << "eg: " << argv[0] << " 10000 8 5000" << std::endl;
    return -1;
  }

  char* endptr = NULL;
  uint64_t bits = strtoull(argv[1], &endptr, 10);
  if (endptr == argv[1] || *endptr != 0) {
    std::cerr << "parse error for 'bits' - '" << argv[1] << "'" << std::endl;
    return -1;
  }

  uint64_t hashes = strtoull(argv[2], &endptr, 10);
  if (endptr == argv[1] || *endptr != 0) {
    std::cerr << "parse error for 'hashes' - '" << argv[2] << "'" << std::endl;
    return -1;
  }
  
  uint64_t items = strtoull(argv[3], &endptr, 10);
  if (endptr == argv[3] || *endptr != 0) {
    std::cerr << "parse error for 'items' - '" << argv[3] << "'" << std::endl;
    return -1;
  }

  std::cout << blf::helper::Calculator::FalsePositiveRate(bits, hashes, items);

  return 0;
}

