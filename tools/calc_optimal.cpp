/**
  @file tools/calc_optimal.cpp
  @author Wolfhead
*/
#include <iostream>
#include <bloomfilter/helper/calculator.hpp>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "usage:" << argv[0] << " [items] [false-positive rate]" << std::endl;
    std::cerr << "eg: " << argv[0] << " 10000 0.00001" << std::endl;
    return -1;
  }

  char* endptr = NULL;
  uint64_t items = strtoull(argv[1], &endptr, 10);
  if (endptr == argv[1] || *endptr != 0) {
    std::cerr << "parse error for 'items' - '" << argv[1] << "'" << std::endl;
    return -1;
  }

  double rate = strtod(argv[2], &endptr);
  if (endptr == argv[2] || *endptr != 0) {
    std::cerr << "parse error for 'fale-positive rate' - '" << argv[2] << "'" << std::endl;
    return -1;
  }

  uint64_t bits = 0;
  uint64_t hashes = 0;

  blf::helper::Calculator::Optimal(items, rate, &bits, &hashes);
  std::cout << "bits: " << bits << std::endl;
  std::cout << "bytes: " << (bits + 7) / 8 << std::endl;
  std::cout << "Kb: " << (double(bits + 7) / 8 / 1024) << std::endl;
  std::cout << "Mb: " << (double(bits + 7) / 8 / 1024 / 1024) << std::endl;
  std::cout << "Gb: " << (double(bits + 7) / 8 / 1024 / 1024 / 1024) << std::endl;
  std::cout << "Hash: " << hashes << std::endl;

  return 0;
}

