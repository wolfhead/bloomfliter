#ifndef _BLOOMFILTER_HASHER_MURMUR_HASHER_HPP_
#define _BLOOMFILTER_HASHER_MURMUR_HASHER_HPP_
/**
  @file murmur_hasher.hpp
  @author Wolfhead
*/

#include "details/MurmurHash3.h"

namespace blf {

class MurmurHasher {
 public:
  static int64_t Hash(const void* key, int len, unsigned int index) {
    int64_t result[2];
    MurmurHash3_x64_128(key, len, index, result);
    return result[0];
  }
};

} //namespace blf

#endif // _BLOOMFILTER_HASHER_MURMUR_HASHER_HPP_

